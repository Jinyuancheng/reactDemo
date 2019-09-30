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

#define CONFIGPATH   "/usr/local/jinzi/config/config.ini"		/*\ �����ļ���·�� \*/

int main(int argc, char* argv[])
{
	int iFd;				/*\ ��� \*/
	/*\ ��ʼ�������ļ��� \*/
	if (!InitIniFile(CONFIGPATH))
	{
		return -1;
	}
	/*\ �򿪴��� \*/
	iFd = serial_open(2, 115200);
	if (iFd < 0)
	{
		printf("Serial Port Open Error\n");
		goto ERR;
	}
	printf("Open Serial Port Success\n");
	/*\ ���ô��ڵ����� \*/
	serial_set_attr(iFd, 8, PARITY_NONE, 1, FLOW_CONTROL_NONE);
	/*\ ���ó�ʱʱ�� \*/
	//serial_set_timeout(fd, 1);
	printf("Start Waiting\n");
	/*\ �������ݵȵ� \*/
	JuageStrOpt(iFd, gl_pIniPortMirror, gl_pIni8021X);
	serial_close(iFd);
ERR:
	/*\ �ر��ļ������� \*/
	serial_close(iFd);
	return 0;
}
