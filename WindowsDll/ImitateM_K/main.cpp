#include <iostream>
#include <windows.h>
#include <process.h>

using namespace std;



int main(int argc,char* argv[])
{
	//定位鼠标
	SetCursorPos(35, 840);
	Sleep(1000);
	//模拟鼠标点击
	mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 35, 840, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 35, 840, 0, 0);
	//定位鼠标
	SetCursorPos(450, 485);
	//模拟鼠标点击
	mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 450, 485, 0, 0);
	//模仿键盘输入
	keybd_event('J', 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
	return 0;
}