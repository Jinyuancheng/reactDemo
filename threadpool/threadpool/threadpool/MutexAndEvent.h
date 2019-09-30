#pragma once
#ifndef _MUTEXANDEVENT_H_
#define _MUTEXANDEVENT_H_

#ifndef _WINDOWS_
#include <windows.h>
#endif

/*\ 线程池中自定义的变量 \*/
typedef void* ThreadPoolMutex;		//用来定义锁
typedef void* ThreadPoolCond;		//用来定义条件变量（事件）
typedef unsigned int ThreadPoolID;	//定义线程id

/****************************************!
*@brief  初始化互斥锁
*@author Jinzi
*@date   2019/04/12 11:30:37
*@param[in]  _Mutex 要初始化的互斥锁
*@param[out]
*@return 成功返回0
****************************************/
int InitMutex(ThreadPoolMutex* _Mutex)
{
	*_Mutex = CreateMutex(NULL, FALSE, NULL);
	return NULL == *_Mutex ? GetLastError() : 0;
}

 /****************************************!
 *@brief  初始化条件变量
 *@author Jinzi
 *@date   2019/04/12 11:38:52
 *@param[in]  _Cond要初始化的条件变量
 *@param[out] 
 *@return     成功返回0
 ****************************************/
int InitCond(ThreadPoolCond* _Cond)
{
	*_Cond = CreateEvent(NULL, FALSE, FALSE, NULL);
	return NULL == *_Cond ? GetLastError() : 0;
}

#endif // !1

