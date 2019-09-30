#include <iostream>
#include <Windows.h>

using namespace std;
typedef int(*Function)(int, int, int(*)(int, int));
typedef int(*tianjia)(int, int);
tianjia add;

int Add(int a,int b) 
{
	return a + b;
}

int main(int argc, char* agrv[])
{
	HMODULE JinziHandler = LoadLibrary("./Jinzi_Utils");
	if (JinziHandler == NULL)
	{
		FreeLibrary(JinziHandler);
	}
	else
	{
		Function Opreator = (Function)GetProcAddress(JinziHandler,"Operation");
		int result = Opreator(3, 4, Add);
		cout << "result = " << result << endl;
		add = (int(*)(int,int))GetProcAddress(JinziHandler, "add");
		int results = add(3,4);
		cout << "results = " << results << endl;
	}

	system("pause");

	return 0;
}