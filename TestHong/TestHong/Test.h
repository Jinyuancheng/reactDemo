#pragma once
#ifndef _TEST_H_
#define _TEST_H_
//函数指针
typedef int(*Func)(int, int);
//函数声明
int add(int a, int b);
//函数实现
int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
//操作函数
int Opt(int a, int b, Func func)
{
	return func(a, b);
}

#endif
