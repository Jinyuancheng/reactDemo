/**************************************************************
 * @file main.cpp
 * @date 2019/08/29 13:32
 * @author Jinzi
 * @Contact: 2493349541@qq.com
 * @brief ��demo������ʾ��ʶ�߳�
***************************************************************/
#include <iostream>
#include <thread>
using namespace std;

void Print()
{
	std::cout << "���߳�id �� " << std::this_thread::get_id() << std::endl;
}

int main(int argc, char *argv[])
{
	std::thread t1(Print);
	std::cout << "���߳�id �� " << std::this_thread::get_id() << std::endl;
	std::cout << "���߳�id�ڶ��ַ�ʽ : " << t1.get_id() << std::endl;
	system("pause");
	return 0;
}