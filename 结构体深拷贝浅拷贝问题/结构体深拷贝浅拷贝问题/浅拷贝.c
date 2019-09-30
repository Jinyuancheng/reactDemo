#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include <windows.h>
PSTUDENT stu2 = NULL;
/*\ 默认是在栈空间分配内存 \*/
STUDENT stu1;
int main(int argc,char* argv[])
{
	stu1.age = 50;
	printf("stu1.age = %d\n",stu1.age);
	stu2 = (PSTUDENT)malloc(sizeof(PSTUDENT));
	if (stu2 == NULL)
	{
		return -1;
	}
	memset(stu2, 0, sizeof(stu2));
	stu2->id = 0x3c;
	stu2->age = 60;
	printf("stu2.age = %d\n", stu2->age);
	printf("stu2.grade.Math = %f\n",stu2->grade.Math);
	system("pause");
	return 0;
}