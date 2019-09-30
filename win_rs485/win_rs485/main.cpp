
#include <windows.h>
#include <stdio.h>
#include <TCHAR.h>

#ifndef _RS485_PROTOCOL_H_
#include "./lower_rs485.h"
#endif

int _tmain(int argc, _TCHAR* argv[])
{
	HANDLE hCom;
	hCom = CreateFile(TEXT("com3"),//COM1口
		GENERIC_READ | GENERIC_WRITE, //允许读
		0, //指定共享属性，由于串口不能共享，所以该参数必须为0
		NULL,
		OPEN_EXISTING, //打开而不是创建
		FILE_ATTRIBUTE_NORMAL, //属性描述，该值为FILE_FLAG_OVERLAPPED，表示使用异步I/O，该参数为0，表示同步I/O操作
		NULL);
	if (hCom == INVALID_HANDLE_VALUE)
	{
		printf("打开COM失败!\n");
		return FALSE;
	}
	else
	{
		printf("COM打开成功！\n");
	}
	SetupComm(hCom, 1024, 1024); //输入缓冲区和输出缓冲区的大小都是1024
	/*********************************超时设置**************************************/
	COMMTIMEOUTS TimeOuts;
	//设定读超时
	TimeOuts.ReadIntervalTimeout = MAXDWORD;//读间隔超时
	TimeOuts.ReadTotalTimeoutMultiplier = 0;//读时间系数
	TimeOuts.ReadTotalTimeoutConstant = 0;//读时间常量
	//设定写超时
	TimeOuts.WriteTotalTimeoutMultiplier = 1;//写时间系数
	TimeOuts.WriteTotalTimeoutConstant = 1;//写时间常量
	SetCommTimeouts(hCom, &TimeOuts); //设置超时
	/*****************************************配置串口***************************/
	DCB dcb;
	GetCommState(hCom, &dcb);
	dcb.BaudRate = 9600; //波特率为115200
	dcb.ByteSize = 8; //每个字节有8位
	dcb.Parity = NOPARITY; //无奇偶校验位
	dcb.StopBits = ONESTOPBIT; //一个停止位
	SetCommState(hCom, &dcb);

	DWORD wCount;//实际读取的字节数
	bool bReadStat;
	char chBuff[10240];
	while (true)
	{
		memset(chBuff, 0, 10240);
		bReadStat = ReadFile(hCom, chBuff, 10240, &wCount, NULL);
		if (!bReadStat)
		{
			printf("读串口失败!\n");
			continue;
		}
		else
		{
			chBuff[0] = (unsigned char)RS485_FLAGBIT;
			chBuff[1] = 1;
			WriteFile(hCom, chBuff, strlen(chBuff), &wCount, NULL);
		}
		Sleep(100);
	}
	CloseHandle(hCom);
	return 0;
}
