#include <iostream>
#include <windows.h>

using namespace std;

int main(int argc, char* argv[])
{
	/*\ Ѱ�Ҳ��رպڴ��� \*/
	ShowWindow(FindWindow("ConsoleWindowClass", argv[0]), 0);
	while (1)
	{
		HWND hHandle = FindWindow("YodaoMainWndClass", "�����е��ʵ�");
		if (hHandle == NULL)
		{
			printf("Ѱ�Ҵ���ʧ��\n");
		}
		else
		{
			keybd_event('j', KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0, 0);
			/*\ �ƶ����ڲ����ô��ڴ�С \*/
			MoveWindow(hHandle, 300, 300, 900, 500, false);
			Sleep(5000);
		}
	}
	system("pause");
	return 0;
}