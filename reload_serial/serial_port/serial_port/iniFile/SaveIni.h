

/**************************************************************
 * @file SaveIni.h										  
 * @date 2019/05/09 11:16		
 * @commpany �����������޹�˾ 
 * @author Jinzi                                              
 * @Contact: 2493349541@qq.com							      
 * @brief ���ļ��ǳ�ʼ�������ļ��������ݴ洢���ڴ浱��				  
***************************************************************/
#pragma once
#ifndef _SAVEINIFILE_H_
#define _SAVEINIFILE_H_

#ifndef _INIFILE_H_
#include "./iniFile.h"
#endif

#ifndef _BOOL_H_
#include "../utils/bool.h"
#endif

#ifndef _STDLIB_H
#include <stdlib.h>
#endif

/*\ ���������ļ��еı���[$end] \*/
#define INTERCHANGER		"INTERCHANGER"		/*\ ������������Ϣ \*/
#define DEV8021X			"DEV8021X"			/*\ ����802.1x���豸���� \*/

/*\ �����洢�˿ھ��������ļ�����Ϣ \*/
typedef struct  
{
	char chMainPort[64];		/*\ �������˿ڣ�eth0/1�������ͣ� \*/
	char chCpuPort[64];			/*\ ������ӳ��Ķ˿� �����н��յ����ݸ��Ƶ�cpu�˿��� \*/
	char chSessDes[64];			/*\ �����Ự��˵�� \*/
}SAVEINI,*PSAVEINI;

/*\ �����洢802.1x������Ϣ \*/
typedef struct  
{
	char chIp[64];				/*\ redius��������ip��ַ \*/
	char chPort[32];			/*\ �˿� \*/
	char chKey[128];			/*\ ϵͳ��redius��������������ʱ��Ĺ�����Կ \*/	
}INI8021X,*PINI8021X;

///////////////////// BEGIN���������ļ���ȫ�ֱ��� /////////////////////////////////////////////////////
PSAVEINI					gl_pIniPortMirror;	/*\ �洢�˿ھ����������Ϣ \*/
PINI8021X					gl_pIni8021X;		/*\ �洢802.1x��������Ϣ \*/

///////////////////// END���������ļ���ȫ�ֱ��� /////////////////////////////////////////////////////

 /****************************************!
 *@brief  ��ʼ�������ļ� �������ļ��е����ݴ洢���ڴ���
 *@author Jinzi
 *@date   2019/05/09 11:22:09
 *@param[in]  _FileName �����ļ���·��-�ļ���
			  _SaveIni �洢�������ļ��Ľṹ��
 *@param[out] 
 *@return     �ɹ�����true ʧ�ܷ���false
 ****************************************/
int InitIniFile(const char* _FileName);
 /****************************************!
 *@brief  �ͷŴ洢�������ļ�����Ϣ
 *@author Jinzi
 *@date   2019/05/09 15:51:58
 *@param[in]  
 *@param[out] 
 *@return     
 ****************************************/
void DestroyIniFile();
#endif