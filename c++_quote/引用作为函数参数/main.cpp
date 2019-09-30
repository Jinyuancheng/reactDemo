#include <iostream>
using namespace std;

//可以省略内存拷贝，类似于指针
void add(int& a, int& b)
{
	std::cout << "a + b = " << a + b << std::endl;
}

void foreach(int* Array, int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << "Array[" << i << "] = " << *Array << std::endl;
		(Array)++;
	}
}
//未成功
void foreach(int& Array, int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << "Array[" << i << "] = " << Array << std::endl;
	}
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap1(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swap2(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main(int argc,char *argv[])
{
	int a = 10;
	int b = 20;
	/*int Arr[3] = { 20,50,70 };
	add(a, b);
	foreach(Arr, 3);*/
	swap(&a, &b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	swap1(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	swap2(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;


	system("pause");
	return 0;
}