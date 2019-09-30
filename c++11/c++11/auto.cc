#include <iostream>
#include <vector>
#include <functional>
using namespace std;

/*\ auto 声明变量必须初始化 否则编译器找寻不到是什么数据类型 auto 不能作为函数形参 \*/
void Auto()
{
	auto a = 3;
	auto b = 5;
	string str = "jinzi";
	decltype(str) str1 = "Hello";
}

void NullPtr()
{
	void* jinzi = malloc(sizeof(1024));
	if (jinzi == nullptr)
	{
		printf("Memory Error\n");
	}
	else
	{
		printf("Memory Success\n");
	}
}

void ForEach()
{
	std::vector<std::string> vecTest;
	vecTest.push_back("jinzi1");
	vecTest.push_back("jinzi2");
	vecTest.push_back("jinzi3");
	for (auto jinzi : vecTest)
	{
		printf("%s\n", jinzi);
	}
}
int add(int a, int b)
{
	return a + b;
}
std::function<int(int, int)> cbAdd;
std::function<void(void*)> cbTest;
int main(int argc,char *argv[])
{
	//Auto();
	//NullPtr();
	cbAdd = add;
	std::cout << cbAdd(2, 3) << endl;
	ForEach();
	auto a = 1;
	system("pause");
	return 0;
}