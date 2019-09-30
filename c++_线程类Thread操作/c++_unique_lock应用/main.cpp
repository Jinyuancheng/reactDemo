/**************************************************************
 * @file main.cpp
 * @date 2019/08/29 16:21
 * @author Jinzi
 * @Contact: 2493349541@qq.com
 * @brief ��demo��������unique_lock�Ĳ���
***************************************************************/
#include <iostream>
#include <thread>
#include <mutex>
#include <functional>
#include <algorithm>

using namespace std;

class CTest
{
public:
	CTest() { }
public:
	void Demo()
	{
		std::cout << "jinzi" << std::endl;
	}
	int test111(int i)
	{
		std::cout << i << std::endl;
		return i;
	}
	void test222(int a, int b)
	{
		std::cout << a * b << std::endl;
	}
	/*\ ʹ��unique_lock���м��� \*/
	void test(CTest _oTest1, CTest _oTest2)
	{
		/*\ defer_lock ��������ԪΪδ���� \*/
		std::unique_lock<std::mutex> oLock_1(_oTest1.m_oMutex, std::defer_lock);
		std::unique_lock<std::mutex> oLock_2(_oTest2.m_oMutex, std::defer_lock);
		/*\ ���� \*/
		std::lock(oLock_1, oLock_2);
		Demo();
	}
protected:
private:
	std::mutex m_oMutex;
};

int main(int argc, char *argv[])
{
	CTest test1;
	CTest test2;

	std::thread t1(&CTest::test222, &CTest(), test1, test2);

	t1.join();

	system("pause");
	return 0;
}