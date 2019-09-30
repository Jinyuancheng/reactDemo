// WinHttpServerDll.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "../include/http/BasicHttp.h"

//初始化服务器
extern "C" _declspec(dllexport)void Init(const char* _Port)
{
	BasicHttp* iBasicHttp = new BasicHttp();
	//初始化
	iBasicHttp->ManagerInit();
	//绑定监听端口
	iBasicHttp->ManagerBind(_Port);
	//设置http
	iBasicHttp->ManagerSetHttp();
	//轮询
	iBasicHttp->ManagerPoll();
};


