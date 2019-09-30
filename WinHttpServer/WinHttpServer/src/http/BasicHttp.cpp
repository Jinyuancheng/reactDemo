#include "../../include/http/BasicHttp.h"

BasicHttp::BasicHttp()
{
}


BasicHttp::~BasicHttp()
{
}

void BasicHttp::ManagerInit()
{
	mg_mgr_init(&this->m_Manger, NULL);
}

void BasicHttp::ManagerBind(const char* _Port)
{
	this->m_Conn = mg_bind(&this->m_Manger, _Port, EventHandle);
	printf("HttpServer Listen Port : %s\n",_Port);
}
//����http
void BasicHttp::ManagerSetHttp()
{
	mg_set_protocol_http_websocket(this->m_Conn);
}

//��ѯ
void BasicHttp::ManagerPoll()
{
	for (;;) {
		mg_mgr_poll(&this->m_Manger, 1000);
	}
	mg_mgr_free(&this->m_Manger);
}

void BasicHttp::EventHandle(Connection* _Conn, int _Ev, void* _UserData)
{
	//�ͻ��˷��͹���������
	ClientSendData *iHttpMessage = (ClientSendData*)_UserData;
	switch (_Ev)
	{
	case MG_EV_HTTP_REQUEST:
		BasicHttp::ManagerHandleRouter(_Conn, iHttpMessage);
		break;
	}
}
//�õ�����
Connection* BasicHttp::ManagerGetConn()
{
	return this->m_Conn;
}

//���ͻ��˷�������
void BasicHttp::ManagerServerToClientData(Connection* _Connect, const char* _SendData)
{
	/* Send headers */
	mg_printf(_Connect, "%s", "HTTP/1.1 200 OK\r\nTransfer-Encoding: chunked\r\n\r\n");
	//Ҫ���͵�����
	mg_printf_http_chunk(_Connect, _SendData);
	//��ʾ��Ӧ����
	mg_send_http_chunk(_Connect, "", 0); /* Send empty chunk, the end of response */
}

//���Ϳͻ�����������Ϊ��
void BasicHttp::ManagerSendClientReqDataNull(Connection* _Connect)
{
	/* Send headers */
	mg_printf(_Connect, "%s", "HTTP/1.1 200 OK\r\nTransfer-Encoding: chunked\r\n\r\n");
	//Ҫ���͵�����
	const char* iNullStr = "{ \"result\":\"Client Request Data Null!!!\" }";
	mg_printf_http_chunk(_Connect, iNullStr);
	//��ʾ��Ӧ����
	mg_send_http_chunk(_Connect, "", 0); /* Send empty chunk, the end of response */
}

//�����ͻ��˷��͵�����
//_DataBody mg_str�ṹ�� �洢�ͻ��˷��͵ľ�������
//_Name �ͻ��˷��͹����� ����������
//_SaveBuf Ҫ��������ĸñ�����ֵ��ŵĻ���������
//_SizeSaveBuf ���������ݵĴ�С sizeof(_SaveBuf)
void BasicHttp::ManagerResolver(DataBody* _DataBody, const char* _Name, char* _SaveBuf, size_t _SizeSaveBuf)
{
	mg_get_http_var(_DataBody, _Name, _SaveBuf, _SizeSaveBuf);
}

//����Test·��
//_Connect �ͻ��˵����Ӿ��
//_ReqData �ͻ������������
void BasicHttp::ManagerHandleTest(Connection* _Connect, ClientSendData* _ReqData)
{
	if (&_ReqData->body.len == (size_t)0)
	{
		//���ͻ��˷�����������Ϊnull
		BasicHttp::ManagerSendClientReqDataNull(_Connect);
	}
	else
	{
		//�������տͻ��˷��͹���������
		char buf[100];
		memset(buf, 0, sizeof(buf));
		memcpy(buf, _ReqData->body.p, sizeof(buf) < _ReqData->body.len ? sizeof(buf) - 1 : _ReqData->body.len);
		printf("Client Send Data : %s\n",buf);
		//�������ս���֮�������
		char name[100];
		char pass[100];
		//mg_get_http_var������������
		BasicHttp::ManagerResolver(&_ReqData->body, "name", name, sizeof(name));
		BasicHttp::ManagerResolver(&_ReqData->body, "pass", pass, sizeof(pass));
		printf("n1 = %s\n",name);
		printf("n2 = %s\n", pass);
		const char* iResData = "{ \"result\":\"success\" }";
		BasicHttp::ManagerServerToClientData(_Connect, iResData);
	}
}

//�����������·�ɵ���Ϣ
//_clientSendMessage �ͻ��˷��͹���������
//hm ����http_message �ṹ�� ����洢�˿ͻ��˷��͵ľ�����Ϣ
void BasicHttp::ManagerHandleRouter(Connection* _Conn,ClientSendData* hm)
{
	//�������Ե�·��
	//mg_vcmp���������ж�·��
	if (mg_vcmp(&hm->uri, TEST) == 0) {
		BasicHttp::ManagerHandleTest(_Conn,hm);
	}
	
}

