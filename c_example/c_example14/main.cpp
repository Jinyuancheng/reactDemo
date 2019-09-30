/**************************************************************
 * @file main.cpp										  
 * @date 2019/08/15 11:02		
 * @author Jinzi                                              
 * @Contact: 2493349541@qq.com							      
 * @brief 	利用条件运算符的嵌套来完成此题：学习成绩>=90分的同学用A表示，60-89分之间的用B表示，60分以下的用C表示。			  
***************************************************************/
#include <iostream>
using namespace std;

class Student
{
public:
	Student(int _iId, int _iGarde) :
		m_iId(_iId), m_iGarde(_iGarde) {}
public:
	int m_iId;
	int m_iGarde;
};

int main(int argc,char *argv[])
{
	Student A1(1, 55);

	std::string sRet = (A1.m_iGarde > 90) ? "A" :(A1.m_iGarde > 60 && A1.m_iGarde < 89?"B":"C");

	std::cout << "sRet : " << sRet.c_str() << endl;

	system("pause");
	return 0;
}