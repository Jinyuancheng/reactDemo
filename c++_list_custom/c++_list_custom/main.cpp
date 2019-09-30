#include <iostream>
using namespace std;

/*\ 用来存储数据 \*/
typedef struct
{
	char chpData[256];
	unsigned int uiDataLength;
}Data, *pData;

/*\ 链表的节点 \*/
typedef struct Node
{
	Data* opData;
	Node* opEnd;
}Node, *pNode;

/*\ 创建链表,头结点 \*/
Node* CreateList(Data* _opData);
/*\ 在链表尾部添加数据 \*/
void AddNodeEnd(Node* _opNodeHead, Node* _opNodeEnd);

int main(int argc, char *argv[])
{
	Data* opDataHead = new Data();
	strcpy_s(opDataHead->chpData, "jinzi");
	opDataHead->uiDataLength = 6;
	Node* opNodeHead = CreateList(opDataHead);
	Node* opNode = new Node();
	opNode->opData = opDataHead;
	AddNodeEnd(opNodeHead, opNode);
	system("pause");
	return 0;
}

/*\ 创建链表头指针 \*/
Node* CreateList(Data* _opData)
{
	Node* opHeadNode = new Node();
	opHeadNode->opEnd = nullptr;
	opHeadNode->opData = _opData;
	return opHeadNode;
}

/*\ 在链表尾部添加数据 \*/
void AddNodeEnd(Node* _opNodeHead, Node* _opNodeEnd)
{
	while (true)
	{
		if (_opNodeHead->opEnd == nullptr)
		{
			_opNodeHead->opEnd = _opNodeEnd;
			_opNodeEnd->opEnd = nullptr;
			break;
		}
		_opNodeHead++;
	}
}