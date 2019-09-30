#pragma once
#ifndef _LOGIN_ETC_H_
#define _LOGIN_ETC_H_

#ifndef _BOOL_H_
#include "../utils/bool.h"
#endif

#ifndef _SAVEINIFILE_H_
#include "../iniFile/SaveIni.h"
#endif

/*\ 配置交换机的步骤命令 \*/
typedef enum CMD
{
	INTERCHANGER_NONE   = -1,		//相当于恢复默认
	INTERCHANGER_ONE    = 1,		//第一步进入特权模式      （用户模式下操作）
	INTERCHANGER_TWO    = 2,		//第二步进入全局模式      （特权模式下操作）
	INTERCHANGER_THREE  = 3,		//第三步注册会话	      （全局模式下操作）
	INTERCHANGER_FOUR   = 4,		//第四步设置会话的说明    （全局模式下操作）
	INTERCHANGER_FIVE   = 5,		//第五步配置会话源端口    （全局模式下操作）
	INTERCHANGER_SIX    = 6,		//第六步配置会话目的端口  （全局模式下操作）
	INTERCHANGER_SIX_1	= 600001,	//第六部中的第一步退出到全局模式
	INTERCHANGER_SEVEN  = 7,		//第七步开启802.1x认证	  （全局模式下操作）
	INTERCHANGER_EIGHT  = 8,		//第八步配置端口		  （全局模式下操作）
	INTERCHANGER_NINE   = 9,		//第九步开启端口		  （接口模式下操作）
	INTERCHANGER_TEN    = 10,	    //第十步退出到全局模式	  （接口模式下操作）
	INTERCHANGER_ELEVEN = 11,	    //第十一步配置redius服务器（全局模式下操作）
	INTERCHANGER_TWELVE = 12,		//第十二步
}InterChangerCMD;

/*\ 用来标识状态 \*/
typedef enum
{
	CMDSTATUS_NONE		= -1,		// 默认状态下
	CMDSTATUS_INIT		= 0,		// 交换机加载中 
	CMDSTATUS_USER		= 1,		// 输入用户名状态 
	CMDSTATUS_PASS		= 2,		// 输入密码状态
	CMDSTATUS_USERMODE	= 3,		// 用户模式状态
	CMDSTATUS_PRIMODE	= 4,		// 特权模式状态
	CMDSTATUS_GLBMODE	= 5,		// 全局模式状态
	CMDSTATUS_INTERMODE = 6,		// 接口模式状态
	CMDSTATUS_CONPORT   = 7,			// 配置端口状态
	CMSTSATUS_YES		= 8
}CMDSTATUS;

/****************************************!
*@brief  判断字符操作，用来判断交换机是否加载成功，然后登陆
*@author Jinzi
*@date   2019/05/08 8:40:19
*@param[in]  _Fd 串口句柄
			 _InterChanger 存储的配置交换机的信息
			 _Ini8021x 存储配置8021x的信息
*@param[out]
*@return
****************************************/
void JuageStrOpt(int _Fd, PSAVEINI _InterChanger, PINI8021X _Ini8021x);
/****************************************!
*@brief  在命令行特权模式下操作的所有命令
*@author Jinzi
*@date   2019/05/09 17:44:42
*@param[in]  _Fd 串口句柄
			 _InterChanger 存储的配置文件中的交换机信息
			 _Ini8021x	存储配置8021x的信息
*@param[out]
*@return
****************************************/
void OperPriModeCMD(int _Fd, PSAVEINI _InterChanger, PINI8021X _Ini8021x);
/****************************************!
*@brief  在命令行全局模式下操作的所有命令
*@author Jinzi
*@date   2019/05/09 17:44:42
*@param[in]  _Fd 串口句柄
			 _InterChanger 存储的配置文件中的交换机信息
			 _Ini8021x	存储配置8021x的信息
*@param[out]
*@return
****************************************/
void OperGlobModeCMD(int _Fd, PSAVEINI _InterChanger, PINI8021X _Ini8021x);
/****************************************!
*@brief  在命令行用户模式下操作的所有命令(SWITCH>)
*@author Jinzi
*@date   2019/05/09 17:44:42
*@param[in]  _Fd 串口句柄
*@param[out]
*@return
****************************************/
void OperUserModeCMD(int _Fd);
 /****************************************!
 *@brief  模拟用户登录（输入账号）
 *@author Jinzi
 *@date   2019/05/09 17:56:46
 *@param[in]  _Fd 串口句柄
			  _UserName 用户名
 *@param[out] 
 *@return     
 ****************************************/
void UserLogin(int _Fd, const char* _UserName);
 /****************************************!
 *@brief  模拟用户输入密码
 *@author Jinzi
 *@date   2019/05/10 8:23:33
 *@param[in]  _Fd 串口句柄
			  _PassWord 用户密码
 *@param[out] 
 *@return     
 ****************************************/
void UserPass(int _Fd, const char* _PassWord);
/****************************************!
*@brief  用来发送指令
*@author Jinzi
*@date   2019/05/10 8:41:14
*@param[in]  _Fd 串口句柄
			 _Type 用来设置_OptStat的步骤信息 （#InterChangerCMD）
			 _Cmd 发送的指令
*@param[out]
*@return
****************************************/
void SendCMD(int _Fd, InterChangerCMD _Type, char* _Cmd);
/****************************************!
*@brief  在命令行接口模式下操作的所有命令
*@author Jinzi
*@date   2019/05/09 17:44:42
*@param[in]  _Fd 串口句柄
			 _OptStat 操作状态
			 _InterChanger 存储的配置文件中的交换机信息
			 _Ini8021x	存储配置8021x的信息
*@param[out]
*@return
****************************************/
void OperInterModeCMD(int _Fd, PSAVEINI _InterChanger, PINI8021X _Ini8021x);
 /****************************************!
 *@brief  说明交换机正在初始化数据
 *@author Jinzi
 *@date   2019/05/10 11:10:04
 *@param[in]  _Fd就是串口句柄
 *@param[out] 
 *@return     
 ****************************************/
void InterChangeInitData(int _Fd);
/****************************************!
*@brief  在命令行接口模式下操作的所有命令
*@author Jinzi
*@date   2019/05/09 17:44:42
*@param[in]  _Fd 串口句柄
			 _OptStat 操作状态
			 _InterChanger 存储的配置文件中的交换机信息
			 _Ini8021x	存储配置8021x的信息
*@param[out]
*@return
****************************************/
void OperPortModeCMD(int _Fd, PSAVEINI _InterChanger, PINI8021X _Ini8021x);
#endif
