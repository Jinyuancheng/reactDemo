#pragma once
#include "threadpool.h"

PTHREADPOOL CreateThreadPool(int _MinThreadNum, int _MaxThreadNum, int _MaxQuequeNum)
{
	PTHREADPOOL pool = NULL;
	pool = (PTHREADPOOL)malloc(sizeof(PTHREADPOOL));
	if (pool == NULL)
	{
		printf("Create ThreadPool Error\n");
		goto free;
		return (PTHREADPOOL)NULL;;
	}
	/*\ 初始化线程池 \*/
	pool->min_thr_num = _MinThreadNum;
	pool->max_thr_num = _MaxThreadNum;
	pool->busy_thr_num = 0;
	pool->live_thr_num = _MinThreadNum;
	pool->wait_exit_thr_num = 0;
	pool->queue_info.queue_front = 0;
	pool->queue_info.queue_rear = 0;
	pool->queue_info.queue_size = 0;
	pool->queue_info.queue_max_size = _MaxQuequeNum;
	pool->shutdown = false;
	/*\ 给工作线程数组开辟内存空间 \*/
	pool->threads = (ThreadPoolID*)malloc(sizeof(ThreadPoolID) * _MaxThreadNum);
	if (pool->threads == NULL)
	{
		printf("Malloc Memory To ThreadPool->threads Error\n");
		goto free;
		return (PTHREADPOOL)NULL;;
	}
	/*\ 给最大任务数组开辟内存空间 \*/
	pool->task_queue = (PTASK)malloc(sizeof(PTASK) * _MaxQuequeNum);
	if (pool->task_queue == NULL)
	{
		printf("Malloc Memory To task_queue Error\n");
		goto free;
		return (PTHREADPOOL)NULL;;
	}
	/*\ 初始化线程互斥锁 和条件变量\*/
	if (InitMutex(pool->lock) != 0 ||
		InitMutex(pool->thread_counter) != 0 ||
		InitCond(pool->queue_not_empty) != 0 ||
		InitCond(pool->queue_not_full) != 0)
	{
		printf("Init Mutex And Event Error\n");
		goto free;
		return (PTHREADPOOL)NULL;
	}
	/*\ 启动最少的线程数 \*/
	for (int i = 0; i < _MinThreadNum; i++)
	{

	}
	return pool;
free:
	free(pool->task_queue);
	free(pool->threads);
	free(pool);
	pool->task_queue = NULL;
	pool->threads = NULL;
	pool = NULL;

}
