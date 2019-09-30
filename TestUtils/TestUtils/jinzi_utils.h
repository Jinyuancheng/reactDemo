#pragma once
#ifndef _JINZI_UTILS_H_
#define _JINZI_UTILS_H_

#ifndef _STDIO_H
#include <stdio.h>
#endif
typedef char* CHAR;
typedef struct
{
	char str1[8];
	char str2[8];
	char str3[8];
	char str4[8];
}IP,*PIP;
/****************************************!
*@brief  在字符串中删除指定的字符
*@author Jinzi
*@date   2019/05/20 10:11:35
*@param[in]  _DesStrData 源字符串
			 _DelStr 要删除的字符
*@param[out]
*@return
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
	printf("结果啊 : %s\n",data);
	return data;
}

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

#endif