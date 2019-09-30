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
 *@brief  ���ַ�����ɾ��ָ�����ַ�
 *@author Jinzi
 *@date   2019/05/20 10:11:35
 *@param[in]  _DesStrData Դ�ַ���
			  _DelStr Ҫɾ�����ַ�
 *@param[out] 
 *@return     ����ɾ��ָ���ַ�����ַ���
 ****************************************/
char* DelStrInChar(char* _DesStrData, char _DelStr);
 /****************************************!
 *@brief  �ж��ַ������Ƿ����ĳ���ַ�
 *@author Jinzi
 *@date   2019/05/20 12:42:11
 *@param[in]  _DesStrData Դ�ַ���
			  _DelStr Ҫɾ�����ַ�
 *@param[out] 
 *@return     ���ڷ���true �����ڷ���false
 ****************************************/
int JuageStrinCharExit(char* _DesStrData, char _DelStr);
 /****************************************!
 *@brief  ����ָ���ַ������ַ������и�
 *@author Jinzi
 *@date   2019/05/20 15:17:44
 *@param[in] _DesStrData Ҫ�����и���ַ���
			 _DelStr ���ݸ��ַ������и�
			 _SaveStr �洢�и�������
 *@param[out] 
 *@return     �����и�������
 ****************************************/
char* Split(char* _DesStrData, const char* _DelStr, char** _SaveStr);


#endif