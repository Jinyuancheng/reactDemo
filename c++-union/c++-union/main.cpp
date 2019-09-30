#include <iostream>
using namespace std;

typedef union
{
	unsigned char Num;
	struct  
	{
		unsigned char NumL : 4;
		unsigned char NumH : 4;
	};
}unionTest;


int main(int argc,char *argv[])
{
	unionTest test;
	test.Num = 10;
	std::cout << test.Num << std::endl;
	std::cout << test.NumH << std::endl;
	std::cout << test.NumL << std::endl;

	system("pause");
	return 0;
}