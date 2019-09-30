#include <stdint.h>
#include <stdio.h>
#include <queue>
#include <vector>
#include <iostream>
#include <string.h>
#include <json/json.h>
#include <arpa/inet.h>
using namespace std;

const uint8_t MY_PROTO_MAGIC = 88;
const uint32_t MY_PROTO_MAX_SIZE = 10 * 1024 * 1024; //10M
const uint32_t MY_PROTO_HEAD_SIZE = 8;

typedef enum MyProtoParserStatus
{
	ON_PARSER_INIT = 0,
	ON_PARSER_HAED = 1,
	ON_PARSER_BODY = 2,
}MyProtoParserStatus;

/*
	Э��ͷ
 */
struct MyProtoHead
{
	uint8_t version;    //Э��汾��
	uint8_t magic;      //Э��ħ��
	uint16_t server;    //Э�鸴�õķ���ţ���ʶЭ��֮�ϵĲ�ͬ����
	uint32_t len;       //Э�鳤�ȣ�Э��ͷ����+�䳤jsonЭ���峤�ȣ�
};

/*
	Э����Ϣ��
 */
struct MyProtoMsg
{
	MyProtoHead head;   //Э��ͷ
	Json::Value body;   //Э����
};

void myProtoMsgPrint(MyProtoMsg & msg)
{
	string jsonStr = "";
	Json::FastWriter fWriter;
	jsonStr = fWriter.write(msg.body);

	printf("Head[version=%d,magic=%d,server=%d,len=%d]\n"
		"Body:%s", msg.head.version, msg.head.magic,
		msg.head.server, msg.head.len, jsonStr.c_str());
}
/*
	MyProto�����
 */
class MyProtoEnCode
{
public:
	//Э����Ϣ��������
	uint8_t * encode(MyProtoMsg * pMsg, uint32_t & len);
private:
	//Э��ͷ�������
	void headEncode(uint8_t * pData, MyProtoMsg * pMsg);
};

void MyProtoEnCode::headEncode(uint8_t * pData, MyProtoMsg * pMsg)
{
	//����Э��ͷ�汾��Ϊ1
	*pData = 1;
	++pData;

	//����Э��ͷħ��
	*pData = MY_PROTO_MAGIC;
	++pData;

	//����Э�����ţ���head.server�����ֽ���ת��Ϊ�����ֽ���
	*(uint16_t *)pData = htons(pMsg->head.server);
	pData += 2;

	//����Э���ܳ��ȣ���head.len�����ֽ���ת��Ϊ�����ֽ���
	*(uint32_t *)pData = htonl(pMsg->head.len);
}

uint8_t * MyProtoEnCode::encode(MyProtoMsg * pMsg, uint32_t & len)
{
	uint8_t * pData = NULL;
	Json::FastWriter fWriter;

	//Э��json�����л�
	string bodyStr = fWriter.write(pMsg->body);
	//����Э����Ϣ���л�����ܳ���
	len = MY_PROTO_HEAD_SIZE + (uint32_t)bodyStr.size();
	pMsg->head.len = len;
	//����Э����Ϣ���л���Ҫ�Ŀռ�
	pData = new uint8_t[len];
	//���Э��ͷ
	headEncode(pData, pMsg);
	//���Э����
	memcpy(pData + MY_PROTO_HEAD_SIZE, bodyStr.data(), bodyStr.size());

	return pData;
}

/*
	MyProto�����
 */
class MyProtoDeCode
{
public:
	void init();
	void clear();
	bool parser(void * data, size_t len);
	bool empty();
	MyProtoMsg * front();
	void pop();
private:
	bool parserHead(uint8_t ** curData, uint32_t & curLen,
		uint32_t & parserLen, bool & parserBreak);
	bool parserBody(uint8_t ** curData, uint32_t & curLen,
		uint32_t & parserLen, bool & parserBreak);

private:
	MyProtoMsg mCurMsg;                     //��ǰ�����е�Э����Ϣ��
	queue<MyProtoMsg *> mMsgQ;              //�����õ�Э����Ϣ����
	vector<uint8_t> mCurReserved;           //δ�����������ֽ���
	MyProtoParserStatus mCurParserStatus;   //��ǰ����״̬
};

void MyProtoDeCode::init()
{
	mCurParserStatus = ON_PARSER_INIT;
}

void MyProtoDeCode::clear()
{
	MyProtoMsg * pMsg = NULL;

	while (!mMsgQ.empty())
	{
		pMsg = mMsgQ.front();
		delete pMsg;
		mMsgQ.pop();
	}
}

bool MyProtoDeCode::parserHead(uint8_t ** curData, uint32_t & curLen,
	uint32_t & parserLen, bool & parserBreak)
{
	parserBreak = false;
	if (curLen < MY_PROTO_HEAD_SIZE)
	{
		parserBreak = true; //��ֹ����
		return true;
	}

	uint8_t * pData = *curData;
	//�����汾��
	mCurMsg.head.version = *pData;
	pData++;
	//����ħ��
	mCurMsg.head.magic = *pData;
	pData++;
	//ħ����һ�£��򷵻ؽ���ʧ��
	if (MY_PROTO_MAGIC != mCurMsg.head.magic)
	{
		return false;
	}
	//���������
	mCurMsg.head.server = ntohs(*(uint16_t*)pData);
	pData += 2;
	//����Э����Ϣ��ĳ���
	mCurMsg.head.len = ntohl(*(uint32_t*)pData);
	//�쳣������򷵻ؽ���ʧ��
	if (mCurMsg.head.len > MY_PROTO_MAX_SIZE)
	{
		return false;
	}

	//����ָ����ǰ�ƶ�MY_PROTO_HEAD_SIZE�ֽ�
	(*curData) += MY_PROTO_HEAD_SIZE;
	curLen -= MY_PROTO_HEAD_SIZE;
	parserLen += MY_PROTO_HEAD_SIZE;
	mCurParserStatus = ON_PARSER_HAED;

	return true;
}

bool MyProtoDeCode::parserBody(uint8_t ** curData, uint32_t & curLen,
	uint32_t & parserLen, bool & parserBreak)
{
	parserBreak = false;
	uint32_t jsonSize = mCurMsg.head.len - MY_PROTO_HEAD_SIZE;
	if (curLen < jsonSize)
	{
		parserBreak = true; //��ֹ����
		return true;
	}

	Json::Reader reader;    //json������
	if (!reader.parse((char *)(*curData),
		(char *)((*curData) + jsonSize), mCurMsg.body, false))
	{
		return false;
	}

	//����ָ����ǰ�ƶ�jsonSize�ֽ�
	(*curData) += jsonSize;
	curLen -= jsonSize;
	parserLen += jsonSize;
	mCurParserStatus = ON_PARSER_BODY;

	return true;
}

bool MyProtoDeCode::parser(void * data, size_t len)
{
	if (len <= 0)
	{
		return false;
	}

	uint32_t curLen = 0;
	uint32_t parserLen = 0;
	uint8_t * curData = NULL;

	curData = (uint8_t *)data;
	//�ѵ�ǰҪ�����������ֽ���д��δ�������ֽ���֮��
	while (len--)
	{
		mCurReserved.push_back(*curData);
		++curData;
	}

	curLen = mCurReserved.size();
	curData = (uint8_t *)&mCurReserved[0];

	//ֻҪ����δ�����������ֽ������ͳ�������
	while (curLen > 0)
	{
		bool parserBreak = false;
		//����Э��ͷ
		if (ON_PARSER_INIT == mCurParserStatus ||
			ON_PARSER_BODY == mCurParserStatus)
		{
			if (!parserHead(&curData, curLen, parserLen, parserBreak))
			{
				return false;
			}

			if (parserBreak) break;
		}

		//������Э��ͷ������Э����
		if (ON_PARSER_HAED == mCurParserStatus)
		{
			if (!parserBody(&curData, curLen, parserLen, parserBreak))
			{
				return false;
			}

			if (parserBreak) break;
		}

		if (ON_PARSER_BODY == mCurParserStatus)
		{
			//�������������Ϣ����������
			MyProtoMsg * pMsg = NULL;
			pMsg = new MyProtoMsg;
			*pMsg = mCurMsg;
			mMsgQ.push(pMsg);
		}
	}

	if (parserLen > 0)
	{
		//ɾ���Ѿ��������������ֽ���
		mCurReserved.erase(mCurReserved.begin(), mCurReserved.begin() + parserLen);
	}

	return true;
}

bool MyProtoDeCode::empty()
{
	return mMsgQ.empty();
}

MyProtoMsg * MyProtoDeCode::front()
{
	MyProtoMsg * pMsg = NULL;
	pMsg = mMsgQ.front();
	return pMsg;
}

void MyProtoDeCode::pop()
{
	mMsgQ.pop();
}

int main()
{
	uint32_t len = 0;
	uint8_t * pData = NULL;
	MyProtoMsg msg1;
	MyProtoMsg msg2;
	MyProtoDeCode myDecode;
	MyProtoEnCode myEncode;

	msg1.head.server = 1;
	msg1.body["op"] = "set";
	msg1.body["key"] = "id";
	msg1.body["value"] = "9856";

	msg2.head.server = 2;
	msg2.body["op"] = "get";
	msg2.body["key"] = "id";

	myDecode.init();
	pData = myEncode.encode(&msg1, len);
	if (!myDecode.parser(pData, len))
	{
		cout << "parser falied!" << endl;
	}
	else
	{
		cout << "msg1 parser successful!" << endl;
	}

	pData = myEncode.encode(&msg2, len);
	if (!myDecode.parser(pData, len))
	{
		cout << "parser falied!" << endl;
	}
	else
	{
		cout << "msg2 parser successful!" << endl;
	}

	MyProtoMsg * pMsg = NULL;
	while (!myDecode.empty())
	{
		pMsg = myDecode.front();
		myProtoMsgPrint(*pMsg);
		myDecode.pop();
	}

	return 0;
}