#pragma once
#ifndef _JINZI_UTILS_H_
#define _JINZI_UTILS_H_

#ifndef _STDIO_H
#include <stdio.h>
#endif 
#ifndef _STRING_H
#include <string.h>
#endif
#ifndef	 _BOOL_H_
#include "../utils/bool.h"
#endif
#ifndef _STDBOOL
#include <stdbool.h>
#endif
 /****************************************!
 *@brief  在字符串中删除指定的字符
 *@author Jinzi
 *@date   2019/05/20 10:11:35
 *@param[in]  _DesStrData 源字符串
			  _DelStr 要删除的字符
 *@param[out] 
 *@return     返回删除指定字符后的字符串
 ****************************************/
char* DelStrInChar(char* _DesStrData, char _DelStr);
 /****************************************!
 *@brief  判断字符串中是否存在某个字符
 *@author Jinzi
 *@date   2019/05/20 12:42:11
 *@param[in]  _DesStrData 源字符串
			  _DelStr 要删除的字符
 *@param[out] 
 *@return     存在返回true 不存在返回false
 ****************************************/
int JuageStrinCharExit(char* _DesStrData, char _DelStr);
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
char* Split(char* _DesStrData, const char* _DelStr, char** _SaveStr);


#endif