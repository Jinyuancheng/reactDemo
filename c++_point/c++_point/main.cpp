#include <iostream>
using namespace std;

int main(int argc,char *argv[])
{
	int a = 10;
	int Array[6] = { 0,11,22,33,44,55 };
	int* p = nullptr;
	int* Arr = nullptr;
	p = &a;
	Arr = Array;
	*p = 20;
	std::cout << "*p = " << *p << std::endl;
	std::cout << "Arr + 2 = " << *(Arr + 2) << std::endl;
	for (int i = 0; i < 6; i++)
	{
		std::cout << "Arr[" << i << "] = " << *Arr << std::endl;
		Arr++;
	}
	system("pause");
	return 0;
}