#include <iostream>
using namespace std;

typedef int(*Func)(int, int);

int* OptNum(Func _Func, int a, int b)
{
	int* Num = (int*)malloc(sizeof(int));
	*Num = _Func(a, b);
	std::cout << "Num = " << *Num << std::endl;
	return Num;
}

int add(int a, int b)
{
	return a + b;
}

int reduce(int a, int b)
{
	return a - b;
}

int main(int argc,char *argv[])
{
	int* Num = OptNum(add, 3, 5);
	std::cout << "*Num = " << *Num << std::endl;
	Num = OptNum(reduce, 7, 5);
	std::cout << "*Num = " << *Num << std::endl;
	free(Num);
	Num = nullptr;
	system("pause");
	return 0;
}