/**************************************************************
 * @file main.cpp										  
 * @date 2019/08/29 11:08		
 * @author Jinzi                                              
 * @Contact: 2493349541@qq.com							      
 * @brief 该demo演示了线程所有权的转移				  
***************************************************************/
#include <iostream>
#include <thread>
using namespace std;

void Print()
{
	std::cout << "test" << std::endl;
}

int main(int argc,char *argv[])
{
	/*\ 定义一个线程的实例 \*/
	std::thread t1(Print);			
	/*\ 将线程t1的所有权，转移到t2上 \*/
	std::thread t2 = std::move(t1); 
	
	t2.join();

	system("pause");
	return 0;
}

