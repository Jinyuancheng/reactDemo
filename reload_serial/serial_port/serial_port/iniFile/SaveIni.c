
/**************************************************************
 * @file SaveIni.c										  
 * @date 2019/05/09 11:30		
 * @commpany �����������޹�˾ 
 * @author Jinzi                                              
 * @Contact: 2493349541@qq.com							      
 * @brief ������SaveIni.h�еĺ�������ʵ��				  
***************************************************************/
#ifndef _SAVEINIFILE_H_
#include "./SaveIni.h"
#endif

/****************************************!
*@brief  ��ʼ�������ļ� �������ļ��е����ݴ洢���ڴ���
*@author Jinzi
*@date   2019/05/09 11:22:09
*@param[in]  _FileName �����ļ���·��-�ļ���
			 _SaveIni �洢�������ļ��Ľṹ��
*@param[out]
*@return     �ɹ�����true ʧ�ܷ���false
****************************************/
int InitIniFile(const char* _FileName)
{
	SAVEINI objIniVarName;
	INI8021X objIni8021x;
	gl_pIniPortMirror = (PSAVEINI)malloc(sizeof(SAVEINI));
	gl_pIni8021X = (PINI8021X)malloc(sizeof(INI8021X));
	memset(&objIniVarName, 0, sizeof(SAVEINI));
	memset(&objIni8021x, 0, sizeof(INI8021X));
	/*\ �˿ھ��� \*/
	strcpy(objIniVarName.chMainPort, "MainPort");
	strcpy(objIniVarName.chCpuPort, "CpuPort");
	strcpy(objIniVarName.chSessDes, "SessDes");
	/*\ 802.1x ,\*/
	strcpy(objIni8021x.chIp, "Ip");
	strcpy(objIni8021x.chPort, "Port");
	strcpy(objIni8021x.chKey, "Key");

	/*\ ��ʼ������ \*/
	if (GetIniKeyString(INTERCHANGER, objIniVarName.chMainPort, _FileName, gl_pIniPortMirror->chMainPort) < 0)
	{
		printf("InitIniFile==>GetIniKeyString==>MainPort Error\n");
		return false;
	}
	if (GetIniKeyString(INTERCHANGER, objIniVarName.chCpuPort, _FileName, gl_pIniPortMirror->chCpuPort) < 0)
	{
		printf("InitIniFile==>GetIniKeyString==>MainPort Error\n");
		return false;
	}
	if (GetIniKeyString(INTERCHANGER, objIniVarName.chSessDes, _FileName, gl_pIniPortMirror->chSessDes) < 0)
	{
		printf("InitIniFile==>GetIniKeyString==>MainPort Error\n");
		return false;
	}
	/*if (GetIniKeyString(DEV8021X, objIni8021x.chIp, _FileName, gl_pIni8021X->chIp) < 0)
	{
		printf("InitIniFile==>GetIniKeyString==>Ip Error\n");
		return false;
	}
	if (GetIniKeyString(DEV8021X, objIni8021x.chPort, _FileName, gl_pIni8021X->chPort) < 0)
	{
		printf("InitIniFile==>GetIniKeyString==>Port Error\n");
		return false;
	}
	if (GetIniKeyString(DEV8021X, objIni8021x.chKey, _FileName, gl_pIni8021X->chKey) < 0)
	{
		printf("InitIniFile==>GetIniKeyString==>Key Error\n");
		return false;
	}*/

	return true;
}

/****************************************!
*@brief  �ͷŴ洢�������ļ�����Ϣ
*@author Jinzi
*@date   2019/05/09 15:51:58
*@param[in]
*@param[out]
*@return
****************************************/
void DestroyIniFile()
{
	free(gl_pIniPortMirror);
	free(gl_pIni8021X);
}