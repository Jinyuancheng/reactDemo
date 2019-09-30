#include <iostream>
#include <windows.h>

using namespace std;

int main(int argc, char* argv[])
{
	/*\ 寻找并关闭黑窗口 \*/
	ShowWindow(FindWindow("ConsoleWindowClass", argv[0]), 0);
	while (1)
	{
		HWND hHandle = FindWindow("YodaoMainWndClass", "网易有道词典");
		if (hHandle == NULL)
		{
			printf("寻找窗口失败\n");
		}
		else
		{
			keybd_event('j', KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0, 0);
			/*\ 移动窗口并设置窗口大小 \*/
			MoveWindow(hHandle, 300, 300, 900, 500, false);
			Sleep(5000);
		}
	}
	system("pause");
	return 0;
}