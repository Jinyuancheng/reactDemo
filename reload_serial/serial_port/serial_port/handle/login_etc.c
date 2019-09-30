
#include "./login_etc.h"
#include <stdlib.h>
#ifndef __SERIAL_H__
#include "../serial/serial.h"
#endif

/*\ ��������ָ��Ĳ��� \*/
InterChangerCMD uiOptCMD = INTERCHANGER_ONE;	//���뵽��Ȩģʽ
/*\ ָ���״̬ \*/
CMDSTATUS uiCmdStatus = CMDSTATUS_NONE;			//��ʼ��ģʽ
/****************************************!
*@brief  �ж��ַ������������жϽ������Ƿ���سɹ���Ȼ���½
*@author Jinzi
*@date   2019/05/08 8:40:19
*@param[in]  _Fd ���ھ��
			 _InterChanger �洢�����ý���������Ϣ
			 _Ini8021x �洢����8021x����Ϣ
*@param[out]
*@return
****************************************/
void JuageStrOpt(int _Fd, PSAVEINI _InterChanger, PINI8021X _Ini8021x)
{
	/*\ ������������ \*/
	char _Buf[10240];
	serial_send(_Fd, "\n", 1);
	/*\ �������� \*/
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
			/*\ ���ö˿ھ��� \*/
			else if (strstr(_Buf, "SWITCH(config-monitor)#") != NULL)
			{
				uiCmdStatus = CMDSTATUS_CONPORT;
				printf("%s\n", _Buf);
				continue;
			}
			/*\ �ӿ�ģʽ�� \*/
			else if (strstr(_Buf, "SWITCH(config-if)#") != NULL)
			{
				uiCmdStatus = CMDSTATUS_INTERMODE;
				printf("%s\n", _Buf);
				continue;
			}
			/*\ ȫ��ģʽ \*/
			else if (strstr(_Buf, "SWITCH(config)#") != NULL)
			{
				uiCmdStatus = CMDSTATUS_GLBMODE;
				continue;
			}
			/*\ ��Ȩģʽ \*/
			else if (strstr(_Buf, "SWITCH#") != NULL)
			{
				uiCmdStatus = CMDSTATUS_PRIMODE;
				printf("%s\n", _Buf);
				continue;
			}
			/*\ �û�ģʽ \*/
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
			/*\ ����ָ��״̬���в�ͬ�Ĳ��� \*/
			switch (uiCmdStatus)
			{
				/*\ ˵�����������ڼ������� \*/
			case CMDSTATUS_INIT:
				InterChangeInitData(_Fd);
				break;
				/*\ �û���¼ \*/
			case CMDSTATUS_USER:
				UserLogin(_Fd, "admin\n");
				break;
				/*\ ģ�������û����� \*/
			case CMDSTATUS_PASS:
				UserPass(_Fd, "admin\n");
				break;
				/*\ �û�ģʽ�� \*/
			case CMDSTATUS_USERMODE:
				OperUserModeCMD(_Fd);
				/*\ ��ǰ������Ȩģʽ�� \*/
			case CMDSTATUS_PRIMODE:
				OperPriModeCMD(_Fd, _InterChanger, _Ini8021x);
				break;
				/*\ ��ǰ����ȫ��ģʽ�� \*/
			case CMDSTATUS_GLBMODE:
				OperGlobModeCMD(_Fd, _InterChanger, _Ini8021x);
				break;
				/*\ ��ǰ���ڽӿ�ģʽ�� \*/
			case CMDSTATUS_INTERMODE:
				OperInterModeCMD(_Fd, _InterChanger, _Ini8021x);
				/*\ ���ö˿ھ���ģʽ�� SWITCH(config-monitor)# \*/
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
*@brief  �������нӿ�ģʽ�²�������������
*@author Jinzi
*@date   2019/05/09 17:44:42
*@param[in]  _Fd ���ھ��
			 _OptStat ����״̬
			 _InterChanger �洢�������ļ��еĽ�������Ϣ
			 _Ini8021x	�洢����8021x����Ϣ
*@param[out]
*@return
****************************************/
void OperPortModeCMD(int _Fd, PSAVEINI _InterChanger, PINI8021X _Ini8021x)
{
	char chBuf[4096];
	switch (uiOptCMD)
	{
	case INTERCHANGER_FOUR: /*\ ���ûỰ��˵�� \*/
		memset(chBuf, 0, sizeof(chBuf));
		sprintf(chBuf, "description %s\n", _InterChanger->chSessDes);
		SendCMD(_Fd, INTERCHANGER_FIVE, chBuf);
		break;
	case INTERCHANGER_FIVE: /*\ ���ûỰԴ�˿� source interface %s rx\*/
		memset(chBuf, 0, sizeof(chBuf));
		sprintf(chBuf, "source interface %s rx\n", _InterChanger->chMainPort);
		SendCMD(_Fd, INTERCHANGER_SIX, chBuf);
		break;
	case INTERCHANGER_SIX: /*\ ���ûỰĿ�Ķ˿� destination interface %s \*/
		memset(chBuf, 0, sizeof(chBuf));
		sprintf(chBuf, "destination interface %s\n", _InterChanger->chCpuPort);
		SendCMD(_Fd, INTERCHANGER_SIX_1, chBuf);
		break;
	case INTERCHANGER_SIX_1: /*\ �˳���ȫ��ģʽ \*/
		SendCMD(_Fd, INTERCHANGER_SEVEN, "exit\n");
		break;
	default:
		break;
	}
}

/****************************************!
*@brief  ģ���û���¼
*@author Jinzi
*@date   2019/05/09 17:56:46
*@param[in]  _Fd ���ھ��
			 _UserName (��ʽ �� admin\n)
*@param[out]
*@return
****************************************/
void UserLogin(int _Fd, const char* _UserName)
{
	char chBuf[1024];
	int iSendLen = -1;
	memset(chBuf, 0, sizeof(chBuf));
	strcpy(chBuf, _UserName);
	/*\ �ɹ����ط������ݵĳ��� ʧ�ܷ���-1 \*/
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
*@brief  ģ���û���������
*@author Jinzi
*@date   2019/05/10 8:23:33
*@param[in]  _Fd ���ھ��
			 _PassWord �û����� (��ʽ �� admin\n)
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
*@brief  ����������Ȩģʽ�²�������������
*@author Jinzi
*@date   2019/05/09 17:44:42
*@param[in]  _Fd ���ھ��
			 _OptStat ����״̬
			 _InterChanger �洢�������ļ��еĽ�������Ϣ
			 _Ini8021x	�洢����8021x����Ϣ
*@param[out]
*@return
****************************************/
void OperPriModeCMD(int _Fd, PSAVEINI _InterChanger, PINI8021X _Ini8021x)
{
	char chBuf[1024];
	printf("Exec \n");
	memset(chBuf, 0, sizeof(chBuf));
	strcpy(chBuf, "reload\n");		//��������������
	//strcpy(chBuf, "show users\n");
	SendCMD(_Fd, INTERCHANGER_NONE, chBuf);
	usleep(1000000);
	memset(chBuf, 0, sizeof(chBuf));
	strcpy(chBuf, "y\n");		//��������������
	//strcpy(chBuf, "show users\n");
	SendCMD(_Fd, INTERCHANGER_NONE, chBuf);
}

/****************************************!
*@brief  ��������ָ��
*@author Jinzi
*@date   2019/05/10 8:41:14
*@param[in]  _Fd ���ھ��
			 _OptStat ����״̬ ������ʶ�ߵ��˵ڼ���
			 _Type ��������_OptStat�Ĳ�����Ϣ ��#InterChangerCMD��
			 _Cmd ���͵�ָ��
*@param[out]
*@return
****************************************/
void SendCMD(int _Fd, InterChangerCMD _Type, char* _Cmd)
{
	char chBuf[1024];
	size_t iSendLen = 0;
	/*\ ʹ������뵽ȫ��ģʽ�� \*/
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
*@brief  ��������ȫ��ģʽ�²�������������
*@author Jinzi
*@date   2019/05/09 17:44:42
*@param[in]  _Fd ���ھ��
			 _OptStat ����״̬
			 _InterChanger �洢�������ļ��еĽ�������Ϣ
			 _Ini8021x	�洢����8021x����Ϣ
*@param[out]
*@return
****************************************/
void OperGlobModeCMD(int _Fd, PSAVEINI _InterChanger, PINI8021X _Ini8021x)
{
	char chBuf[4096];
	switch (uiOptCMD)
	{
	case INTERCHANGER_THREE:/*\ ע��Ự monitor session 1\*/
		printf("INTERCHANGER_THREE\n");
		SendCMD(_Fd, INTERCHANGER_FOUR, "monitor session 1\n");
		break;
	case INTERCHANGER_SEVEN: /*\ ����802.1x��֤ dot1x enable \*/
		SendCMD(_Fd, INTERCHANGER_EIGHT, "dot1x enable");
	case INTERCHANGER_EIGHT: /*\ ���ö˿� interface eth0/2 \*/
		memset(chBuf, 0, sizeof(chBuf));
		sprintf(chBuf, "interface %s\n", _Ini8021x->chPort);
		SendCMD(_Fd, INTERCHANGER_NINE, chBuf);
		break;
	case INTERCHANGER_ELEVEN: /*\ ����redius��Ϣ radius-server host 1.1.1.2 key name \*/
		memset(chBuf, 0, sizeof(chBuf));
		sprintf(chBuf, "radius-server host %s key %s", _Ini8021x->chIp, _Ini8021x->chKey);
		SendCMD(_Fd, INTERCHANGER_TWELVE, chBuf);
		break;
	default:
		break;
	}
}
/****************************************!
*@brief  �������нӿ�ģʽ�²�������������
*@author Jinzi
*@date   2019/05/09 17:44:42
*@param[in]  _Fd ���ھ��
			 _OptStat ����״̬
			 _InterChanger �洢�������ļ��еĽ�������Ϣ
			 _Ini8021x	�洢����8021x����Ϣ
*@param[out]
*@return
****************************************/
void OperInterModeCMD(int _Fd, PSAVEINI _InterChanger, PINI8021X _Ini8021x)
{
	switch (uiOptCMD)
	{
	case INTERCHANGER_NINE:	/*\ �򿪶˿� dot1x port-control auto \*/
		SendCMD(_Fd, INTERCHANGER_TEN, "dot1x port-control auto");
		break;
	case INTERCHANGER_TEN:  /*\ �ӽӿ�ģʽ���˳���ȫ��ģʽ exit \*/
		SendCMD(_Fd, INTERCHANGER_ELEVEN, "exit");
		break;
	default:
		break;
	}
}
/****************************************!
*@brief  ���������û�ģʽ�²�������������(SWITCH>)
*@author Jinzi
*@date   2019/05/09 17:44:42
*@param[in]  _Fd ���ھ��
			 _OptStat ����״̬
*@param[out]
*@return
****************************************/
void OperUserModeCMD(int _Fd)
{
	switch (uiOptCMD)
	{
	case INTERCHANGER_ONE:/*\ ���뵽��Ȩģʽ��enable\n \*/
		SendCMD(_Fd, INTERCHANGER_TWO, "enable\n");
		break;
	default:
		break;
	}
}

/****************************************!
*@brief  ˵�����������ڳ�ʼ������
*@author Jinzi
*@date   2019/05/10 11:10:04
*@param[in]  _Fd���Ǵ��ھ��
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
	/*\ �ɹ����ط������ݵĳ��� ʧ�ܷ���-1 \*/
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