#pragma once
#ifndef _GLOBALVAR_H_
#define _GLOBALVAR_H_
#include <iostream>

/*\ 存储配置文件中的数据 \*/
typedef struct
{
	std::string		sMainPort;	/*\ 主服务器监听端口 \*/
	std::string		sUserPort;	/*\ 用户服务器监听端口 \*/
	std::string		sMangePort;	/*\ 管理服务器监听端口 \*/
	std::string		sMysqlIp;	/*\ 数据库ip \*/
	std::string		sMysqlUser;	/*\ 数据库登录用户名 \*/
	std::string		sMysqlPass;	/*\ 数据库登录密码 \*/
	std::string		sMysqlDB;	/*\ 数据库名称 \*/
}SaveIniFile, *pSaveIniFile;

pSaveIniFile	gl_SaveIniFile;		/*\ 全局的存储配置文件信息 \*/

/*\ 初始化该该结构体 \*/
void InitSaveIniFileData()
{
	gl_SaveIniFile = new SaveIniFile();
}
/*\ 释放该结构体 \*/
void FreeSaveIniFileData()
{
	delete[] gl_SaveIniFile;
}
#endif