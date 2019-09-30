#pragma once
#ifndef _STUDENT_H_
#define _STUDENT_H_
/*\ 学生成绩 \*/
typedef struct
{
	float Math;			//数学
	float Chinese;      //语文
	float English;      //英语
}GRADE, *PGRADE;

/*\ 学生信息 \*/
typedef struct
{
	int id;	            //学生id

	int age;            //学生年龄
	char sex[2];        //学生性别
	GRADE grade;        //学生成绩
}STUDENT, *PSTUDENT;

/*\ 分配内存 \*/
void MallocMemory(PSTUDENT* pstu);

#endif