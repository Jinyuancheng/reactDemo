#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/time.h>
#include <sys/types.h>

#ifndef __SERIAL_H__
#include "serial/serial.h"
#endif // !__SERIAL_H__


#define CONFIGPATH   "/usr/local/jinzi/config/config.ini"		/*\ 配置文件的路径 \*/
#define BOTELV	115200

int main(int argc, char* argv[])
{
	int iFd;				/*\ 句柄 \*/
	char chBuf[10240];
	/*\ 打开串口 \*/
	iFd = serial_open(2, 115200);
	if (iFd < 0)
	{
		printf("Serial Port Open Error\n");
		goto ERR;
	}
	printf("Open Serial Port Success\n");
	/*\ 设置串口的属性 \*/
	serial_set_attr(iFd, 8, PARITY_NONE, 1, FLOW_CONTROL_NONE);
	//set_opt(iFd, 115200, 8, 'N', 1);
	//uart_config(iFd, 115200, 'N', 8, 'S', 1);
	/*\ 设置超时时间 \*/
	//serial_set_timeout(fd, 1);

	/*\ 接收数据等等 \*/
	serial_send(iFd, "\n", 1);
	while (1)
	{
		int iLen = serial_receive(iFd, chBuf, sizeof(chBuf), 10);
		printf("Recv Len : %d\n", iLen);
		printf("Recv Data : %s\n", chBuf);
		if (iLen > 0)
		{
			if (strstr(chBuf, "SWITCH#") != NULL)
			{
				serial_send(iFd, "CONFIGURE", 12);
				usleep(500000);
				serial_send(iFd, " TERMINAL\n ", 12);
				serial_send(iFd, "\r\n", 1);

				usleep(2000000);
				continue;
			}
			else if (strstr(chBuf, "SWITCH(config-if)#") != NULL)
			{
				//dot1x port-control auto
				memset(chBuf, 0, sizeof(chBuf));
				strcpy(chBuf, "dot1x");
				serial_send(iFd, chBuf, strlen(chBuf));
				usleep(500000);
				memset(chBuf, 0, sizeof(chBuf));
				strcpy(chBuf, " port");
				serial_send(iFd, chBuf, strlen(chBuf));
				usleep(500000);
				memset(chBuf, 0, sizeof(chBuf));
				strcpy(chBuf, "-control");
				serial_send(iFd, chBuf, strlen(chBuf));
				usleep(500000);
				memset(chBuf, 0, sizeof(chBuf));
				strcpy(chBuf, " auto\n");
				serial_send(iFd, chBuf, strlen(chBuf));
				usleep(2000000);

			}
			else if (strstr(chBuf, "SWITCH(config-monitor)#") != NULL)
			{
				do 
				{
					//serial_send(iFd, "DESCRI", 6);
					//usleep(500000);
					//serial_send(iFd, "PTION", 5);
					//usleep(500000);
					//serial_send(iFd, " TESTSESSION\n", 15);
					//serial_send(iFd, "\r\n", 1);
					//usleep(2000000);
					////source interface %s rx\n
					//memset(chBuf, 0, sizeof(chBuf));
					//strcpy(chBuf, "SOURCE");
					//serial_send(iFd, chBuf, strlen(chBuf));
					//usleep(500000);
					//memset(chBuf, 0, sizeof(chBuf));
					//strcpy(chBuf, " INTERFACE");
					//serial_send(iFd, chBuf, strlen(chBuf));
					//usleep(500000);
					//memset(chBuf, 0, sizeof(chBuf));
					//strcpy(chBuf, " eth0/1");
					//serial_send(iFd, chBuf, strlen(chBuf));
					//usleep(500000);
					//memset(chBuf, 0, sizeof(chBuf));
					//strcpy(chBuf, " rx\n");
					//serial_send(iFd, chBuf, strlen(chBuf));
					//serial_send(iFd, "\r\n", 1);
					//usleep(2000000);


					//memset(chBuf, 0, sizeof(chBuf));
					//strcpy(chBuf, "DESTI");
					//serial_send(iFd, chBuf, strlen(chBuf));
					//usleep(500000);

					//memset(chBuf, 0, sizeof(chBuf));
					//strcpy(chBuf, "NATION");
					//serial_send(iFd, chBuf, strlen(chBuf));
					//usleep(500000);
					//memset(chBuf, 0, sizeof(chBuf));
					//strcpy(chBuf, " INTERFACE ");
					//serial_send(iFd, chBuf, strlen(chBuf));
					//usleep(500000);

					//memset(chBuf, 0, sizeof(chBuf));
					//strcpy(chBuf, "eth0/8");
					//strcat(chBuf, "\n");
					//serial_send(iFd, chBuf, strlen(chBuf));
					//usleep(500000);

					//serial_send(iFd, "\r\n", 1);

					usleep(2000000);
					serial_send(iFd, "exit\n", 7);
					continue;
				} while (0);
				
			}
			else if (strstr(chBuf, "SWITCH(config)") != NULL)
			{
				/*serial_send(iFd, "MONITOR", 7);
				usleep(500000);
				serial_send(iFd, " SESSION 1\n ", 12);
				serial_send(iFd, "\r\n", 1);*/

				/*memset(chBuf, 0, sizeof(chBuf));
				strcpy(chBuf, "dot1x");
				serial_send(iFd, chBuf, strlen(chBuf));
				usleep(500000);
				memset(chBuf, 0, sizeof(chBuf));
				strcpy(chBuf, " enable\n");
				serial_send(iFd, chBuf, strlen(chBuf));
				usleep(2000000);

				memset(chBuf, 0, sizeof(chBuf));
				strcpy(chBuf, "interface");
				serial_send(iFd, chBuf, strlen(chBuf));
				usleep(500000);

				memset(chBuf, 0, sizeof(chBuf));
				strcpy(chBuf, " eth0/3\n");
				serial_send(iFd, chBuf, strlen(chBuf));*/

				//radius-server host 1.1.1.2 key name
				memset(chBuf, 0, sizeof(chBuf));
				strcpy(chBuf, "radius");
				serial_send(iFd, chBuf, strlen(chBuf));
				usleep(500000);
				memset(chBuf, 0, sizeof(chBuf));
				strcpy(chBuf, "-server");
				serial_send(iFd, chBuf, strlen(chBuf));
				usleep(500000);
				memset(chBuf, 0, sizeof(chBuf));
				strcpy(chBuf, " host");
				serial_send(iFd, chBuf, strlen(chBuf));
				usleep(500000);
				memset(chBuf, 0, sizeof(chBuf));
				strcpy(chBuf, " 1.1.1.2");
				serial_send(iFd, chBuf, strlen(chBuf));
				usleep(500000);
				memset(chBuf, 0, sizeof(chBuf));
				strcpy(chBuf, " key");
				serial_send(iFd, chBuf, strlen(chBuf));
				usleep(500000);
				memset(chBuf, 0, sizeof(chBuf));
				strcpy(chBuf, " name\n");
				serial_send(iFd, chBuf, strlen(chBuf));

				usleep(2000000);
				continue;
			}
			
		}
	}
	serial_close(iFd);
ERR:
	/*\ 关闭文件描述符 \*/
	serial_close(iFd);
	return 0;
}
