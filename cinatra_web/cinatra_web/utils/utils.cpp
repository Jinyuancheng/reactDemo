#ifndef _JINZIUTILS_H_
#include "./utils.h"
#endif

#include <stdio.h>
#include <string.h>

 /****************************************!
 *@brief  �õ�һ��������ĵ��ö���
 *@author Jinzi
 *@date   2019/04/18 17:04:02
 *@param[in]  
 *@param[out] 
 *@return     ����һ��JinziUtils��Ķ����ָ��
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
 *@brief  ���new�����Ķ���
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
 *@brief  ������string���͵�����ת��Ϊchar*����
 *@author Jinzi
 *@date   2019/04/18 17:07:26
 *@param[in]  
 *@param[out] 
 *@return     ����ת���������
 ****************************************/
void JinziUtils::UtilsStringToConstChar(std::string Str, char* chData)
{
	const int len = Str.length();
	chData = new char[len + 1];
	strcpy(chData, Str.c_str());
	//strcpy_s(iSendData, sizeof(iSendData), Str.c_str());
}
/****************************************!
*@brief  ������const char* ת��Ϊstring
*@author Jinzi
*@date   2019/03/21 9:55:28
*@param[in]  Str ����׼��Ϊstring���� ��һ���ַ���ָ��
*@param[out]
*@return	����׼������ַ���
****************************************/
std::string JinziUtils::UtilsConstCharToString(const char* Str)
{
	std::string str(Str);
	return str;
}
 /****************************************!
 *@brief  ������url��ʽ����&�и�
 *@author Jinzi
 *@date   2019/04/18 17:24:33
 *@param[in]  StrҪ�и���ַ���
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
 *@brief  ���������ָ�����ַ����������ַ�����Ӧ�����ݷ��ػ���
 *@author Jinzi
 *@date   2019/04/18 17:46:18
 *@param[in]  VecStr�洢��Ӧ���ݵ�һ��vector���ϣ�Str���ݸ��ַ������в��ҷ���
 *@param[out] 
 *@return     ���ҵ��Ľ�������û�з���NULL
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