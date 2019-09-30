// flow_dll.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"

#include <iostream>

#define EXTERN extern "C" __declspec(dllexport)
#define _IN_
#define _OUT_
#define _CALLBACK_

typedef void(*FuncCB)(void*);

FuncCB gl_pCallBack;

EXTERN void StartUp(_CALLBACK_ FuncCB _pCallBack) 
{
	if (_pCallBack != nullptr)
	{
		gl_pCallBack = _pCallBack;
	}
}

EXTERN void CallBack(_IN_ std::string _Data)
{
	if (gl_pCallBack)
	{
		gl_pCallBack((void*)_Data.c_str());
	}
}