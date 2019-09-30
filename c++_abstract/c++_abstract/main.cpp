/**************************************************************
 * @file main.cpp
 * @date 2019/08/26 16:23
 * @author Jinzi
 * @Contact: 2493349541@qq.com
 * @brief 该demo用来测试 抽象类
***************************************************************/
#include <iostream>
using namespace std;
/*\ 抽象类 \*/
class CAbstract
{
public:
	virtual void virlSetId(int _iId) = 0;
	virtual void virlSetName(std::string _sName) = 0;
protected:
	int         m_iId;		/*\ 抽象类id \*/
	std::string m_sName;	/*\ 抽象类名称 \*/
};

class CTest :public CAbstract
{
public:
	CTest(int _iId, std::string _sName) :
		m_iTestId(_iId), m_sTestName(_sName) 
	{
		m_iId = -1;
		m_sTestName = "";
	}
public:
	void virlSetId(int _iId)
	{
		m_iId = _iId;
	}
	void virlSetName(std::string _sName)
	{
		m_sName = _sName;
	}
	void Print()
	{
		std::cout << "抽象类id : " << m_iId << std::endl;
		std::cout << "抽象类Name : " << m_sName.c_str() << std::endl;
		std::cout << "Test类id : " << m_iTestId << std::endl;
		std::cout << "Test类Name : " << m_sTestName.c_str() << std::endl;
	}
private:
	int         m_iTestId;	/*\ test类id \*/
	std::string m_sTestName;/*\ test类名称 \*/
};

int main(int argc, char *argv[])
{
	CTest* test = new CTest(1, "测试类");
	test->virlSetId(10);
	test->virlSetName("抽象类");
	test->Print();
	system("pause");
	return 0;
}