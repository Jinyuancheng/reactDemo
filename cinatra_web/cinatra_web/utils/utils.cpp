#ifndef _JINZIUTILS_H_
#include "./utils.h"
#endif

#include <stdio.h>
#include <string.h>

 /****************************************!
 *@brief  得到一个工具类的调用对象
 *@author Jinzi
 *@date   2019/04/18 17:04:02
 *@param[in]  
 *@param[out] 
 *@return     返回一个JinziUtils类的对象的指针
 ****************************************/
JinziUtils* JinziUtils::GetInstance()
{
	if (m_Instance == NULL)
	{
		m_Instance = new JinziUtils();
	}
	return m_Instance;
}
 /****************************************!
 *@brief  清空new出来的对象
 *@author Jinzi
 *@date   2019/04/18 17:04:27
 *@param[in]  
 *@param[out] 
 *@return     
 ****************************************/
void JinziUtils::DelInstance()
{
	if (m_Instance != NULL)
	{
		delete[] m_Instance;
		m_Instance = NULL;
	}
}
 /****************************************!
 *@brief  用来将string类型的数据转换为char*类型
 *@author Jinzi
 *@date   2019/04/18 17:07:26
 *@param[in]  
 *@param[out] 
 *@return     返回转换后的数据
 ****************************************/
void JinziUtils::UtilsStringToConstChar(std::string Str, char* chData)
{
	const int len = Str.length();
	chData = new char[len + 1];
	strcpy(chData, Str.c_str());
	//strcpy_s(iSendData, sizeof(iSendData), Str.c_str());
}
/****************************************!
*@brief  用来将const char* 转换为string
*@author Jinzi
*@date   2019/03/21 9:55:28
*@param[in]  Str 用来准换为string类型 的一个字符串指针
*@param[out]
*@return	返回准换后的字符串
****************************************/
std::string JinziUtils::UtilsConstCharToString(const char* Str)
{
	std::string str(Str);
	return str;
}
 /****************************************!
 *@brief  用来将url格式按照&切割
 *@author Jinzi
 *@date   2019/04/18 17:24:33
 *@param[in]  Str要切割的字符串
 *@param[out] 
 *@return     
 ****************************************/
std::vector<std::string> JinziUtils::UtilsUrlToSerialize(std::string Str)
{
	std::vector<std::string> vecStr;
	char arr[100] = { 0 };
	int i = 0;
	int z = 0;
	for (std::string::iterator pStr = Str.begin(); pStr != Str.end(); pStr++)
	{
		z++;
		if (*pStr != '&')
		{
			arr[i] = *pStr;
			i++;
		}
		if (*pStr == '&')
		{
			i = 0;
			std::string strData_1 = JinziUtils::GetInstance()->UtilsConstCharToString(arr);
			vecStr.push_back(strData_1);
			memset(arr, 0, sizeof(arr));
		}
		if (z == Str.length())
		{
			int iIndex = Str.find_last_of("&");
			string strData_2 = Str.substr(iIndex + 1, Str.length());
			vecStr.push_back(strData_2);
		}
	}
	return vecStr;
}
 /****************************************!
 *@brief  根据输入的指定的字符串，将该字符串对应的数据返回回来
 *@author Jinzi
 *@date   2019/04/18 17:46:18
 *@param[in]  VecStr存储对应数据的一个vector集合，Str根据该字符串进行查找返回
 *@param[out] 
 *@return     查找到的结果，如果没有返回NULL
 ****************************************/
std::string JinziUtils::UtilsStringWithInString(std::vector<std::string> VecStr, std::string Str)
{
	std::vector<std::string>::iterator pVecStr = VecStr.begin();
	std::string strRet;
	int i = 0;
	for (pVecStr; pVecStr != VecStr.end(); pVecStr++)
	{
		i++;
		int iRes = (*pVecStr).find(Str);
		if (iRes < 0)
		{
			continue;
		}
		else
		{
			int iRes = (*pVecStr).find_last_of('=');
			strRet = (*pVecStr).substr(iRes + 1, (*pVecStr).length());
			break;
		}
		if (i == VecStr.size())
		{
			i = 0;
			strRet = nullptr;
			break;
		}
	}
	return strRet;
}

JinziUtils* JinziUtils::m_Instance = NULL;