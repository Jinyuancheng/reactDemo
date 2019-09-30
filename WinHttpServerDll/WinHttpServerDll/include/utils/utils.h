/****************************************************************

						��װ�Ĺ�����
	
****************************************************************/
#pragma once
#ifndef _UTILS_H_
#define _UTILS_H_
#include <stdio.h>
#include <string.h>

//ʵ��ģ����ĵ���ģʽ
template<class T>
class Singleton
{
public:
	//�õ�һ������
	static T* GetInstance()
	{
		static T* instance;
		if (instance == NULL)
		{
			instance = new T();
		}
		return instance;
	}
	//�ͷſռ�
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


