/**************************************************************
 * @file main.cpp
 * @date 2019/08/27 15:50
 * @author Jinzi
 * @Contact: 2493349541@qq.com
 * @brief ��demo�������Գ������Ӧ��
***************************************************************/
#include <iostream>
using namespace std;

/*\ ��״������ \*/
class CXingZhuang
{
public:
	/*\ ������״����� \*/
	virtual void virlCalcArea() = 0;
	/*\ ������״���ܳ� \*/
	virtual void virlCalPerimeter() = 0;
protected:
	double m_dbArea;		/*\ ��״����� \*/
	double m_dbPerimeter;	/*\ ��״���ܳ� \*/
};

/*\ ��� \*/
class CPoint
{
public:
	CPoint(double _dbPosX, double _dbPosY) :
		m_dbPosX(_dbPosX), m_dbPosY(_dbPosY) {}
private:
	double m_dbPosX;	/*\ ��x���� \*/
	double m_dbPosY;	/*\ ��y���� \*/
};

/*\ ��Բ \*/
class CYuan :public CXingZhuang
{
#define PAI	3.14
public:
	CYuan(double _dbBanJing, double _dbPosX, double _dbPosY) :
		m_dbBanJing(_dbBanJing), m_dbPosX(_dbPosX), m_dbPosY(_dbPosY) {};
	CYuan(CYuan& _oYuan)
	{
		this->m_dbBanJing = _oYuan.m_dbBanJing;
		this->m_dbPosX = _oYuan.m_dbPosX;
		this->m_dbPosY = _oYuan.m_dbPosY;
	}
public:
	/*\ ���������== \*/
	bool operator==(CYuan& _oYuan)
	{
		bool bIsEqual = false;
		if (this->m_dbBanJing == _oYuan.m_dbBanJing &&
			this->m_dbPosX == _oYuan.m_dbPosX &&
			this->m_dbPosY == _oYuan.m_dbPosY)
		{
			bIsEqual = true;
		}
		return bIsEqual;
	}
	/*\ ���������< \*/
	bool operator<(CYuan& _oYuan)
	{
		bool bIsEqual = false;
		if (this->m_dbBanJing < _oYuan.m_dbBanJing)
		{
			bIsEqual = true;
		}
		return;
	}
public:
	/*\ ��д���෽�� \*/
	void virlCalcArea() { m_dbArea = PAI * m_dbBanJing * m_dbBanJing; }
	/*\ ��д���෽�� \*/
	void virlCalPerimeter() { m_dbPerimeter = 2 * PAI * m_dbBanJing; }
	/*\ �жϵ��Ƿ���Բ�� \*/
	bool JuageIsPointOnYuan(CPoint& _oPoint)
	{

	}
private:
	double m_dbBanJing;		/*\ Բ�İ뾶 \*/
	double m_dbPosX;		/*\ x���� \*/
	double m_dbPosY;		/*\ y���� \*/
};

int main(int argc, char *argv[])
{
	std::string n;
	CYuan* oYuan1 = new CYuan(10, 10, 10);
	CYuan* oYuan2 = new CYuan(10, 20, 20);
	CPoint* oPoint = new CPoint(5, 5);
	oYuan1->JuageIsPointOnYuan(*oPoint);
	oYuan2->JuageIsPointOnYuan(*oPoint);
	system("pause");
	return 0;
}