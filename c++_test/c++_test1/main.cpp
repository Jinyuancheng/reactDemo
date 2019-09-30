#include <iostream>
using namespace std;



int main(int argc,char *argv[])
{
	int iNumber = 233;

	std::cout << "iNumber : " << iNumber << std::endl;

	iNumber |= 0x04;
	iNumber |= 0x40;
	iNumber |= 0x80;
	iNumber |= 0x080000;

	std::cout << "iNumber : " << iNumber << std::endl;
	system("pause");
	return 0;
}