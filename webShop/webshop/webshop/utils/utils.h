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
	/*\ 得到一个工具类的调用对象 \*/
	static JinziUtils* GetInstance();
	/*\ 删除工具类的对象 \*/
	static void DelInstance();
public:
	/*\ 用来将string转换为const char* \*/	
	char* UtilsStringToConstChar(std::string Str);
	/*\ 用来将const char* 转换为string \*/
	std::string UtilsConstCharToString(const char* Str);
	/*\ 用来将Url（username=jinzi&password=111111）格式按照&切割 \*/
	std::vector<std::string> UtilsUrlToSerialize(std::string Str);
	/*\ 用来将数据指定的数据对应的值返回回来 \*/
	std::string UtilsStringWithInString(std::vector<std::string> VecStr, std::string Str);
private:
	static JinziUtils*			m_Instance;				/*\ 调用对象 \*/
}; 


#endif


