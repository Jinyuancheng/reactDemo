#include <iostream>
#include <vector>
using namespace std;

void Print(std::vector<int> _VecInt)
{
	std::vector<int>::iterator it = _VecInt.begin();
	std::cout << "==================================================================" << std::endl;
	for (it; it != _VecInt.end(); it++)
	{
		std::cout << "*it : " << *it << std::endl;
	}
	std::cout << "==================================================================" << std::endl;
	std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ END @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
}

int main(int argc, char *argv[])
{
	std::vector<int> vecInt;
	for (int i = 0; i < 10; i++)
	{
		//��ĩβ���һ��Ԫ��
		vecInt.push_back(i);
	}
	Print(vecInt);

	//ɾ��ĩβ��һ��Ԫ��
	//vecInt.pop_back();

	//��ָ��λ�ò���һ������
	//vecInt.insert(vecInt.begin() + 1, 20);

	//��ָ��λ��ɾ��һ��Ԫ��
	//vecInt.erase(vecInt.end() - 1);

	Print(vecInt);
	system("pause");
	return 0;
}