#include <iostream>

#include "fileB.h"

using namespace std;

extern DevInfo* gl_DevInfo;
extern void Init();

int main(int argc, char *argv[])
{
	Init();
	printf("gl_iA : %d\n", gl_DevInfo->iA);
	system("pause");
	return 0;
}