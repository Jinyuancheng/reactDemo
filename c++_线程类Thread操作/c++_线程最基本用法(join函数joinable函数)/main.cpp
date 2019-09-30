/**************************************************************
 * @file main.cpp										  
 * @date 2019/08/29 11:26		
 * @author Jinzi                                              
 * @Contact: 2493349541@qq.com							      
 * @brief ��demo������ʾThread���join������joinable����			
		  join()���� �����߳̽����Ϊ�������¸�ֵ״̬
		  joinable()���� �ж��߳��Ƿ���Ը�ֵ
***************************************************************/
#include <iostream>
#include <thread>
using namespace std;

void Print()
{
	//std::cout << "�߳�ִ��" << std::endl;
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