/**********************************************************************
* Copyright (C) 2017-2018 天津蔚蓝玄通科技有限公司
* 文件名: gpio.h
* 描述: GPIO模块
**********************************************************************/
#include <stdlib.h>  
#include <stdio.h>  
#include <string.h>
#include <unistd.h>
#include <fcntl.h>  
#include <pthread.h>

#ifndef GPIO_H
#include "gpio.h"
#endif
/******************************************************************/
int exportGPIO(char* pchPin)
{
	int iRet = -1;
	int fd = -1;
	int iCount = 0;
	char pchBuf[100];
	memset(pchBuf,0,100);
	sprintf(pchBuf,"/sys/class/gpio/gpio%s/value",pchPin);
	fd = open(pchBuf,O_RDWR);
	if(fd != -1)
	{
		close(fd);
		iRet = 1;
	}
	else
	{
		fd = open("/sys/class/gpio/export", O_WRONLY);
		if(fd != -1)
		{
			iCount = write(fd,pchPin,strlen(pchPin));
			printf("exportGPIO: %s %d",pchPin,iCount);
			close(fd);
			iRet = 0;
		}
	}
	return iRet;
}
/******************************************************************/
int unexportGPIO(char* pchPin)
{
	int iRet = -1;
	int iCount = 0;
	int fd = open("/sys/class/gpio/unexport", O_WRONLY);
	if(fd != -1)
	{
		iCount = write(fd,pchPin,strlen(pchPin));
		printf("unexportGPIO : %s %d",pchPin,iCount);
		close(fd);
		iRet = 0;
	}
	return iRet;
}
/******************************************************************/
int setGPIODirection(char* pchPin,char* value)
{
	int iRet = -1;
	int fd;
	char pchBuf[100];
	memset(pchBuf,0,100);
	sprintf(pchBuf,"/sys/class/gpio/gpio%s/direction",pchPin);
	fd = open(pchBuf, O_WRONLY);
	if(fd != -1)
	{
		write(fd, value, strlen(value)); 
		close(fd);
		fd = -1;
		iRet = 0;
	}
	return iRet;
}
/******************************************************************/
int setGPIO(char* pchPin,char* value,int record)
{
	int iRet = -1;
	int iCount = 0;
	int fd;
	char pchBuf[100];
	memset(pchBuf,0,100);
	sprintf(pchBuf,"/sys/class/gpio/gpio%s/value",pchPin);
	fd = open(pchBuf, O_RDWR);
	if(fd != -1)
	{
		iCount = write(fd, value, strlen(value)); 
		//printf("setGPIO : %s %s iRet:%d",pchBuf,value,iCount);
		close(fd);
		fd = -1;
		/*if(iCount > 0 && record==1)
		{
			writeInifileString("GPIO",pchPin,value,g_pIcapDev->pchConfig);
		}*/
		iRet = 0;
	}
	return iRet;
}
/******************************************************************/
int setGPIOEx(char* pchPin,char* value,int record)
{
	int fd = -1;
	char pchBuf[100];
	if(strcmp(value,"1") == 0)
	{
		memset(pchBuf,0,100);
		sprintf(pchBuf,"/sys/class/gpio/gpio%s/value",pchPin);
		fd = open(pchBuf,O_RDWR);
		if(fd != -1)
		{
			close(fd);
			return setGPIO(pchPin,value,record);
		}
		return 0;
	}
	else
	{
		if(exportGPIO(pchPin) == 0)
			setGPIODirection(pchPin,"out");
		return setGPIO(pchPin,value,record);
	}
}
/******************************************************************/
int getGPIO(char* pchPin)
{
	int iRet = -1;
	int iCount = 0;
	int fd;
	char pchBuf[100];
	char pchValue[10];
	memset(pchBuf,0,100);
	sprintf(pchBuf,"/sys/class/gpio/gpio%s/value",pchPin);
	fd = open(pchBuf, O_RDWR);
	if(fd != -1)
	{
		memset(pchValue,0,10);
		iCount = read(fd, pchValue, 10); 
		//printf("getGPIO : %s value:%s",pchBuf,pchValue);
		close(fd);
		if(iCount > 0)
		{
			iRet = atoi(pchValue);
			if(iRet != 0)
			{
				iRet = 1;
			}
		}
	}
	else
	{
		printf("open file error! error=%d\n");
	}
	return iRet;
}
/******************************************************************/
int getGPIOIn(char* pchPin)
{
	setGPIODirection(pchPin,"out");
	setGPIO(pchPin,"1",0);
	setGPIODirection(pchPin,"in");
	return getGPIO(pchPin);
}
/******************************************************************/
