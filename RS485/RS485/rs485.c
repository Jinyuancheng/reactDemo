/**********************************************************************
* Copyright (C) 2019-2020 天津白泽技术有限公司
* 文件名: rs485
* 描述: 设备操作
**********************************************************************/
#ifndef ENVPM_H
#include "rs485.h"
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

/*\ 发送查询状态的指令 \*/
int SendSelStatus(int fd, stpLowerStaSelSucc pRecvData, stpLowerSaveBase pRecvBase,
	unsigned char cr_bit, unsigned char data_len)
{
	int iRet = -1;
	int iCount = 0;
	unsigned char pchBufRec[80] = { 0 };
	char buf[8];
	buf[0] = 0xe5;
	buf[1] = 0x5e;
	buf[2] = 0x00;
	buf[3] = 0x01;
	buf[4] = data_len;
	buf[5] = 0x00;
	buf[6] = 0x00;
	buf[7] = cr_bit;
	setGPIO(GPIO_RS485_1, "0", 0);
	iCount = serial_send(fd, buf, 8);
	usleep(8500);
	setGPIO(GPIO_RS485_1, "1", 0);
	iCount = serial_receive(fd, pchBufRec, 80, 1);
	/*\ 操作成功 \*/
	if (iCount == 80)
	{
		pRecvBase = NULL;
		pRecvData->chFlagBit[0] = pchBufRec[0];
		pRecvData->chFlagBit[1] = pchBufRec[1];
		pRecvData->chDevAddr = pchBufRec[2];
		pRecvData->eCmdFlag = pchBufRec[3];
		pRecvData->chDataLen = pchBufRec[4];
		pRecvData->eCmdSucc = pchBufRec[5];
		pRecvData->chPowerStatus1_8 = pchBufRec[6];
		pRecvData->chPowerStatus9_12 = pchBufRec[7];
		int i = 0;
		for (i; i < 72; i++)
		{
			pRecvData->chElectData[i] = pchBufRec[8 + i];
		}
		iRet = 0;
		printf("Success\n");
	}
	/*\ 操作失败 \*/
	else
	{
		pRecvData = NULL;
		pRecvBase->chFlagBit[0] = pchBufRec[0];
		pRecvBase->chFlagBit[1] = pchBufRec[1];
		pRecvBase->chDevAddr = pchBufRec[2];
		pRecvBase->eCmdFlag = pchBufRec[3];
		pRecvBase->chDataLen = pchBufRec[4];
		pRecvBase->chFixData = pchBufRec[5];
		pRecvBase->eOptRes = pchBufRec[6];
		pRecvBase->chData = pchBufRec[7];
		printf("Default\n");
	}
	return iRet;
}
/*\ 开关控制指令 \*/
int SendOnOffContorlCmd(int fd, stpLowerSaveBase pRecvBase, unsigned char power_number,
	unsigned char on_or_off, unsigned char cr_bit, unsigned char data_len)
{
	int iRet = -1;
	int iCount = 0;
	unsigned char pchBufRec[77] = { 0 };
	//E5 5E 00 03 02 01 01 07
	char buf[8];
	buf[0] = 0xe5;
	buf[1] = 0x5e;
	buf[2] = 0x00;
	buf[3] = 0x03;
	buf[4] = data_len;
	buf[5] = power_number;
	buf[6] = on_or_off;
	buf[7] = cr_bit;
	/*buf[4] = 0x02;
	buf[5] = 0x01;
	buf[6] = 0x01;
	buf[7] = 0x07;*/
	setGPIO(GPIO_RS485_1, "0", 0);
	iCount = serial_send(fd, buf, 8);
	usleep(8500);
	setGPIO(GPIO_RS485_1, "1", 0);
	iCount = serial_receive(fd, (char*)pchBufRec, 8, 1);
	/*\ 操作成功 \*/
	if (iCount == 8)
	{
		pRecvBase->chFlagBit[0] = pchBufRec[0];
		pRecvBase->chFlagBit[1] = pchBufRec[1];
		pRecvBase->chDevAddr = pchBufRec[2];
		pRecvBase->eCmdFlag = pchBufRec[3];
		pRecvBase->chDataLen = pchBufRec[4];
		pRecvBase->chFixData = pchBufRec[5];
		pRecvBase->eOptRes = pchBufRec[6];
		pRecvBase->chData = pchBufRec[7];
		iRet = 0;
	}
	/*\ 操作失败 \*/
	else
	{
		pRecvBase->chFlagBit[0] = pchBufRec[0];
		pRecvBase->chFlagBit[1] = pchBufRec[1];
		pRecvBase->chDevAddr = pchBufRec[2];
		pRecvBase->eCmdFlag = pchBufRec[3];
		pRecvBase->chDataLen = pchBufRec[4];
		pRecvBase->chFixData = pchBufRec[5];
		pRecvBase->eOptRes = pchBufRec[6];
		pRecvBase->chData = pchBufRec[7];
	}
	return iRet;
}
/****************************************!
*@brief  处理电流的操作
*@author Jinzi
*@date   2019/06/14 8:45:00
*@param[in]  elect 存储电流的数组
*@param[out]
*@return     成功返回0 失败返回-1 成功 elect存储电流数据 失败elect为NULL
****************************************/
int HandleElect(float* elect)
{
	stpLowerStaSelSucc chBuff = (stpLowerStaSelSucc)malloc(sizeof(stLowerStaSelSucc));
	stpLowerSaveBase chBuffBase = (stpLowerSaveBase)malloc(sizeof(stLowerSaveBase));
	exportGPIO(GPIO_RS485_1);
	setGPIODirection(GPIO_RS485_1, "out");
	int SerialFd = OpenENVPMPort();
	if (SendSelStatus(SerialFd, chBuff, chBuffBase, 0x03, 0x02) >= 0)
	{
		unsigned int* ElectParam;//电流参数
		unsigned int* ElectValue;//电流值
		char temp[4] = { 0 };
		char temp1[4] = { 0 };
		int i = 0;
		int j = 0;
		int num;
		int ii = 1;
		for (i; i < 72;)
		{
			printf("i = %d\n",i);
			if (i == 0 || i == (num + 6))
			{
				memset(temp, 0, 4);
				memset(temp1, 0, 4);
				printf("data : %02X\n", chBuff->chElectData[i]);
				printf("data : %02X\n", chBuff->chElectData[i + 1]);
				printf("data : %02X\n", chBuff->chElectData[i + 2]);
				printf("data : %02X\n", chBuff->chElectData[i + 3]);
				printf("data : %02X\n", chBuff->chElectData[i + 4]);
				printf("data : %02X\n", chBuff->chElectData[i + 5]);
				temp[3] = 0x00;
				temp[2] = chBuff->chElectData[i];
				temp[1] = chBuff->chElectData[i + 1];
				temp[0] = chBuff->chElectData[i + 2];
				ElectParam = (unsigned int*)temp;
				printf("ElectParam : %d\n", *ElectParam);
				temp1[3] = 0x00;
				temp1[2] = chBuff->chElectData[i + 3];
				temp1[1] = chBuff->chElectData[i + 4];
				temp1[0] = chBuff->chElectData[i + 5];
				ElectValue = (unsigned int*)temp1;
				printf("ElectValue : %d\n", *ElectValue);
				if (*ElectValue == 0)
				{
					printf("@@@@@@======> dian liu xin xi wei 0\n");
					elect[ii - 1] = 0;
				}
				else
				{
					float test;
					test = (((float)(*ElectParam) / (float)(*ElectValue)) * 0.02);
					elect[ii - 1] = test;
					printf("@@@@@@=====>Di [%d] lian lu dian liu zhi wei : %f\n", ii, test);
				}
			}
			ii++;
			num = i;
			i += 6;
		}
		free(chBuff);
		free(chBuffBase);
		CloseENVPMPort(SerialFd);
		return 0;
	}
	else
	{
		elect = NULL;
		return -1;
	}
	
}
