#pragma once
#ifndef _THREADPOOL_H_
#define _THREADPOOL_H_

#ifndef _MUTEXANDEVENT_H_
#include "MutexAndEvent.h"
#endif

/*\ ����һ��bool���͵ĺ� \*/
#define false 0
#define true  1

/*\ ���� \*/
typedef struct  
{
	void* (*func)(void*);			//������Ϣ�ĺ���
	void* args;						//������Ϣ�����Ĳ���
}TASK,*PTASK;

/*\ ���������Ϣ \*/
typedef struct  
{
	int queue_front;                         /* ��ͷ */
	int queue_rear;                          /* ��β */
	int queue_size;
	int queue_max_size;                      /* ���������ɵ���������� */
}TASKQUEUE,*PTASKQUEUE;

/*�̳߳ع���*/
typedef struct
{
	ThreadPoolMutex lock;                    /* ��ס�����ṹ�� */
	ThreadPoolMutex thread_counter;          /* ����ʹ��æ�߳���ʱ���� */
	ThreadPoolCond  queue_not_full;          /* ����������������в�Ϊ�� */
	ThreadPoolCond  queue_not_empty;         /* ������в�Ϊ�� */

	ThreadPoolID *threads;                   /* ����̵߳�tid,ʵ���Ͼ��ǹ������� ���� */
	ThreadPoolID admin_tid;                  /* �������߳�tid */
	PTASK task_queue;                        /* ������� */

	TASKQUEUE queue_info;					 /* ���е���Ϣ */
	/*�̳߳���Ϣ*/
	int min_thr_num;                         /* �̳߳�����С�߳��� */
	int max_thr_num;                         /* �̳߳�������߳��� */
	int live_thr_num;                        /* �̳߳��д����߳��� */
	int busy_thr_num;                        /* æ�̣߳����ڹ������߳� */
	int wait_exit_thr_num;                   /* ��Ҫ���ٵ��߳��� */
	 /*�̳߳�״̬*/
	int shutdown;                            /* trueΪ�ر� */
}THREADPOOL,*PTHREADPOOL;

 /****************************************!
 *@brief  ����һ���̳߳�
 *@author Jinzi
 *@date   2019/04/12 11:00:11
 *@param[in]  int _MinThreadNum ��С�߳���
			  int MaxThreadNum  ����߳���
			  int MaxQuequeNum  ���������
 *@param[out] 
 *@return     ����һ���̳߳�(THREADPOOL)
 ****************************************/
THREADPOOL CreateThreadPool(int _MinThreadNum, int MaxThreadNum, int MaxQuequeNum);

#endif