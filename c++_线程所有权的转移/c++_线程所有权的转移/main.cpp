/**************************************************************
 * @file main.cpp										  
 * @date 2019/08/29 11:08		
 * @author Jinzi                                              
 * @Contact: 2493349541@qq.com							      
 * @brief ��demo��ʾ���߳�����Ȩ��ת��				  
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
	/*\ ����һ���̵߳�ʵ�� \*/
	std::thread t1(Print);			
	/*\ ���߳�t1������Ȩ��ת�Ƶ�t2�� \*/
	std::thread t2 = std::move(t1); 
	
	t2.join();

	system("pause");
	return 0;
}

