/**************************************************************
 * @file main.cpp										  
 * @date 2019/08/15 11:02		
 * @author Jinzi                                              
 * @Contact: 2493349541@qq.com							      
 * @brief 	���������������Ƕ������ɴ��⣺ѧϰ�ɼ�>=90�ֵ�ͬѧ��A��ʾ��60-89��֮�����B��ʾ��60�����µ���C��ʾ��			  
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