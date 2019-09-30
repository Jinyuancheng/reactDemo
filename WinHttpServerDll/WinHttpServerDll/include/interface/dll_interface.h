#pragma once
#ifndef _DLL_INTERFACE_H_
#define _DLL_INTERFACE_H_

#include "../../include/http/BasicHttp.h"

//初始化服务器
_declspec(dllexport)void Init(const char* _Port)
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



#endif
