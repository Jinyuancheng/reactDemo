
#include "fileB.h"

DevInfo* gl_DevInfo;

void Init()
{
	gl_DevInfo = new DevInfo();
	gl_DevInfo->iA = 10;
	gl_DevInfo->iB = 20;
	gl_DevInfo->iC = 30;
}