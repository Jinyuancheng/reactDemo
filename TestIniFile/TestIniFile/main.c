#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _INIFILE_H_
#include "iniFile/iniFile.h"
#endif

int main(int argc,char* argv[])
{
	char chTemp[64];
	memset(chTemp, 0, sizeof(chTemp));
	int iRet = PutIniKeyString("TEST", "user", "admin", "./config.ini");
	printf("iRet = %d\n", iRet);
	system("pause");
	return 0;
}