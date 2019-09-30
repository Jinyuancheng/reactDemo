
#include <windows.h>
#include <stdio.h>
#include <TCHAR.h>

#ifndef _RS485_PROTOCOL_H_
#include "./lower_rs485.h"
#endif

int _tmain(int argc, _TCHAR* argv[])
{
	HANDLE hCom;
	hCom = CreateFile(TEXT("com3"),//COM1��
		GENERIC_READ | GENERIC_WRITE, //�����
		0, //ָ���������ԣ����ڴ��ڲ��ܹ������Ըò�������Ϊ0
		NULL,
		OPEN_EXISTING, //�򿪶����Ǵ���
		FILE_ATTRIBUTE_NORMAL, //������������ֵΪFILE_FLAG_OVERLAPPED����ʾʹ���첽I/O���ò���Ϊ0����ʾͬ��I/O����
		NULL);
	if (hCom == INVALID_HANDLE_VALUE)
	{
		printf("��COMʧ��!\n");
		return FALSE;
	}
	else
	{
		printf("COM�򿪳ɹ���\n");
	}
	SetupComm(hCom, 1024, 1024); //���뻺����������������Ĵ�С����1024
	/*********************************��ʱ����**************************************/
	COMMTIMEOUTS TimeOuts;
	//�趨����ʱ
	TimeOuts.ReadIntervalTimeout = MAXDWORD;//�������ʱ
	TimeOuts.ReadTotalTimeoutMultiplier = 0;//��ʱ��ϵ��
	TimeOuts.ReadTotalTimeoutConstant = 0;//��ʱ�䳣��
	//�趨д��ʱ
	TimeOuts.WriteTotalTimeoutMultiplier = 1;//дʱ��ϵ��
	TimeOuts.WriteTotalTimeoutConstant = 1;//дʱ�䳣��
	SetCommTimeouts(hCom, &TimeOuts); //���ó�ʱ
	/*****************************************���ô���***************************/
	DCB dcb;
	GetCommState(hCom, &dcb);
	dcb.BaudRate = 9600; //������Ϊ115200
	dcb.ByteSize = 8; //ÿ���ֽ���8λ
	dcb.Parity = NOPARITY; //����żУ��λ
	dcb.StopBits = ONESTOPBIT; //һ��ֹͣλ
	SetCommState(hCom, &dcb);

	DWORD wCount;//ʵ�ʶ�ȡ���ֽ���
	bool bReadStat;
	char chBuff[10240];
	while (true)
	{
		memset(chBuff, 0, 10240);
		bReadStat = ReadFile(hCom, chBuff, 10240, &wCount, NULL);
		if (!bReadStat)
		{
			printf("������ʧ��!\n");
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
