#include <iostream>
using namespace std;

int main1(int argc,char *argv[])
{
	int iType = 0x00000000;

	iType |= 1 << 7;
	iType |= 1 << 10;
	iType |= 1 << 11;
	std::cout << std::hex << iType << std::endl;
	system("pause");
	return 0;
}

char* Ret()
{
	char* chp = (char*)malloc(1024);
	if (chp != nullptr)
	{
		strcpy(chp, "jinzi");
		return chp;
	}
	return nullptr;
}

int main2()
{
	char* chp = Ret();
	std::cout << chp << std::endl;
	free(chp);
	chp = nullptr;
	system("pause");
	return 0;
}

void GetMemory(char** _chppPoint)
{
	*_chppPoint = (char*)malloc(1024);
}
void GetMemory(char*& _cchpPoint)
{
	_cchpPoint = (char*)malloc(1024);
}
int main()
{
	char* chp = nullptr;
	GetMemory(chp);
	strcpy(chp, "jinzi");
	std::cout << chp << std::endl;
	system("pause");
	return 0;
}