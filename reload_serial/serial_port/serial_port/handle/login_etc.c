
#include "./login_etc.h"
#include <stdlib.h>
#ifndef __SERIAL_H__
#include "../serial/serial.h"
#endif

/*\ 用来操作指令的步骤 \*/
InterChangerCMD uiOptCMD = INTERCHANGER_ONE;	//进入到特权模式
/*\ 指令的状态 \*/
CMDSTATUS uiCmdStatus = CMDSTATUS_NONE;			//初始化模式
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
void JuageStrOpt(int _Fd, PSAVEINI _InterChanger, PINI8021X _Ini8021x)
{
	/*\ 用来接收数据 \*/
	char _Buf[10240];
	serial_send(_Fd, "\n", 1);
	/*\ 接收数据 \*/
	while (1)
	{
		memset(_Buf, 0, sizeof(_Buf));
		int iLen = serial_receive(_Fd, _Buf, sizeof(_Buf), 10);
		printf("%s", _Buf);
		if (iLen > 0)
		{
			if (strstr(_Buf, "U-Boot") != NULL)
			{
				uiCmdStatus = CMDSTATUS_INIT;
				printf("%s\n", _Buf);
				continue;
			}
			/*\ 配置端口镜像 \*/
			else if (strstr(_Buf, "SWITCH(config-monitor)#") != NULL)
			{
				uiCmdStatus = CMDSTATUS_CONPORT;
				printf("%s\n", _Buf);
				continue;
			}
			/*\ 接口模式下 \*/
			else if (strstr(_Buf, "SWITCH(config-if)#") != NULL)
			{
				uiCmdStatus = CMDSTATUS_INTERMODE;
				printf("%s\n", _Buf);
				continue;
			}
			/*\ 全局模式 \*/
			else if (strstr(_Buf, "SWITCH(config)#") != NULL)
			{
				uiCmdStatus = CMDSTATUS_GLBMODE;
				continue;
			}
			/*\ 特权模式 \*/
			else if (strstr(_Buf, "SWITCH#") != NULL)
			{
				uiCmdStatus = CMDSTATUS_PRIMODE;
				printf("%s\n", _Buf);
				continue;
			}
			/*\ 用户模式 \*/
			else if (strstr(_Buf, "SWITCH>") != NULL)
			{
				uiCmdStatus = CMDSTATUS_USERMODE;
				printf("%s\n", _Buf);
				continue;
			}
			else if (strstr(_Buf, "Password:") != NULL)
			{
				uiCmdStatus = CMDSTATUS_PASS;
				printf("%s\n", _Buf);
				continue;
			}
			else if (strstr(_Buf, "SWITCH login:") != NULL)
			{
				uiCmdStatus = CMDSTATUS_USER;
				printf("%s\n", _Buf);
				continue;
			}
			else if (strstr(_Buf, "Please answer 'y' or 'n'") != NULL)
			{
				uiCmdStatus = CMSTSATUS_YES;
				printf("%s\n", _Buf);
				continue;
			}
		}
		else
		{
			/*\ 根据指令状态进行不同的操作 \*/
			switch (uiCmdStatus)
			{
				/*\ 说明交换机正在加载数据 \*/
			case CMDSTATUS_INIT:
				InterChangeInitData(_Fd);
				break;
				/*\ 用户登录 \*/
			case CMDSTATUS_USER:
				UserLogin(_Fd, "admin\n");
				break;
				/*\ 模拟输入用户密码 \*/
			case CMDSTATUS_PASS:
				UserPass(_Fd, "admin\n");
				break;
				/*\ 用户模式下 \*/
			case CMDSTATUS_USERMODE:
				OperUserModeCMD(_Fd);
				/*\ 当前是在特权模式下 \*/
			case CMDSTATUS_PRIMODE:
				OperPriModeCMD(_Fd, _InterChanger, _Ini8021x);
				break;
				/*\ 当前是在全局模式下 \*/
			case CMDSTATUS_GLBMODE:
				OperGlobModeCMD(_Fd, _InterChanger, _Ini8021x);
				break;
				/*\ 当前是在接口模式下 \*/
			case CMDSTATUS_INTERMODE:
				OperInterModeCMD(_Fd, _InterChanger, _Ini8021x);
				/*\ 配置端口镜像模式下 SWITCH(config-monitor)# \*/
			case CMDSTATUS_CONPORT:
				OperPortModeCMD(_Fd, _InterChanger, _Ini8021x);
				break;
			case CMSTSATUS_YES:
				serial_send(_Fd, "y\n", 2);
				break;
			default:
				break;
			}
		}
	}
}

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
void OperPortModeCMD(int _Fd, PSAVEINI _InterChanger, PINI8021X _Ini8021x)
{
	char chBuf[4096];
	switch (uiOptCMD)
	{
	case INTERCHANGER_FOUR: /*\ 设置会话的说明 \*/
		memset(chBuf, 0, sizeof(chBuf));
		sprintf(chBuf, "description %s\n", _InterChanger->chSessDes);
		SendCMD(_Fd, INTERCHANGER_FIVE, chBuf);
		break;
	case INTERCHANGER_FIVE: /*\ 配置会话源端口 source interface %s rx\*/
		memset(chBuf, 0, sizeof(chBuf));
		sprintf(chBuf, "source interface %s rx\n", _InterChanger->chMainPort);
		SendCMD(_Fd, INTERCHANGER_SIX, chBuf);
		break;
	case INTERCHANGER_SIX: /*\ 配置会话目的端口 destination interface %s \*/
		memset(chBuf, 0, sizeof(chBuf));
		sprintf(chBuf, "destination interface %s\n", _InterChanger->chCpuPort);
		SendCMD(_Fd, INTERCHANGER_SIX_1, chBuf);
		break;
	case INTERCHANGER_SIX_1: /*\ 退出到全局模式 \*/
		SendCMD(_Fd, INTERCHANGER_SEVEN, "exit\n");
		break;
	default:
		break;
	}
}

/****************************************!
*@brief  模拟用户登录
*@author Jinzi
*@date   2019/05/09 17:56:46
*@param[in]  _Fd 串口句柄
			 _UserName (格式 ： admin\n)
*@param[out]
*@return
****************************************/
void UserLogin(int _Fd, const char* _UserName)
{
	char chBuf[1024];
	int iSendLen = -1;
	memset(chBuf, 0, sizeof(chBuf));
	strcpy(chBuf, _UserName);
	/*\ 成功返回发送数据的长度 失败返回-1 \*/
	iSendLen = serial_send(_Fd, chBuf, strlen(chBuf));
	if (iSendLen > 0)
	{
		iSendLen = -1;
	}
	else
	{
		printf("Send Login UserName Error\n");
	}
}

/****************************************!
*@brief  模拟用户输入密码
*@author Jinzi
*@date   2019/05/10 8:23:33
*@param[in]  _Fd 串口句柄
			 _PassWord 用户密码 (格式 ： admin\n)
*@param[out]
*@return
****************************************/
void UserPass(int _Fd, const char* _PassWord)
{
	char chBuf[1024];
	int iSendLen = -1;
	memset(chBuf, 0, sizeof(chBuf));
	strcpy(chBuf, _PassWord);
	iSendLen = serial_send(_Fd, chBuf, strlen(chBuf));
	if (iSendLen > 0)
	{
		iSendLen = -1;
	}
	else
	{
		printf("Send Login PassWord Error\n");
	}
}

/****************************************!
*@brief  在命令行特权模式下操作的所有命令
*@author Jinzi
*@date   2019/05/09 17:44:42
*@param[in]  _Fd 串口句柄
			 _OptStat 操作状态
			 _InterChanger 存储的配置文件中的交换机信息
			 _Ini8021x	存储配置8021x的信息
*@param[out]
*@return
****************************************/
void OperPriModeCMD(int _Fd, PSAVEINI _InterChanger, PINI8021X _Ini8021x)
{
	char chBuf[1024];
	printf("Exec \n");
	memset(chBuf, 0, sizeof(chBuf));
	strcpy(chBuf, "reload\n");		//重新启动交换机
	//strcpy(chBuf, "show users\n");
	SendCMD(_Fd, INTERCHANGER_NONE, chBuf);
	usleep(1000000);
	memset(chBuf, 0, sizeof(chBuf));
	strcpy(chBuf, "y\n");		//重新启动交换机
	//strcpy(chBuf, "show users\n");
	SendCMD(_Fd, INTERCHANGER_NONE, chBuf);
}

/****************************************!
*@brief  用来发送指令
*@author Jinzi
*@date   2019/05/10 8:41:14
*@param[in]  _Fd 串口句柄
			 _OptStat 操作状态 用来标识走到了第几步
			 _Type 用来设置_OptStat的步骤信息 （#InterChangerCMD）
			 _Cmd 发送的指令
*@param[out]
*@return
****************************************/
void SendCMD(int _Fd, InterChangerCMD _Type, char* _Cmd)
{
	char chBuf[1024];
	size_t iSendLen = 0;
	/*\ 使程序进入到全局模式下 \*/
	memset(chBuf, 0, sizeof(chBuf));
	strcpy(chBuf, _Cmd);
	iSendLen = serial_send(_Fd, chBuf, strlen(chBuf));
	if (iSendLen > 0)
	{
		iSendLen = -1;
		uiOptCMD = _Type;
	}
	else
	{
		printf("Send CMD(%s) Error\n", _Cmd);
	}
}

/****************************************!
*@brief  在命令行全局模式下操作的所有命令
*@author Jinzi
*@date   2019/05/09 17:44:42
*@param[in]  _Fd 串口句柄
			 _OptStat 操作状态
			 _InterChanger 存储的配置文件中的交换机信息
			 _Ini8021x	存储配置8021x的信息
*@param[out]
*@return
****************************************/
void OperGlobModeCMD(int _Fd, PSAVEINI _InterChanger, PINI8021X _Ini8021x)
{
	char chBuf[4096];
	switch (uiOptCMD)
	{
	case INTERCHANGER_THREE:/*\ 注册会话 monitor session 1\*/
		printf("INTERCHANGER_THREE\n");
		SendCMD(_Fd, INTERCHANGER_FOUR, "monitor session 1\n");
		break;
	case INTERCHANGER_SEVEN: /*\ 开启802.1x认证 dot1x enable \*/
		SendCMD(_Fd, INTERCHANGER_EIGHT, "dot1x enable");
	case INTERCHANGER_EIGHT: /*\ 配置端口 interface eth0/2 \*/
		memset(chBuf, 0, sizeof(chBuf));
		sprintf(chBuf, "interface %s\n", _Ini8021x->chPort);
		SendCMD(_Fd, INTERCHANGER_NINE, chBuf);
		break;
	case INTERCHANGER_ELEVEN: /*\ 配置redius信息 radius-server host 1.1.1.2 key name \*/
		memset(chBuf, 0, sizeof(chBuf));
		sprintf(chBuf, "radius-server host %s key %s", _Ini8021x->chIp, _Ini8021x->chKey);
		SendCMD(_Fd, INTERCHANGER_TWELVE, chBuf);
		break;
	default:
		break;
	}
}
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
void OperInterModeCMD(int _Fd, PSAVEINI _InterChanger, PINI8021X _Ini8021x)
{
	switch (uiOptCMD)
	{
	case INTERCHANGER_NINE:	/*\ 打开端口 dot1x port-control auto \*/
		SendCMD(_Fd, INTERCHANGER_TEN, "dot1x port-control auto");
		break;
	case INTERCHANGER_TEN:  /*\ 从接口模式中退出到全局模式 exit \*/
		SendCMD(_Fd, INTERCHANGER_ELEVEN, "exit");
		break;
	default:
		break;
	}
}
/****************************************!
*@brief  在命令行用户模式下操作的所有命令(SWITCH>)
*@author Jinzi
*@date   2019/05/09 17:44:42
*@param[in]  _Fd 串口句柄
			 _OptStat 操作状态
*@param[out]
*@return
****************************************/
void OperUserModeCMD(int _Fd)
{
	switch (uiOptCMD)
	{
	case INTERCHANGER_ONE:/*\ 进入到特权模式中enable\n \*/
		SendCMD(_Fd, INTERCHANGER_TWO, "enable\n");
		break;
	default:
		break;
	}
}

/****************************************!
*@brief  说明交换机正在初始化数据
*@author Jinzi
*@date   2019/05/10 11:10:04
*@param[in]  _Fd就是串口句柄
*@param[out]
*@return
****************************************/
void InterChangeInitData(int _Fd)
{
	char chBuf[1024];
	int iSendLen = -1;
	printf("InterChanger Init Data Exec\n");
	memset(chBuf, 0, sizeof(chBuf));
	strcpy(chBuf, "\n");
	/*\ 成功返回发送数据的长度 失败返回-1 \*/
	iSendLen = serial_send(_Fd, chBuf, strlen(chBuf));
	if (iSendLen > 0)
	{
		iSendLen = -1;
	}
	else
	{
		printf("Send Login UserName Error\n");
	}
}