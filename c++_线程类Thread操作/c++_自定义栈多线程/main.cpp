/**************************************************************
 * @file main.cpp
 * @date 2019/08/29 14:56
 * @author Jinzi
 * @Contact: 2493349541@qq.com
 * @brief 封装了多线程共享数据的栈类
***************************************************************/
#include <iostream>
#include <stack>
#include <thread>
#include <mutex>
using namespace std;

template<typename Type>
class CSafeStack
{
public:
	CSafeStack() {}
	CSafeStack(const CSafeStack& _oSafeStack)
	{
		std::lock_guard<std::mutex> oLock(m_oStackMutex);
		m_stackSaveData = _oSafeStack.m_stackSaveData;
	}
public:
	void operator=(CSafeStack&) = delete;
public:
	void push(const Type& _oType)
	{
		std::lock_guard<std::mutex> oLock(m_oStackMutex);
		m_stackSaveData.push(_oType);
	}
	void pop()
	{
		std::lock_guard<std::mutex> oLock(m_oStackMutex);
		m_stackSaveData.pop();
	}
	std::shared_ptr<Type> top()
	{
		std::lock_guard<std::mutex> oLock(m_oStackMutex);
		std::shared_ptr<Type> pType;
		if (!m_stackSaveData.empty())
		{
			pType = std::make_shared<Type>(m_stackSaveData.top());
		}
		return pType;
	}
	bool empty() const
	{
		bool bIsEmpty = false;
		std::lock_guard<std::mutex> oLock(m_oStackMutex);
		if (m_stackSaveData.empty())
		{
			bIsEmpty = true;
		}
		return bIsEmpty;
	}
private:
	std::stack<Type>	m_stackSaveData;
	std::mutex			m_oStackMutex;
};

int main(int argc, char *argv[])
{
	CSafeStack<int> oStack;
	for (int i = 0; i < 10; i++)
	{
		oStack.push(i);
	}
	oStack.pop();
	int iNum1 = *oStack.top();
	std::cout << iNum1 << std::endl;
	system("pause");
	return 0;
}