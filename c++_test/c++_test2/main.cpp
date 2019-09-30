#include <iostream>
using namespace std;

int main(int argc,char *argv[])
{
	int iA = 233;
	int iCount = 0;
	for (int i = 0; i < 32; i++)
	{
		if ((iA & 0x01) == 0x01)
		{
			iCount++;
		}
		iA >>= 1;
	}
	std::cout << "count = " << iCount << std::endl;
	system("pause");
	return 0;
}