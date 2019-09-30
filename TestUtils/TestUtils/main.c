#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jinzi_utils.h"

int main(int argc,char* argv[])
{
	
	char str[] = "192.168.1.146";
	char* Str[4];
	Split(str, ".", Str);
	printf("%s\n",Str[0]);
	printf("%s\n",Str[1]);
	printf("%s\n",Str[2]);
	printf("%s\n",Str[3]);
	system("pause");
	return 0;
}