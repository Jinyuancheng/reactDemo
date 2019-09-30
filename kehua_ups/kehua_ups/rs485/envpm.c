/**********************************************************************
* Copyright (C) 2017-2018 天津蔚蓝玄通科技有限公司
* 文件名: envpm.c
* 描述: 环境监测模块
**********************************************************************/
#ifndef ENVPM_H
#include "envpm.h"
#endif
#ifndef __SERIAL_H__
#include "serial.h"
#endif
#ifndef GPIO_H
#include "gpio.h"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <iconv.h>
#include <errno.h>
#include <wchar.h>

#ifndef _KEHUA_H_
#include "../kehua_pro/kehua.h"
#endif

//***********************************************************
void InvertUint8(unsigned char *DesBuf, unsigned char *SrcBuf)
{
	int i;
	unsigned char temp = 0;

	for (i = 0; i < 8; i++)
	{
		if (SrcBuf[0] & (1 << i))
		{
			temp |= 1 << (7 - i);
		}
	}
	DesBuf[0] = temp;
}
//***********************************************************
void InvertUint16(unsigned short *DesBuf, unsigned short *SrcBuf)
{
	int i;
	unsigned short temp = 0;

	for (i = 0; i < 16; i++)
	{
		if (SrcBuf[0] & (1 << i))
		{
			temp |= 1 << (15 - i);
		}
	}
	DesBuf[0] = temp;
}
//***********************************************************//
/*\ 差错校验码 \*/
unsigned short CRC16_MODBUS(unsigned char *puchMsg, unsigned int usDataLen)
{
	unsigned short wCRCin = 0xFFFF;  /*\ 1111 1111 1111 1111 \*/
	unsigned short wCPoly = 0x8005;  /*\ 1000 0000 0000 0101 \*/
	unsigned char wChar = 0;
	int i = 0;
	while (usDataLen--)
	{
		wChar = *(puchMsg++);
		InvertUint8(&wChar, &wChar);
		wCRCin ^= (wChar << 8);
		for (i = 0; i < 8; i++)
		{
			if (wCRCin & 0x8000)
			{
				wCRCin = (wCRCin << 1) ^ wCPoly;
			}
			else
			{
				wCRCin = wCRCin << 1;
			}
		}
	}
	InvertUint16(&wCRCin, &wCRCin);
	return (wCRCin);
}

/****************************************!
*@brief  打开科华串口
*@author Jinzi
*@date   2019/06/12 9:33:08
*@param[in]
*@param[out]
*@return	成功返回打开的串口句柄，失败返回-1
****************************************/
int OpenKeHuaPort(int _port)
{
	int SerialFd = serial_open(_port, 2400);
	if (SerialFd != -1)
	{
		serial_set_attr(SerialFd, 8, PARITY_NONE, 1, FLOW_CONTROL_NONE);
		printf("@@@@ kehua Open Serial Port Ok\n");
	}
	else
	{
		printf("@@@@ kehua Open Serial Port Error\n");
	}
	return SerialFd;
}

/****************************************!
*@brief  关闭打开的串口
*@author Jinzi
*@date   2019/06/12 9:37:55
*@param[in]  _fd 打开的串口句柄
*@param[out]
*@return
****************************************/
void CloseKeHuaPort(int _fd)
{
	if (_fd != -1)
	{
		serial_close(_fd);
	}
}

/****************************************!
*@brief  用来区分是请求哪个数据
*@author Jinzi
*@date   2019/06/12 10:03:59
*@param[in]  _fd 文件句柄
			 _type 请求ups类型
			 _dest 用来存储ups返回数据
*@param[out]
*@return
****************************************/
void UpsReqCmdType(int _fd, TRANSPOSTCMD _type, char* _dest)
{
	switch (_type)
	{
	case TRANSPOSTCMD_Q1: /*\ 请求ups状态信息 \*/
		UpsStautsReq(_fd, _dest);
		break;
	case TRANSPOSTCMD_T: /*\ 测试10秒钟 \*/
		UpsTestTenS(_fd, _dest);
		break;
	case TRANSPOSTCMD_TL: /*\ 电池欠压 \*/
		UpsPowerLowerV(_fd, _dest);
		break;
	case TRANSPOSTCMD_TTIME: /*\ 测试规定时间,下一个字节为时间01-99 T<n> \*/
		/*\ 默认时间10分钟 \*/
		UpsSetTime(_fd, _dest, 0x0a);
		break;
	case TRANSPOSTCMD_Q: /*\ 开关蜂鸣器 \*/
		UpsOnOffBuzzer(_fd, _dest);
		break;
	case TRANSPOSTCMD_STIME: /*\ 多少分钟后关机 \*/
		/*\ 默认时间5分钟，最大不能超过10分钟 \*/
		UpsShutDownTime(_fd, _dest, 0x05);
		break;
	case TRANSPOSTCMD_STIMER: /*\ 多久后关机，相隔多久后在开机 \*/
		/*\ 默认都为两分钟 \*/
		UpsSTimeRTime(_fd, _dest, 0x02, 0x02);
		break;
	case TRANSPOSTCMD_C: /*\ 取消关机指令 \*/
		UpsCancelSCmd(_fd, _dest);
		break;
	case TRANSPOSTCMD_CT: /*\ 取消测试指令 \*/
		UpsCancelTestCmd(_fd, _dest);
		break;
	case TRANSPOSTCMD_I: /*\ 厂家信息指令查询 \*/
		UpsSelFactInfo(_fd, _dest);
		break;
	case TRANSPOSTCMD_F: /*\ ups额定信息查询 \*/
		UpsSelRatedInfo(_fd, _dest);
		break;
	default:
		break;
	}
}

/****************************************!
*@brief  ups状态请求
*@author Jinzi
*@date   2019/06/12 9:40:23
*@param[in]  _fd 串口句柄
			 _dest 用来存储ups返回的数据
*@param[out]
*@return
****************************************/
void UpsStautsReq(int _fd, char* _dest)
{
	unsigned char uchSendBuf[8];
	//unsigned char uchRecvBuf[8];
	int iSendLen = 0;
	int iRecvLen = 0;
	memset(uchSendBuf, 0, sizeof(uchSendBuf));
	//memset(uchRecvBuf, 0, sizeof(uchRecvBuf));
	uchSendBuf[0] = 0x51;
	uchSendBuf[1] = 0x01;
	uchSendBuf[2] = CR;
	/*\ rs485是单向通信 通过调整高电平或底电平来控制输入还是输出 \*/
	setGPIO(GPIO_RS485_1, "0", 0);
	iSendLen = serial_send(_fd, (char*)uchSendBuf, 8);
	printf("@@@@@@@@@0   send %d %02X %02X %02X %02X %02X %02X %02X %02X\n", iSendLen, uchSendBuf[0],
		uchSendBuf[1], uchSendBuf[2], uchSendBuf[3], uchSendBuf[4], uchSendBuf[5],
		uchSendBuf[6], uchSendBuf[7]);
	usleep(8500);/*\ 根据波特率等计算出来的 \*/
	setGPIO(GPIO_RS485_1, "1", 0);
	iRecvLen = serial_receive(_fd, _dest, 8, 1);
	if (iRecvLen == 8)
	{
		printf("@@@@ Recv Data Success\n");
	}
	else
	{
		printf("@@@ Recv Data Failed\n");
	}
}
/****************************************!
*@brief  ups测试十秒钟
*@author Jinzi
*@date   2019/06/12 10:14:24
*@param[in]  _fd 串口句柄
			 _dest 存储ups返回的数据
*@param[out]
*@return
****************************************/
void UpsTestTenS(int _fd, char* _dest)
{
	unsigned char uchSendBuf[8];
	int iSendLen = 0;
	int iRecvLen = 0;
	memset(uchSendBuf, 0, sizeof(uchSendBuf));
	//memset(uchRecvBuf, 0, sizeof(uchRecvBuf));
	uchSendBuf[0] = 0x54;
	uchSendBuf[1] = CR;
	/*\ rs485是单向通信 通过调整高电平或底电平来控制输入还是输出 \*/
	setGPIO(GPIO_RS485_1, "0", 0);
	iSendLen = serial_send(_fd, (char*)uchSendBuf, 8);
	printf("@@@@@@@@@0   send %d %02X %02X %02X %02X %02X %02X %02X %02X\n", iSendLen, uchSendBuf[0],
		uchSendBuf[1], uchSendBuf[2], uchSendBuf[3], uchSendBuf[4], uchSendBuf[5],
		uchSendBuf[6], uchSendBuf[7]);
	usleep(8500);/*\ 根据波特率等计算出来的 \*/
	setGPIO(GPIO_RS485_1, "1", 0);
	iRecvLen = serial_receive(_fd, _dest, 8, 1);
	if (iRecvLen == 8)
	{
		printf("@@@@ Recv Data Success\n");
	}
	else
	{
		printf("@@@ Recv Data Failed\n");
	}
}
/****************************************!
*@brief  ups电池欠压
*@author Jinzi
*@date   2019/06/12 10:14:24
*@param[in]  _fd 串口句柄
			 _dest 存储ups返回的数据
*@param[out]
*@return
****************************************/
void UpsPowerLowerV(int _fd, char* _dest)
{
	unsigned char uchSendBuf[8];
	int iSendLen = 0;
	int iRecvLen = 0;
	memset(uchSendBuf, 0, sizeof(uchSendBuf));
	//memset(uchRecvBuf, 0, sizeof(uchRecvBuf));
	uchSendBuf[0] = 0x54;
	uchSendBuf[1] = 0x4c;
	uchSendBuf[2] = CR;
	/*\ rs485是单向通信 通过调整高电平或底电平来控制输入还是输出 \*/
	setGPIO(GPIO_RS485_1, "0", 0);
	iSendLen = serial_send(_fd, (char*)uchSendBuf, 8);
	printf("@@@@@@@@@0   send %d %02X %02X %02X %02X %02X %02X %02X %02X\n", iSendLen, uchSendBuf[0],
		uchSendBuf[1], uchSendBuf[2], uchSendBuf[3], uchSendBuf[4], uchSendBuf[5],
		uchSendBuf[6], uchSendBuf[7]);
	usleep(8500);/*\ 根据波特率等计算出来的 \*/
	setGPIO(GPIO_RS485_1, "1", 0);
	iRecvLen = serial_receive(_fd, _dest, 8, 1);
	if (iRecvLen == 8)
	{
		printf("@@@@ Recv Data Success\n");
	}
	else
	{
		printf("@@@ Recv Data Failed\n");
	}
}
/****************************************!
*@brief  ups测试规定时间
*@author Jinzi
*@date   2019/06/12 10:14:24
*@param[in]  _fd 串口句柄
			 _dest 存储ups返回的数据
			 _minute 相隔多长时间
*@param[out]
*@return
****************************************/
void UpsSetTime(int _fd, char* _dest, unsigned char _minute)
{
	unsigned char uchSendBuf[8];
	int iSendLen = 0;
	int iRecvLen = 0;
	memset(uchSendBuf, 0, sizeof(uchSendBuf));
	//memset(uchRecvBuf, 0, sizeof(uchRecvBuf));
	uchSendBuf[0] = 0x54;
	uchSendBuf[1] = _minute	;
	uchSendBuf[2] = CR;
	/*\ rs485是单向通信 通过调整高电平或底电平来控制输入还是输出 \*/
	setGPIO(GPIO_RS485_1, "0", 0);
	iSendLen = serial_send(_fd, (char*)uchSendBuf, 8);
	printf("@@@@@@@@@0   send %d %02X %02X %02X %02X %02X %02X %02X %02X\n", iSendLen, uchSendBuf[0],
		uchSendBuf[1], uchSendBuf[2], uchSendBuf[3], uchSendBuf[4], uchSendBuf[5],
		uchSendBuf[6], uchSendBuf[7]);
	usleep(8500);/*\ 根据波特率等计算出来的 \*/
	setGPIO(GPIO_RS485_1, "1", 0);
	iRecvLen = serial_receive(_fd, _dest, 8, 1);
	if (iRecvLen == 8)
	{
		printf("@@@@ Recv Data Success\n");
	}
	else
	{
		printf("@@@ Recv Data Failed\n");
	}
}
/****************************************!
*@brief  ups开关蜂鸣器
*@author Jinzi
*@date   2019/06/12 10:14:24
*@param[in]  _fd 串口句柄
			 _dest 存储ups返回的数据
*@param[out]
*@return
****************************************/
void UpsOnOffBuzzer(int _fd, char* _dest)
{
	unsigned char uchSendBuf[8];
	int iSendLen = 0;
	int iRecvLen = 0;
	memset(uchSendBuf, 0, sizeof(uchSendBuf));
	//memset(uchRecvBuf, 0, sizeof(uchRecvBuf));
	uchSendBuf[0] = 0x54;
	uchSendBuf[1] = CR;
	/*\ rs485是单向通信 通过调整高电平或底电平来控制输入还是输出 \*/
	setGPIO(GPIO_RS485_1, "0", 0);
	iSendLen = serial_send(_fd, (char*)uchSendBuf, 8);
	printf("@@@@@@@@@0   send %d %02X %02X %02X %02X %02X %02X %02X %02X\n", iSendLen, uchSendBuf[0],
		uchSendBuf[1], uchSendBuf[2], uchSendBuf[3], uchSendBuf[4], uchSendBuf[5],
		uchSendBuf[6], uchSendBuf[7]);
	usleep(8500);/*\ 根据波特率等计算出来的 \*/
	setGPIO(GPIO_RS485_1, "1", 0);
	iRecvLen = serial_receive(_fd, _dest, 8, 1);
	if (iRecvLen == 8)
	{
		printf("@@@@ Recv Data Success\n");
	}
	else
	{
		printf("@@@ Recv Data Failed\n");
	}
}
/****************************************!
*@brief  ups多少分钟后关机
*@author Jinzi
*@date   2019/06/12 10:14:24
*@param[in]  _fd 串口句柄
			 _dest 存储ups返回的数据
			 _minute 相隔多长时间
*@param[out]
*@return
****************************************/
void UpsShutDownTime(int _fd, char* _dest, unsigned char _minute)
{
	unsigned char uchSendBuf[8];
	int iSendLen = 0;
	int iRecvLen = 0;
	memset(uchSendBuf, 0, sizeof(uchSendBuf));
	//memset(uchRecvBuf, 0, sizeof(uchRecvBuf));
	uchSendBuf[0] = 0x53;
	uchSendBuf[1] = _minute;
	uchSendBuf[2] = CR;
	/*\ rs485是单向通信 通过调整高电平或底电平来控制输入还是输出 \*/
	setGPIO(GPIO_RS485_1, "0", 0);
	iSendLen = serial_send(_fd, (char*)uchSendBuf, 8);
	printf("@@@@@@@@@0   send %d %02X %02X %02X %02X %02X %02X %02X %02X\n", iSendLen, uchSendBuf[0],
		uchSendBuf[1], uchSendBuf[2], uchSendBuf[3], uchSendBuf[4], uchSendBuf[5],
		uchSendBuf[6], uchSendBuf[7]);
	usleep(8500);/*\ 根据波特率等计算出来的 \*/
	setGPIO(GPIO_RS485_1, "1", 0);
	iRecvLen = serial_receive(_fd, _dest, 8, 1);
	if (iRecvLen == 8)
	{
		printf("@@@@ Recv Data Success\n");
	}
	else
	{
		printf("@@@ Recv Data Failed\n");
	}
}
/****************************************!
*@brief  ups多少分钟后关机，多少分钟后重启
*@author Jinzi
*@date   2019/06/12 10:14:24
*@param[in]  _fd 串口句柄
			 _dest 存储ups返回的数据
			 _sminute 相隔多长时间后关机
			 _reminute 相隔多长时间后开机
*@param[out]
*@return
****************************************/
void UpsSTimeRTime(int _fd, char* _dest, unsigned char _sminute, unsigned char _rminute)
{
	unsigned char uchSendBuf[8];
	int iSendLen = 0;
	int iRecvLen = 0;
	memset(uchSendBuf, 0, sizeof(uchSendBuf));
	//memset(uchRecvBuf, 0, sizeof(uchRecvBuf));
	uchSendBuf[0] = 0x53;
	uchSendBuf[1] = _sminute;
	uchSendBuf[2] = 0x52;
	uchSendBuf[3] = _rminute;
	uchSendBuf[4] = CR;
	/*\ rs485是单向通信 通过调整高电平或底电平来控制输入还是输出 \*/
	setGPIO(GPIO_RS485_1, "0", 0);
	iSendLen = serial_send(_fd, (char*)uchSendBuf, 8);
	printf("@@@@@@@@@0   send %d %02X %02X %02X %02X %02X %02X %02X %02X\n", iSendLen, uchSendBuf[0],
		uchSendBuf[1], uchSendBuf[2], uchSendBuf[3], uchSendBuf[4], uchSendBuf[5],
		uchSendBuf[6], uchSendBuf[7]);
	usleep(8500);/*\ 根据波特率等计算出来的 \*/
	setGPIO(GPIO_RS485_1, "1", 0);
	iRecvLen = serial_receive(_fd, _dest, 8, 1);
	if (iRecvLen == 8)
	{
		printf("@@@@ Recv Data Success\n");
	}
	else
	{
		printf("@@@ Recv Data Failed\n");
	}
}
/****************************************!
*@brief  ups取消关机指令
*@author Jinzi
*@date   2019/06/12 10:14:24
*@param[in]  _fd 串口句柄
			 _dest 存储ups返回的数据
*@param[out]
*@return
****************************************/
void UpsCancelSCmd(int _fd, char* _dest)
{
	unsigned char uchSendBuf[8];
	int iSendLen = 0;
	int iRecvLen = 0;
	memset(uchSendBuf, 0, sizeof(uchSendBuf));
	//memset(uchRecvBuf, 0, sizeof(uchRecvBuf));
	uchSendBuf[0] = 0x43;
	uchSendBuf[1] = CR;
	/*\ rs485是单向通信 通过调整高电平或底电平来控制输入还是输出 \*/
	setGPIO(GPIO_RS485_1, "0", 0);
	iSendLen = serial_send(_fd, (char*)uchSendBuf, 8);
	printf("@@@@@@@@@0   send %d %02X %02X %02X %02X %02X %02X %02X %02X\n", iSendLen, uchSendBuf[0],
		uchSendBuf[1], uchSendBuf[2], uchSendBuf[3], uchSendBuf[4], uchSendBuf[5],
		uchSendBuf[6], uchSendBuf[7]);
	usleep(8500);/*\ 根据波特率等计算出来的 \*/
	setGPIO(GPIO_RS485_1, "1", 0);
	iRecvLen = serial_receive(_fd, _dest, 8, 1);
	if (iRecvLen == 8)
	{
		printf("@@@@ Recv Data Success\n");
	}
	else
	{
		printf("@@@ Recv Data Failed\n");
	}
}
/****************************************!
*@brief  ups取消测试指令
*@author Jinzi
*@date   2019/06/12 10:14:24
*@param[in]  _fd 串口句柄
			 _dest 存储ups返回的数据
*@param[out]
*@return
****************************************/
void UpsCancelTestCmd(int _fd, char* _dest)
{
	unsigned char uchSendBuf[8];
	int iSendLen = 0;
	int iRecvLen = 0;
	memset(uchSendBuf, 0, sizeof(uchSendBuf));
	//memset(uchRecvBuf, 0, sizeof(uchRecvBuf));
	uchSendBuf[0] = 0x43;
	uchSendBuf[1] = 0x54;
	uchSendBuf[2] = CR;
	/*\ rs485是单向通信 通过调整高电平或底电平来控制输入还是输出 \*/
	setGPIO(GPIO_RS485_1, "0", 0);
	iSendLen = serial_send(_fd, (char*)uchSendBuf, 8);
	printf("@@@@@@@@@0   send %d %02X %02X %02X %02X %02X %02X %02X %02X\n", iSendLen, uchSendBuf[0],
		uchSendBuf[1], uchSendBuf[2], uchSendBuf[3], uchSendBuf[4], uchSendBuf[5],
		uchSendBuf[6], uchSendBuf[7]);
	usleep(8500);/*\ 根据波特率等计算出来的 \*/
	setGPIO(GPIO_RS485_1, "1", 0);
	iRecvLen = serial_receive(_fd, _dest, 8, 1);
	if (iRecvLen == 8)
	{
		printf("@@@@ Recv Data Success\n");
	}
	else
	{
		printf("@@@ Recv Data Failed\n");
	}
}
/****************************************!
*@brief  ups厂家信息命令查询
*@author Jinzi
*@date   2019/06/12 10:14:24
*@param[in]  _fd 串口句柄
			 _dest 存储ups返回的数据
*@param[out]
*@return
****************************************/
void UpsSelFactInfo(int _fd, char* _dest)
{
	unsigned char uchSendBuf[8];
	int iSendLen = 0;
	int iRecvLen = 0;
	memset(uchSendBuf, 0, sizeof(uchSendBuf));
	//memset(uchRecvBuf, 0, sizeof(uchRecvBuf));
	uchSendBuf[0] = 0x49;
	uchSendBuf[1] = CR;
	/*\ rs485是单向通信 通过调整高电平或底电平来控制输入还是输出 \*/
	setGPIO(GPIO_RS485_1, "0", 0);
	iSendLen = serial_send(_fd, (char*)uchSendBuf, 8);
	printf("@@@@@@@@@0   send %d %02X %02X %02X %02X %02X %02X %02X %02X\n", iSendLen, uchSendBuf[0],
		uchSendBuf[1], uchSendBuf[2], uchSendBuf[3], uchSendBuf[4], uchSendBuf[5],
		uchSendBuf[6], uchSendBuf[7]);
	usleep(8500);/*\ 根据波特率等计算出来的 \*/
	setGPIO(GPIO_RS485_1, "1", 0);
	iRecvLen = serial_receive(_fd, _dest, 256, 1);
	if (iRecvLen == 256)
	{
		printf("@@@@ Recv Data Success\n");
	}
	else
	{
		printf("@@@ Recv Data Failed\n");
	}
}
/****************************************!
*@brief  ups额定值信息查询
*@author Jinzi
*@date   2019/06/12 10:14:24
*@param[in]  _fd 串口句柄
			 _dest 存储ups返回的数据
*@param[out]
*@return
****************************************/
void UpsSelRatedInfo(int _fd, char* _dest)
{
	unsigned char uchSendBuf[8];
	int iSendLen = 0;
	int iRecvLen = 0;
	memset(uchSendBuf, 0, sizeof(uchSendBuf));
	//memset(uchRecvBuf, 0, sizeof(uchRecvBuf));
	uchSendBuf[0] = 0x46;
	uchSendBuf[1] = CR;
	/*\ rs485是单向通信 通过调整高电平或底电平来控制输入还是输出 \*/
	setGPIO(GPIO_RS485_1, "0", 0);
	iSendLen = serial_send(_fd, (char*)uchSendBuf, 8);
	printf("@@@@@@@@@0   send %d %02X %02X %02X %02X %02X %02X %02X %02X\n", iSendLen, uchSendBuf[0],
		uchSendBuf[1], uchSendBuf[2], uchSendBuf[3], uchSendBuf[4], uchSendBuf[5],
		uchSendBuf[6], uchSendBuf[7]);
	usleep(8500);/*\ 根据波特率等计算出来的 \*/
	setGPIO(GPIO_RS485_1, "1", 0);
	iRecvLen = serial_receive(_fd, _dest, 8, 1);
	if (iRecvLen == 8)
	{
		printf("@@@@ Recv Data Success\n");
	}
	else
	{
		printf("@@@ Recv Data Failed\n");
	}
}

//***********************************************************
/*\ 打开串口，并设置属性 \*/
int OpenENVPMPort()
{
	//setGPIO(GPIO_RS485_1,"1",0);
	int fdCom = serial_open(1, 9600);
	if (fdCom != -1)
	{
		serial_set_attr(fdCom, 8, PARITY_NONE, 1, FLOW_CONTROL_NONE);
		printf("@@@@ Open com Ok \n");
	}
	else
		printf("@@@@ Open com Error \n");
	return fdCom;
}
//***********************************************************
/*\ 关闭串口 \*/
void CloseENVPMPort(int fd)
{
	if (fd != -1)
	{
		serial_close(fd);
	}
}
//***********************************************************
void SetENVPMAddr(int fd)
{
	unsigned char pchBuf[8];
	int iCount = 0;
	//unsigned short chCRC;
	memset(pchBuf, 0, 8);
	pchBuf[0] = 0x00;
	pchBuf[1] = 0x06;
	pchBuf[2] = 0x00;
	pchBuf[3] = 0x11;
	pchBuf[4] = 0x00;
	pchBuf[5] = 0x18;
	pchBuf[6] = 0xD8;
	pchBuf[7] = 0x14;
	setGPIO(GPIO_RS485_1, "0", 0);
	iCount = serial_send(fd, (char*)pchBuf, 8);
	printf("@@@@@@@@@0   send %d %02X %02X %02X %02X %02X %02X %02X %02X\n", iCount, pchBuf[0],
		pchBuf[1], pchBuf[2], pchBuf[3], pchBuf[4], pchBuf[5], pchBuf[6], pchBuf[7]);
	usleep(8500);
	pchBuf[3] = 0x13;
	pchBuf[5] = 0x03;
	pchBuf[6] = 0x39;
	pchBuf[7] = 0xDF;
	iCount = serial_send(fd, (char*)pchBuf, 8);
	printf("@@@@@@@@@00   send %d %02X %02X %02X %02X %02X %02X %02X %02X\n", iCount, pchBuf[0],
		pchBuf[1], pchBuf[2], pchBuf[3], pchBuf[4], pchBuf[5], pchBuf[6], pchBuf[7]);
	usleep(8500);
	setGPIO(GPIO_RS485_1, "1", 0);
}
//***********************************************************
int ReadENVPMData(int fd, unsigned short* data)
{
	int iRet = -1;
	int iCount = 0;
	unsigned short chCRC;
	unsigned char pchBuf[8];
	unsigned char pchBufRec[13];
	memset(pchBuf, 0, 8);
	pchBuf[0] = 0x03;
	pchBuf[1] = 0x03;
	pchBuf[2] = 0x00;
	pchBuf[3] = 0x00;
	pchBuf[4] = 0x00;
	pchBuf[5] = 0x04;
	chCRC = CRC16_MODBUS(pchBuf, 6);
	pchBuf[6] = chCRC & 0xFF;
	pchBuf[7] = (chCRC >> 8) & 0xFF;
	setGPIO(GPIO_RS485_1, "0", 0);
	iCount = serial_send(fd, (char*)pchBuf, 8);
	usleep(8500);
	setGPIO(GPIO_RS485_1, "1", 0);
	iCount = serial_receive(fd, (char*)pchBufRec, 13, 1);
	if (iCount == 13)
	{
		data[0] = ((unsigned short)pchBufRec[3]) << 8 | ((unsigned short)pchBufRec[4]);
		data[1] = ((unsigned short)pchBufRec[5]) << 8 | ((unsigned short)pchBufRec[6]);
		data[2] = ((unsigned short)pchBufRec[7]) << 8 | ((unsigned short)pchBufRec[8]);
		data[3] = ((unsigned short)pchBufRec[9]) << 8 | ((unsigned short)pchBufRec[10]);
		printf("@@@@@@@@@   error %d %d\n", data[0], data[1]);
		iRet = 0;
	}
	else
	{
		printf("@@@@@@@@@1   error %d %02X\n", iCount, pchBufRec[0]);
	}
	return iRet;
}
//***********************************************************

