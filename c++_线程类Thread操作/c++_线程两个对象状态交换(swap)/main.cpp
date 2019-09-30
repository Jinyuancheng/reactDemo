/**************************************************************
 * @file main.cpp										  
 * @date 2019/08/29 11:43		
 * @author Jinzi                                              
 * @Contact: 2493349541@qq.com							      
 * @brief 线程两个对象状态的交换				  
		  swap()函数 joinable()是否可连接
***************************************************************/
#include <iostream>
#include <thread>
using namespace std;

void Print()
{ 
	//std::cout << "print" << std::endl;
}

int main(int argc,char *argv[])
{
	std::thread t1;
	std::thread t2(Print);

	std::cout << "t1.joinable() first : " << t1.joinable() << std::endl;
	std::cout << "t2.joinable() first : " << t2.joinable() << std::endl;
	
	t1.swap(t2);

	std::cout << "t1.joinable() last : " << t1.joinable() << std::endl;
	std::cout << "t2.joinable() last : " << t2.joinable() << std::endl;

	system("pause");
	return 0;
}
