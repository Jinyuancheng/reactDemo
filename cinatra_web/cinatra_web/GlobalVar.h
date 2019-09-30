#pragma once
#ifndef _GLOBALVAR_H_
#define _GLOBALVAR_H_
#include <iostream>

/*\ �洢�����ļ��е����� \*/
typedef struct
{
	std::string		sMainPort;	/*\ �������������˿� \*/
	std::string		sUserPort;	/*\ �û������������˿� \*/
	std::string		sMangePort;	/*\ ��������������˿� \*/
	std::string		sMysqlIp;	/*\ ���ݿ�ip \*/
	std::string		sMysqlUser;	/*\ ���ݿ��¼�û��� \*/
	std::string		sMysqlPass;	/*\ ���ݿ��¼���� \*/
	std::string		sMysqlDB;	/*\ ���ݿ����� \*/
}SaveIniFile, *pSaveIniFile;

pSaveIniFile	gl_SaveIniFile;		/*\ ȫ�ֵĴ洢�����ļ���Ϣ \*/

/*\ ��ʼ���øýṹ�� \*/
void InitSaveIniFileData()
{
	gl_SaveIniFile = new SaveIniFile();
}
/*\ �ͷŸýṹ�� \*/
void FreeSaveIniFileData()
{
	delete[] gl_SaveIniFile;
}
#endif