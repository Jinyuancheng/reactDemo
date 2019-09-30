#ifndef _JINZI_UTILS_H_
#include "./jinzi_utils.h"
#endif // !_JINZI_UTILS_H_
/****************************************!
*@brief  在字符串中删除指定的字符
*@author Jinzi
*@date   2019/05/20 10:11:35
*@param[in]  _DesStrData 源字符串
			 _DelStr 要删除的字符
*@param[out]
*@return     返回删除指定字符后的字符串
****************************************/
char* DelStrInChar(char* _DesStrData, char _DelStr)
{
	int i, j;
	char data[4096] = { 0 };
	strcpy(data, _DesStrData);
	for (i = 0, j = 0; data[i] != '\0'; i++) {
		if (data[i] != _DelStr)
		{
			data[j++] = data[i];
		}
	}
	data[j] = '\0';
	return data;
}
/****************************************!
*@brief  判断字符串中是否存在某个字符
*@author Jinzi
*@date   2019/05/20 12:42:11
*@param[in]  _DesStrData 源字符串
			 _DelStr 要删除的字符
*@param[out]
*@return     存在返回true 不存在返回false
****************************************/
int JuageStrinCharExit(char* _DesStrData, char _DelStr)
{
	while (*_DesStrData != '\0')
	{
		if (*_DesStrData == _DelStr)
		{
			return true;
		}
	}
	return false;
}
/****************************************!
*@brief  根据指定字符进行字符串的切割
*@author Jinzi
*@date   2019/05/20 15:17:44
*@param[in] _DesStrData 要进行切割的字符串
			_DelStr 根据该字符进行切割
			_SaveStr 存储切割后的数据
*@param[out]
*@return     返回切割后的数组
****************************************/
char* Split(char* _DesStrData, const char* _DelStr, char** _SaveStr)
{
	char * pch;
	//printf("Splitting string \"%s\" into tokens:\n", str);
	pch = strtok(_DesStrData, _DelStr);
	while (pch != NULL)
	{
		*_SaveStr = pch;
		_SaveStr++;
		pch = strtok(NULL, _DelStr);
	}
}
