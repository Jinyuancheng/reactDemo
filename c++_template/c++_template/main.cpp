#include <iostream>
using namespace std;

class Student;

template<typename _T>
_T GetAdd(_T a, _T b)
{
	return a + b;
}

int main(int argc, char *argv[])
{
	std::cout << "GetAdd : int 隐示调用" << GetAdd(3, 5) << std::endl;
	std::cout << "GetAdd : int 显示调用" << GetAdd<int>(3, 5) << std::endl;
	std::cout << "GetAdd : string 显示调用" << GetAdd<std::string>("Hello ", "World").c_str() << std::endl;
	std::cout << "GetAdd : double 显示调用" << GetAdd<double>(3, 5) << std::endl;

	system("pause");
	return 0;
}