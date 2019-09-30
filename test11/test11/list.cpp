#include <iostream>
using namespace std;

typedef struct  
{
	int			id;
	char		message[1024];
}Message, *pMessage;

typedef struct List
{
	pMessage		pMsg;
	struct List*	pNext;
}Jinzi_List,*pJinzi_List;

/*\ 创建一个空的链表,返回链表的头节点 \*/
pJinzi_List CreateList(pMessage _Msg)
{
	pJinzi_List pHead = (pJinzi_List)malloc(sizeof(Jinzi_List));
	if (pHead != nullptr)
	{
		if (_Msg == nullptr)
		{
			memset(pHead->pMsg, 0, sizeof(pHead->pMsg));
			pHead->pNext = nullptr;
		}
		else
		{
			pHead->pMsg = _Msg;
			pHead->pNext = nullptr;
		}
		return pHead;
	}
	return nullptr;
}
/*\ 向链表中尾部添加节点 \*/
bool InsertLastNote(pJinzi_List _pHead, pMessage _pMsg)
{
	bool bRet = false;
	bool bIsNull = true;
	pJinzi_List pOptList = _pHead;
	pJinzi_List plist = (pJinzi_List)malloc(sizeof(Jinzi_List));
	if (plist->pNext != nullptr)
	{
		while (bIsNull)
		{
			if (pOptList != nullptr)
			{
				pOptList++;
			}
			else
			{
				bIsNull = false;
				pOptList->pNext = plist;
				pOptList->pMsg = _pMsg;
				bRet = true;
			}
		}
		
	}
	return bRet;
}
/*\ 删除所有节点 \*/
bool DelteAllNote(pJinzi_List _pHead)
{
	bool bRet = false;
	bool bIsNull = true;
	pJinzi_List pOptHead = _pHead;
	pJinzi_List pOptList = _pHead + 1;
	while (bIsNull)
	{
		if (pOptList->pNext != nullptr)
		{
			free(pOptHead);
			pOptHead = pOptList;
			pOptList = _pHead++;
		}
		else
		{
			bIsNull = false;
			free(pOptHead);
			free(pOptList);
		}
	}
	return bRet;
}

int main(int argc,char *argv[])
{
	pMessage strMsg = (pMessage)malloc(sizeof(Message));
	if (strMsg == nullptr)
	{
		std::cout << "Malloc Message Error" << std::endl;
		return -1;
	}
	memset(strMsg, 0, sizeof(strMsg));
	strMsg->id = 1;
	memcpy(strMsg->message, "test1", 6);
	pJinzi_List _pListHead = CreateList(strMsg);
	strMsg->id = 2;
	memcpy(strMsg->message, "test2", 6);
	if (InsertLastNote(_pListHead, strMsg))
	{
		std::cout << "插入成功" << std::endl;
	}
	else
	{
		std::cout << "插入失败" << std::endl;
	}


	system("pause");
	return 0;
}