#pragma once
#ifndef _STUDENT_H_
#define _STUDENT_H_
/*\ ѧ���ɼ� \*/
typedef struct
{
	float Math;			//��ѧ
	float Chinese;      //����
	float English;      //Ӣ��
}GRADE, *PGRADE;

/*\ ѧ����Ϣ \*/
typedef struct
{
	int id;	            //ѧ��id

	int age;            //ѧ������
	char sex[2];        //ѧ���Ա�
	GRADE grade;        //ѧ���ɼ�
}STUDENT, *PSTUDENT;

/*\ �����ڴ� \*/
void MallocMemory(PSTUDENT* pstu);

#endif