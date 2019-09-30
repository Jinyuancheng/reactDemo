/**************************************************************
 * @file main.cpp
 * @date 2019/08/29 15:47
 * @author Jinzi
 * @Contact: 2493349541@qq.com
 * @brief 该demo用来演示 多线程中一个锁包含多个互斥元
			侧重点XingWei函数
***************************************************************/
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

class CStudent
{
public:
	CStudent() {}
public:
	void ChiFan()
	{
		std::cout << "吃饭" << std::endl;
	}
	void ShuiJiao()
	{
		std::cout << "睡觉" << std::endl;
	}
	void XingWei(CStudent& _oStu1, CStudent& _oStu2)
	{
		std::lock(_oStu1.m_oMutex, _oStu2.m_oMutex);
		std::lock_guard<std::mutex> oStuMutex1(_oStu1.m_oMutex, std::adopt_lock);
		std::lock_guard<std::mutex> oStuMutex2(_oStu2.m_oMutex, std::adopt_lock);
		ChiFan();
		ShuiJiao();
	}
private:
	std::mutex m_oMutex;
};

int main(int argc, char *argv[])
{
	CStudent stu1;
	CStudent stu2;
	stu1.XingWei(stu1, stu2);
	system("pause");
	return 0;
}
