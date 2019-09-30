#include <iostream>
using namespace std;

class CStudent
{
public:
	CStudent(int _iId, std::string _sName)
	{
		this->m_iId = _iId;
		this->m_sName = _sName;
	}
	void Print1()
	{
		this->Print();
	}
	void Print()
	{
		std::cout << this->m_iId << std::endl;
		std::cout << this->m_sName.c_str() << std::endl;
	}
	CStudent* GetInstance()
	{
		return this;
	}
	CStudent GetInstance1()
	{
		return *this;
	}
	CStudent& GetInstance2()
	{
		return (*this);
	}
private:
	int m_iId;
	std::string m_sName;
};

int main(int argc, char *argv[])
{
	CStudent* oStu = new CStudent(1, "jinzi");
	oStu->Print();
	oStu->Print1();
	oStu->GetInstance()->Print();
	system("pause");
	return 0;
}