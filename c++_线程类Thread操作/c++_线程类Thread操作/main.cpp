/**************************************************************
 * @file main.cpp
 * @date 2019/08/29 11:19
 * @author Jinzi
 * @Contact: 2493349541@qq.com
 * @brief 	��demo������ʾ��򵥵��̲߳���
***************************************************************/
#include <iostream>
#include <thread>
#include <windows.h>
using namespace std;

void Print()
{
	while (1)
	{
		std::cout << "���߳�������Ĳ���" << std::endl;
		Sleep(1000);
	}
}

int main(int argc, char *argv[])
{
	std::thread t1(Print);
	/*\ �ں�ִ̨���̲߳��� \*/
	t1.detach();
	while (1)
	{
		std::cout << "���̲߳���" << std::endl;
		Sleep(2000);
	}
	system("pause");
	return 0;
}