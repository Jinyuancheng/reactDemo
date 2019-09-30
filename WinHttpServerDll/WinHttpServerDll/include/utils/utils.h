/****************************************************************

						封装的工具类
	
****************************************************************/
#pragma once
#ifndef _UTILS_H_
#define _UTILS_H_
#include <stdio.h>
#include <string.h>

//实现模板类的单例模式
template<class T>
class Singleton
{
public:
	//得到一个对象
	static T* GetInstance()
	{
		static T* instance;
		if (instance == NULL)
		{
			instance = new T();
		}
		return instance;
	}
	//释放空间
	static void DeleteInstance(T* instance)
	{
		delete[] instance;
		instance = NULL;
	}
};

class utils:public Singleton<utils>
{
public:
	utils();
	~utils();
public:

};

#endif


