#pragma once
#ifndef _TEST_H_
#define _TEST_H_
//����ָ��
typedef int(*Func)(int, int);
//��������
int add(int a, int b);
//����ʵ��
int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
//��������
int Opt(int a, int b, Func func)
{
	return func(a, b);
}

#endif
