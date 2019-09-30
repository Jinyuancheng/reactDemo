/**************************************************************
 * @file main.cpp										  
 * @date 2019/08/29 11:26		
 * @author Jinzi                                              
 * @Contact: 2493349541@qq.com							      
 * @brief 该demo用来演示Thread类的join函数和joinable函数			
		  join()函数 更改线程将会变为不可重新赋值状态
		  joinable()函数 判断线程是否可以赋值
***************************************************************/
#include <iostream>
#include <thread>
using namespace std;

void Print()
{
	//std::cout << "线程执行" << std::endl;
}

int main(int argc,char *argv[])
{
	std::thread t1;
	std::thread t2(Print);

	std::cout << "t1==>id : " << t1.get_id() << std::endl;
	std::cout << "t2==>id : " << t2.get_id() << std::endl;
	std::cout << "t1 : " << t1.joinable() << std::endl;
	std::cout << "t2 : " << t2.joinable() << std::endl;

	//t1.join();
	t2.join();

	std::cout << "t1==>id : " << t1.get_id() << std::endl;
	std::cout << "t2==>id : " << t2.get_id() << std::endl;
	std::cout << "t1 : " << t1.joinable() << std::endl;
	std::cout << "t2 : " << t2.joinable() << std::endl;

	system("pause");
	return 0;
}