#include <iostream>
#include <windows.h>
using namespace std;

int main(int argc, char *argv[])
{

	HMODULE pHandle = nullptr;
	pHandle = LoadLibrary("./HCNetSDK.dll");
	if (pHandle != nullptr)
	{
		std::cout << "succ" << std::endl;
		void* Test = GetProcAddress(pHandle, "NET_DVR_StartListen_V30");
		if (Test != nullptr)
		{
			std::cout << "success" << std::endl;
		}
	}



	system("pause");
	return 0;
}