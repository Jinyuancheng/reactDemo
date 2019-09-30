#include <iostream>
using namespace std;

class CStudent
{
public:
	CStudent() {}
	void operator=(CStudent& _oStu)
	{
		this->m_iId = _oStu.m_iId;
	}
protected:
private:
	int m_iId;
	std::string m_sName;
};

int main(int argc,char *argv[])
{
	CStudent stu1;
	CStudent stu2;

	stu1 = stu2;

	stu1.operator=(stu2);

	system("pause");
	return 0;
}