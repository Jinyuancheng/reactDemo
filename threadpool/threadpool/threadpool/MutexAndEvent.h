#pragma once
#ifndef _MUTEXANDEVENT_H_
#define _MUTEXANDEVENT_H_

#ifndef _WINDOWS_
#include <windows.h>
#endif

/*\ �̳߳����Զ���ı��� \*/
typedef void* ThreadPoolMutex;		//����������
typedef void* ThreadPoolCond;		//�������������������¼���
typedef unsigned int ThreadPoolID;	//�����߳�id

/****************************************!
*@brief  ��ʼ��������
*@author Jinzi
*@date   2019/04/12 11:30:37
*@param[in]  _Mutex Ҫ��ʼ���Ļ�����
*@param[out]
*@return �ɹ�����0
****************************************/
int InitMutex(ThreadPoolMutex* _Mutex)
{
	*_Mutex = CreateMutex(NULL, FALSE, NULL);
	return NULL == *_Mutex ? GetLastError() : 0;
}

 /****************************************!
 *@brief  ��ʼ����������
 *@author Jinzi
 *@date   2019/04/12 11:38:52
 *@param[in]  _CondҪ��ʼ������������
 *@param[out] 
 *@return     �ɹ�����0
 ****************************************/
int InitCond(ThreadPoolCond* _Cond)
{
	*_Cond = CreateEvent(NULL, FALSE, FALSE, NULL);
	return NULL == *_Cond ? GetLastError() : 0;
}

#endif // !1

