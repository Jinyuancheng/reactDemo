#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#define X1 = (10)
#else
#define X1 = (11)
#endif // DEBUG

#ifndef _TEST_H_
#include "Test.h"
#endif // !_TEST_H_


int main(int argc,char* argv[])
{
	int num = Opt(3, 5, add);
	printf("num = %d\n",num);
	system("pause");
	return 0;
}