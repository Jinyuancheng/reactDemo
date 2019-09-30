#pragma once
#ifndef _TEMPLATE_H_
#define _TEMPLATE_H_
/*\ 单例模式 模板类 \*/
template<typename Obj>
class CSingleton
{
public:
	/*\ 得到obj类型的对象 \*/
	static Obj* GetInstance()
	{
		if (m_instance == nullptr)
		{
			m_instance = new Obj();
		}
		return m_instance;
	}
	//删除obj类型的对象
	static void DelInstance()
	{
		if (m_instance != nullptr)
		{
			delete[] m_instance;
		}
	}
private:
	static Obj*    m_instance;//自身的对象
};
template<class Obj>
Obj* CSingleton<Obj>::m_instance = nullptr;
#endif
