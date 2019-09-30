#pragma once
#ifndef _THREADPOOL_H_
#define _THREADPOOL_H_

#ifndef _MUTEXANDEVENT_H_
#include "MutexAndEvent.h"
#endif

/*\ 声明一个bool类型的宏 \*/
#define false 0
#define true  1

/*\ 任务 \*/
typedef struct  
{
	void* (*func)(void*);			//处理消息的函数
	void* args;						//处理消息函数的参数
}TASK,*PTASK;

/*\ 任务队列信息 \*/
typedef struct  
{
	int queue_front;                         /* 队头 */
	int queue_rear;                          /* 队尾 */
	int queue_size;
	int queue_max_size;                      /* 队列能容纳的最大任务数 */
}TASKQUEUE,*PTASKQUEUE;

/*线程池管理*/
typedef struct
{
	ThreadPoolMutex lock;                    /* 锁住整个结构体 */
	ThreadPoolMutex thread_counter;          /* 用于使用忙线程数时的锁 */
	ThreadPoolCond  queue_not_full;          /* 条件变量，任务队列不为满 */
	ThreadPoolCond  queue_not_empty;         /* 任务队列不为空 */

	ThreadPoolID *threads;                   /* 存放线程的tid,实际上就是管理了线 数组 */
	ThreadPoolID admin_tid;                  /* 管理者线程tid */
	PTASK task_queue;                        /* 任务队列 */

	TASKQUEUE queue_info;					 /* 队列的信息 */
	/*线程池信息*/
	int min_thr_num;                         /* 线程池中最小线程数 */
	int max_thr_num;                         /* 线程池中最大线程数 */
	int live_thr_num;                        /* 线程池中存活的线程数 */
	int busy_thr_num;                        /* 忙线程，正在工作的线程 */
	int wait_exit_thr_num;                   /* 需要销毁的线程数 */
	 /*线程池状态*/
	int shutdown;                            /* true为关闭 */
}THREADPOOL,*PTHREADPOOL;

 /****************************************!
 *@brief  创建一个线程池
 *@author Jinzi
 *@date   2019/04/12 11:00:11
 *@param[in]  int _MinThreadNum 最小线程数
			  int MaxThreadNum  最大线程数
			  int MaxQuequeNum  最大任务数
 *@param[out] 
 *@return     返回一个线程池(THREADPOOL)
 ****************************************/
THREADPOOL CreateThreadPool(int _MinThreadNum, int MaxThreadNum, int MaxQuequeNum);

#endif