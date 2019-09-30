#include <iostream>
using namespace std;
// 0x02 0000 0010 //==>10 00 00 00==>大端模式
typedef union
{
	unsigned char a;
	struct  
	{
		unsigned int AL : 4;
		unsigned int AH : 4;
	};
}Example;
typedef union
{
	unsigned int a;
	struct
	{
		unsigned char A1;
		unsigned char A2;
		unsigned char A3;
		unsigned char A4;
	};
}Example1;
typedef union 
{
	int i;
	char c;
}Example2;
int main(int argc,char *argv[])
{
	Example e;
	Example1 e1;
	Example2 e2;

	e.a = 223;

	e1.A1 = 10;
	e1.A2 = 20;
	e1.A3 = 30;

	e2.i = 1;//0x00 00 00 01 //小段模式 0x00 00 26 9f
	if (e2.c == 1)
	{
		//0x00 0x00 0x00 0x01
		std::cout << "小段模式" << std::endl;
	}
	else
	{
		//0x01 0x00 0x00 0x00
		std::cout << "大段模式" << std::endl;
	}
	std::cout << "AL : " << e.AL << std::endl;
	std::cout << "AH : " << e.AH << std::endl;
	std::cout << "e1.a : " << e1.a << std::endl;
	system("pause");
	return 0;
}
