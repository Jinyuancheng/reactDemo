/**************************************************************
 * @file main.cpp
 * @date 2019/08/29 11:36
 * @author Jinzi
 * @Contact: 2493349541@qq.com
 * @brief 线程所有权的转让
		  std::move() 函数
***************************************************************/
#include <iostream>
#include <thread>
using namespace std;

void Print()
{
	std::cout << "线程执行" << std::endl;
}

int main(int argc, char *argv[])
{
	std::thread t1(Print);

	std::cout << "t1.joinable() : " << t1.joinable() << std::endl;

	/*\ 将t1的所有权移植给t2,转移以后t1将变得不可再赋值 \*/
	std::thread t2 = std::move(t1);
	/*\ t1可以重新获取所有权,t2转移过来的 \*/
	t1 = std::move(t2);
	std::cout << "t1.joinable() After : " << t1.joinable() << std::endl;

	system("pause");
	return 0;
}