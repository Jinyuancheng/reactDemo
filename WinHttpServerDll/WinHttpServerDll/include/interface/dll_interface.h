#pragma once
#ifndef _DLL_INTERFACE_H_
#define _DLL_INTERFACE_H_

#include "../../include/http/BasicHttp.h"

//��ʼ��������
_declspec(dllexport)void Init(const char* _Port)
{
	BasicHttp* iBasicHttp = new BasicHttp();
	//��ʼ��
	iBasicHttp->ManagerInit();
	//�󶨼����˿�
	iBasicHttp->ManagerBind(_Port);
	//����http
	iBasicHttp->ManagerSetHttp();
	//��ѯ
	iBasicHttp->ManagerPoll();
};



#endif
