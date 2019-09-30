/**************************************************************
 * @file main.cpp
 * @date 2019/08/29 11:19
 * @author Jinzi
 * @Contact: 2493349541@qq.com
 * @brief 	该demo用来演示最简单的线程操作
***************************************************************/
#include <iostream>
#include <thread>
#include <windows.h>
using namespace std;

void Print()
{
	while (1)
	{
		std::cout << "子线程最基本的操作" << std::endl;
		Sleep(1000);
	}
}

int main(int argc, char *argv[])
{
	std::thread t1(Print);
	/*\ 在后台执行线程操作 \*/
	t1.detach();
	while (1)
	{
		std::cout << "主线程操作" << std::endl;
		Sleep(2000);
	}
	system("pause");
	return 0;
}