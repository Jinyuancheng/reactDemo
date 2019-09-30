#include <iostream>
using namespace std;

typedef union 
{
	unsigned char buf;
	//从左到右分配 0010 1000 从底位到高位进行分配
	struct  
	{
		unsigned char buf_1 : 1;
		unsigned char buf_2 : 1;
		unsigned char buf_3 : 1;
		unsigned char buf_4 : 1;
		unsigned char buf_5 : 1;
		unsigned char buf_6 : 1;
		unsigned char buf_7 : 1;
		unsigned char buf_8 : 1;
	};
}UNIONTEST;

int main(int argc,char *argv[])
{
	UNIONTEST utest;
	utest.buf = 40;
	std::cout << "buf = " << utest.buf << std::endl;;
	utest.buf_2 = 1;
	std::cout << "buf = " << utest.buf << std::endl;;

	system("pause");
	return 0;
}