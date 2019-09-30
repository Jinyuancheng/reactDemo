#include <iostream>
using namespace std;

int main(int argc,char *argv[])
{
	char* Str[5] = { 
		(char*)"jinzi",
		(char*)"jinzi1",
		(char*)"jinzi2",
		(char*)"jinzi3",
		(char*)"jinzi4" };
	char** Arr = nullptr;
	Arr = Str;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Str[" << i << "] = " << Arr[i] << std::endl;
	}

	system("pause");
	return 0;
}