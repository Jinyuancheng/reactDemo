/**************************************************************
 * @file main.cpp
 * @date 2019/08/29 13:32
 * @author Jinzi
 * @Contact: 2493349541@qq.com
 * @brief 该demo用来演示标识线程
***************************************************************/
#include <iostream>
#include <thread>
using namespace std;

void Print()
{
	std::cout << "子线程id ： " << std::this_thread::get_id() << std::endl;
}

int main(int argc, char *argv[])
{
	std::thread t1(Print);
	std::cout << "主线程id ： " << std::this_thread::get_id() << std::endl;
	std::cout << "子线程id第二种方式 : " << t1.get_id() << std::endl;
	system("pause");
	return 0;
}