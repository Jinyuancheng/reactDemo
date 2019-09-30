#ifndef _STUDENT_H_
#endif
#include "student.h"
#include <stdlib.h>

void MallocMemory(PSTUDENT* pstu)
{
	*pstu = (PSTUDENT)malloc(sizeof(pstu));
}