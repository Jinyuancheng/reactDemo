#pragma once
#ifndef _JINZIUTILS_H_
#define _JINZIUTILS_H_

#ifndef _IOSTREAM_
#include <iostream>
using namespace std;
#endif

#ifndef _VECTOR_
#include <vector>
#endif

#ifndef _STRING_
#include <string>
#endif
class JinziUtils
{
public:
	JinziUtils();
	~JinziUtils();
public:
	/*\ �õ�һ��������ĵ��ö��� \*/
	static JinziUtils* GetInstance();
	/*\ ɾ��������Ķ��� \*/
	static void DelInstance();
public:
	/*\ ������stringת��Ϊconst char* \*/	
	char* UtilsStringToConstChar(std::string Str);
	/*\ ������const char* ת��Ϊstring \*/
	std::string UtilsConstCharToString(const char* Str);
	/*\ ������Url��username=jinzi&password=111111����ʽ����&�и� \*/
	std::vector<std::string> UtilsUrlToSerialize(std::string Str);
	/*\ ����������ָ�������ݶ�Ӧ��ֵ���ػ��� \*/
	std::string UtilsStringWithInString(std::vector<std::string> VecStr, std::string Str);
private:
	static JinziUtils*			m_Instance;				/*\ ���ö��� \*/
}; 


#endif


