#include <iostream>
using namespace std;

/*\ �����洢���� \*/
typedef struct
{
	char chpData[256];
	unsigned int uiDataLength;
}Data, *pData;

/*\ ����Ľڵ� \*/
typedef struct Node
{
	Data* opData;
	Node* opEnd;
}Node, *pNode;

/*\ ��������,ͷ��� \*/
Node* CreateList(Data* _opData);
/*\ ������β��������� \*/
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

/*\ ��������ͷָ�� \*/
Node* CreateList(Data* _opData)
{
	Node* opHeadNode = new Node();
	opHeadNode->opEnd = nullptr;
	opHeadNode->opData = _opData;
	return opHeadNode;
}

/*\ ������β��������� \*/
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