#include <iostream>
using namespace std;

typedef void(*Func)(std::string);

class CDingYue
{
public:
	CDingYue() { m_func = nullptr; }
public:
	//����
	void Regist(Func _func)
	{
		m_func = _func;
	}
	//�¼�
	void Event()
	{
		ExecFunc();
	}
	//�����¼�ִ�еĺ���
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