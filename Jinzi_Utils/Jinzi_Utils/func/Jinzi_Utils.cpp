// Jinzi_Utils.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#define EXTERNDLL	_declspec(dllexport)

extern "C" EXTERNDLL int Operation(int a, int b, int(*Function)(int, int))
{
	return Function(a, b);
}

extern "C" EXTERNDLL int add(int a,int b)
{
	return a + b;
}

