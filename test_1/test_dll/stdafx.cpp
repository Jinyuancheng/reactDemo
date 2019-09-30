#include "stdafx.h"
#include <windows.h>

extern "C" __declspec(dllexport) 
void go()
{
	while (1)
	{
		Sleep(5000);
		MessageBox(NULL, L"test_dll", L"ÌבÊ¾", MB_OK);
	}
}