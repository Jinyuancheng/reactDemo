#pragma once
#ifndef _TEMPLATE_H_
#define _TEMPLATE_H_
/*\ ����ģʽ ģ���� \*/
template<typename Obj>
class CSingleton
{
public:
	/*\ �õ�obj���͵Ķ��� \*/
	static Obj* GetInstance()
	{
		if (m_instance == nullptr)
		{
			m_instance = new Obj();
		}
		return m_instance;
	}
	//ɾ��obj���͵Ķ���
	static void DelInstance()
	{
		if (m_instance != nullptr)
		{
			delete[] m_instance;
		}
	}
private:
	static Obj*    m_instance;//����Ķ���
};
template<class Obj>
Obj* CSingleton<Obj>::m_instance = nullptr;
#endif
