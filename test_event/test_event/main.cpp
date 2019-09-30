#include <iostream>
using namespace std;

typedef void(*Func)(std::string);

class CDingYue
{
public:
	CDingYue() { m_func = nullptr; }
public:
	//订阅
	void Regist(Func _func)
	{
		m_func = _func;
	}
	//事件
	void Event()
	{
		ExecFunc();
	}
	//触发事件执行的函数
	void ExecFunc()
	{
		if (m_func)
		{
			m_func("jinzi");
		}
	}
private:
	Func m_func;
};

void Test(std::string arg)
{
	std::cout << "test : " << arg.c_str() << std::endl;
}

int main(int argc,char *argv[])
{
	CDingYue* dingyue = new CDingYue();
	dingyue->Regist(Test);
	dingyue->Event();
	system("pause");
	return 0;
}