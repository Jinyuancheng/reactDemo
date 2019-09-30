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
		//在末尾添加一个元素
		vecInt.push_back(i);
	}
	Print(vecInt);

	//删除末尾的一个元素
	//vecInt.pop_back();

	//在指定位置插入一个数据
	//vecInt.insert(vecInt.begin() + 1, 20);

	//在指定位置删除一个元素
	//vecInt.erase(vecInt.end() - 1);

	Print(vecInt);
	system("pause");
	return 0;
}