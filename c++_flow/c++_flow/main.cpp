#include <iostream>
#include <windows.h>
using namespace std;

typedef void(*FuncCB)(void*);
typedef void(*StartUp)(FuncCB);
typedef void(*SendData)(std::string);

void CallBack(void* arg)
{
	std::string str;
	str = (const char*)arg;
	std::cout << "arg : " << str.c_str() << std::endl;
}

int main(int argc,char *argv[])
{
	HMODULE pHandle = LoadLibrary("./flow_dll.dll");
	if (pHandle)
	{
		StartUp StartUpFunc = (StartUp)GetProcAddress(pHandle, "StartUp");
		if (StartUpFunc)
		{
			StartUpFunc(CallBack);
		}
		SendData SendDataFunc = (SendData)GetProcAddress(pHandle, "CallBack");
		if (SendDataFunc)
		{
			SendDataFunc("Hello Dll");
		}
	}

	//StartUp==>0x100110b4
	//(*((StartUp)0x0f9a10b4))(CallBack);
	////CallBack==>0x100112e4
	//(*((SendData)0x0f9a12e4))("Hello Dll");
	system("pause");
	return 0;
}