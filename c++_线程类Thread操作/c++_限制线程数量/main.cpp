/**************************************************************
 * @file main.cpp										  
 * @date 2019/08/29 13:12		
 * @author Jinzi                                              
 * @Contact: 2493349541@qq.com							      
 * @brief ��demo��ʾ �����߳�����	
		  ����Ӳ���߳����������� hardware_concurrency()
		  ���������߳��� û�й�ϵ
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
