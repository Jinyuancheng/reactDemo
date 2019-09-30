#include <iostream>
#include <windows.h>
using namespace std;

typedef void(*Regist)(void(*)(void*));


int main(int argc, char* argv[])
{
	HMODULE pHandle = LoadLibrary("./boost_async_timer_dll.dll");
	Regist reg = nullptr;
	if (pHandle != nullptr)
	{
		reg = (Regist)GetProcAddress(pHandle, "RegistCallBack");
	}
	reg();
	system("pause");
	return 0;
}