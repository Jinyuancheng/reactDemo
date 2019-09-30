/**************************************************************
 * @file main.cpp
 * @date 2019/08/29 17:29
 * @author Jinzi
 * @Contact: 2493349541@qq.com
 * @brief 该demo用来测试std::bind函数
***************************************************************/
#include <iostream>
#include <functional>
using namespace std;

class CTest
{
public:
	CTest() {}
public:
	void Study(int _iGarden)
	{
		std::cout << _iGarden << std::endl;
	}
protected:
private:
};

int main(int argc, char *argv[])
{
	CTest test;
	auto TestFunc = std::bind(&CTest::Study, test, 50);
	TestFunc();
	auto TestFunc1 = std::bind(&CTest::Study, CTest(), 60);
	TestFunc1();
	auto TestFunc2 = std::bind(&CTest::Study, CTest(), std::placeholders::_1);
	TestFunc2(70);
	system("pause");
	return 0;
}