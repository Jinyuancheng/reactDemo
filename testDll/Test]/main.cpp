#include <iostream>
#include <windows.h>
using namespace std;

int(*func)(int, int);

int main(int argc,char *argv[])
{
	LPCSTR path = "./testDll";
	//����dll�ļ�
	HMODULE h = LoadLibrary(path);
	if (h != NULL)
	{
		func = (int(*)(int, int))GetProcAddress(h, "Sum");
		if (func != NULL)
		{
			try
			{
				int a = func(2, 4);
				cout << a <<endl;
			}
			catch (const std::exception&)
			{
				cout << "����" << endl;
			}
			
		}
	}
	system("pause");
	return 0;
}