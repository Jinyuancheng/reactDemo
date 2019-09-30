#pragma once
#ifndef _INIFILE_H_
#define _INIFILE_H_

#include <stdio.h>  
#include <string.h>

/****************************************!
*@brief  �õ������ļ��е�ָ��key��Ӧ��ֵ
*@author Jinzi
*@date   2019/05/09 10:07:02
*@param[in]  title �����ļ���һ�����ݵı�ʶ
			 key ����������ҩ������ֵ�ı�ʶ
			 filename Ҫ��ȡ���ļ�·��
			 buf �洢��keyֵ��Ӧ������
*@param[out]
*@return     �ɹ�����0 ʧ�ܷ���-1
****************************************/
int GetIniKeyString(const char *title,const char *key,const char *filename,const char *buf);
/****************************************!
*@brief  �������ļ���д������
*@author Jinzi
*@date   2019/05/09 10:09:43
*@param[in]  title �����ļ���һ�����ݵı�ʶ
			 key ���������е�key
			 val �޸ĺ��ֵ
			 filename �ļ�·��
*@param[out]
*@return     ʧ�ܷ��� -1
****************************************/
int PutIniKeyString(const char *title,const char *key,const char *val,const char *filename);

#endif
