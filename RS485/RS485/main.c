#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef ENVPM_H
#include "rs485.h"
#endif
#ifndef GPIO_H
#include "gpio.h"
#endif
//µçÁ÷²Ù×÷
int main(int argc, char* argv[])
{
	float* Elect = (float*)malloc(sizeof(Elect) * 12);
	if (Elect == NULL)
	{
		printf("(float*)malloc(sizeof(Elect) * 12) Error\n");
	}
	HandleElect(Elect);
	return 0;
}
//×´Ì¬
int main1(int argc, char* argv[])
{
	stpLowerSaveBase chBuffBase = (stpLowerSaveBase)malloc(sizeof(stLowerSaveBase));
	exportGPIO(GPIO_RS485_1);
	setGPIODirection(GPIO_RS485_1, "out");
	int SerialFd = OpenENVPMPort();
	SendOnOffContorlCmd(SerialFd, chBuffBase, 0x01, 0x00, 0x07, 0x02);
	int i = 0;
	for (i; i < 8; i++)
	{
		printf("chBuffBase[%d] = %02X\n", i, chBuffBase[i]);
	}
	CloseENVPMPort(SerialFd);
	return 0;
}