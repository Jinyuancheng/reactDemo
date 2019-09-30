#include <iostream>
using namespace std;

class CShuXing
{
public:
	CShuXing(float _fWeight, float _fHeight) :
		m_fWeight(_fWeight), m_fHeight(_fHeight) {}
public:
	friend double JinziTest() { return 10; };
protected:
	float m_fWeight;
	float m_fHeight;
};

class CTest
{
public:
	CTest() {}
protected:
private:
};

class CStudent
{
public:
	CStudent()
	{
		m_opShuXing = new CShuXing(34.4f, 53.4f);
	}
	~CStudent()
	{
		delete[] m_opShuXing;
	}
protected:
private:
	CShuXing* m_opShuXing;
	CTest*	  m_oTest;
};

int main(int argc, char *argv[])
{
	system("pause");
	return 0;
}