/**************************************************************
 * @file main.cpp
 * @date 2019/08/29 11:36
 * @author Jinzi
 * @Contact: 2493349541@qq.com
 * @brief �߳�����Ȩ��ת��
		  std::move() ����
***************************************************************/
#include <iostream>
#include <thread>
using namespace std;

void Print()
{
	std::cout << "�߳�ִ��" << std::endl;
}

int main(int argc, char *argv[])
{
	std::thread t1(Print);

	std::cout << "t1.joinable() : " << t1.joinable() << std::endl;

	/*\ ��t1������Ȩ��ֲ��t2,ת���Ժ�t1����ò����ٸ�ֵ \*/
	std::thread t2 = std::move(t1);
	/*\ t1�������»�ȡ����Ȩ,t2ת�ƹ����� \*/
	t1 = std::move(t2);
	std::cout << "t1.joinable() After : " << t1.joinable() << std::endl;

	system("pause");
	return 0;
}