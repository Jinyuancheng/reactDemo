#include <iostream>
#include <windows.h>
#include <process.h>

using namespace std;



int main(int argc,char* argv[])
{
	//��λ���
	SetCursorPos(35, 840);
	Sleep(1000);
	//ģ�������
	mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 35, 840, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 35, 840, 0, 0);
	//��λ���
	SetCursorPos(450, 485);
	//ģ�������
	mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 450, 485, 0, 0);
	//ģ�¼�������
	keybd_event('J', 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
	return 0;
}