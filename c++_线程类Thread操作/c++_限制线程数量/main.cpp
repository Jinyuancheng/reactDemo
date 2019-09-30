/**************************************************************
 * @file main.cpp										  
 * @date 2019/08/29 13:12		
 * @author Jinzi                                              
 * @Contact: 2493349541@qq.com							      
 * @brief 该demo演示 限制线程数量	
		  返回硬件线程上下文数量 hardware_concurrency()
		  跟创建的线程数 没有关系
***************************************************************/
#include <iostream>
#include <thread>
using namespace std;

void test() {}

int main(int argc,char *argv[])
{
	std::thread t1(test);
	std::cout << std::thread::hardware_concurrency() << std::endl;
	system("pause");
	return 0;
}
