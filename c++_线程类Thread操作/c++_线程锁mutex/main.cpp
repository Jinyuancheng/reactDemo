/**************************************************************
 * @file main.cpp
 * @date 2019/08/29 14:04
 * @author Jinzi
 * @Contact: 2493349541@qq.com
 * @brief ��demo������ʾmutex���÷�
***************************************************************/
#include <iostream>
#include <list>
#include <mutex>
#include <thread>
#include <algorithm>
using namespace std;

std::list<int>	gl_lstSaveData;	/*\ һ�����������洢���� \*/
std::mutex		gl_oMutex;		/*\ �߳���,����Ԫ \*/

void WriteList()
{
	int iNum = 0;
	while (1)
	{
		iNum++;
		/*\ ��������,���������������� \*/
		std::lock_guard<std::mutex> oGuard(gl_oMutex);
		gl_lstSaveData.push_back(iNum);
	}
}

void ReadList(int _iReadData)
{
	std::lock_guard<std::mutex> oGuard(gl_oMutex);
	if (std::find(gl_lstSaveData.begin(), gl_lstSaveData.end(), _iReadData) != gl_lstSaveData.end())
	{
		std::cout << "Ѱ�ҵ���" << std::endl;
	}
	else
	{
		std::cout << "û��Ѱ�ҵ�" << std::endl;
	}
}

int main1(int argc, char *argv[])
{
	std::thread t1(WriteList);
	std::thread t2(ReadList, 100);
	t1.detach();
	system("pause");
	return 0;
}