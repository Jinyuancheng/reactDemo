#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char *argv[])
{
	std::stack<std::string> stackColl;
	stackColl.push("jinzi");
	stackColl.push("jinzi1");
	stackColl.push("jinzi2");
	stackColl.push("jinzi3");
	int iSize = stackColl.size();
	for (int i = 0; i < iSize; i++)
	{
		std::cout << "res : " << stackColl.top().c_str() << std::endl;
		stackColl.pop();
	}
	if (stackColl.empty())
	{
		std::cout << "stack ����Ϊ��" << std::endl;
	}
	else
	{
		std::cout << "static ���ϲ�Ϊ��" << std::endl;
	}

	system("pause");
	return 0;
}