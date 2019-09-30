#include <iostream>
#include <set> //按照特定顺序存储唯一元素的容器
using namespace std;

int main(int argc, char *argv[])
{
	/*\ 存储唯一的数据 \*/
	std::set<std::string> setData;

	setData.insert("jinzi");
	/*\ 存储重复数据，他会替换，不会进行二次存储 \*/
	setData.insert("jinzi");
	setData.insert("woqu");
	std::cout << "size() = " << setData.size() << std::endl;
	std::cout << "max_size() = " << setData.max_size() << std::endl;
	for (std::set<std::string>::iterator it = setData.begin();
		it != setData.end(); it++)
	{
		std::cout << it->c_str() << std::endl;
	}
	setData.clear();
	if (setData.empty())
	{
		std::cout << "集合为空" << std::endl;
	}
	else
	{
		std::cout << "集合不为空" << std::endl;
	}
	system("pause");
	return 0;
}