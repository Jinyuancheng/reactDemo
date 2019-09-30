#include <iostream>
#include <windows.h>
using namespace std;

void(*func)(const char*);

int main(int argc,char *argv[])
{
	const char* path = "./WinHttpServerDll";
	//º”‘ÿ∂ØÃ¨ø‚
	HMODULE hDll = LoadLibrary(path);
	if (hDll != NULL)
	{
		func = (void(*)(const char*))GetProcAddress(hDll, "Init");
		if (func != NULL)
		{
			const char* Port = "10086";
			func(Port);
		}
	}

	system("pause");
	return 0;
}