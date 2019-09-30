#include <iostream>
#include <windows.h>
using namespace std;

int main(int argc, char *argv[])
{
	char chA = 13;
	/*\ 输出低三位的值 \*/
	std::cout << (chA & 0x07) << std::endl;
	/*\ 输出后五位表示的信息 \*/
	std::cout << ((chA & 0x01) == 0x01 ? 1 : 0) << std::endl; /*\ 1 (低位)\*/
	std::cout << ((chA & 0x02) == 0x02 ? 1 : 0) << std::endl; /*\ 2 \*/
	std::cout << ((chA & 0x04) == 0x04 ? 1 : 0) << std::endl; /*\ 3 \*/
	std::cout << ((chA & 0x08) == 0x08 ? 1 : 0) << std::endl; /*\ 4 \*/
	std::cout << ((chA & 0x10) == 0x10 ? 1 : 0) << std::endl; /*\ 5 \*/
	std::cout << ((chA & 0x20) == 0x20 ? 1 : 0) << std::endl; /*\ 6 \*/
	std::cout << ((chA & 0x40) == 0x40 ? 1 : 0) << std::endl; /*\ 7 \*/
	std::cout << ((chA & 0x80) == 0x80 ? 1 : 0) << std::endl; /*\ 8 (高位)\*/
	system("pause");
	return 0;
}