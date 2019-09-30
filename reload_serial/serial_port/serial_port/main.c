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

#ifndef _LOGIN_ETC_H_
#include "handle/login_etc.h"
#endif

#define CONFIGPATH   "/usr/local/jinzi/config/config.ini"		/*\ 配置文件的路径 \*/

int main(int argc, char* argv[])
{
	int iFd;				/*\ 句柄 \*/
	/*\ 初始化配置文件等 \*/
	if (!InitIniFile(CONFIGPATH))
	{
		return -1;
	}
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
	/*\ 设置超时时间 \*/
	//serial_set_timeout(fd, 1);
	printf("Start Waiting\n");
	/*\ 接收数据等等 \*/
	JuageStrOpt(iFd, gl_pIniPortMirror, gl_pIni8021X);
	serial_close(iFd);
ERR:
	/*\ 关闭文件描述符 \*/
	serial_close(iFd);
	return 0;
}
