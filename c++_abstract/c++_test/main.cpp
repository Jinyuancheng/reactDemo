/**************************************************************
 * @file main.cpp
 * @date 2019/08/27 15:50
 * @author Jinzi
 * @Contact: 2493349541@qq.com
 * @brief 该demo用来测试抽象类的应用
***************************************************************/
#include <iostream>
using namespace std;

/*\ 形状抽象类 \*/
class CXingZhuang
{
public:
	/*\ 计算形状的面积 \*/
	virtual void virlCalcArea() = 0;
	/*\ 计算形状的周长 \*/
	virtual void virlCalPerimeter() = 0;
protected:
	double m_dbArea;		/*\ 形状的面积 \*/
	double m_dbPerimeter;	/*\ 形状的周长 \*/
};

/*\ 类点 \*/
class CPoint
{
public:
	CPoint(double _dbPosX, double _dbPosY) :
		m_dbPosX(_dbPosX), m_dbPosY(_dbPosY) {}
private:
	double m_dbPosX;	/*\ 点x坐标 \*/
	double m_dbPosY;	/*\ 点y坐标 \*/
};

/*\ 类圆 \*/
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
	/*\ 重载运算符== \*/
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
	/*\ 重载运算符< \*/
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
	/*\ 重写父类方法 \*/
	void virlCalcArea() { m_dbArea = PAI * m_dbBanJing * m_dbBanJing; }
	/*\ 重写父类方法 \*/
	void virlCalPerimeter() { m_dbPerimeter = 2 * PAI * m_dbBanJing; }
	/*\ 判断点是否在圆上 \*/
	bool JuageIsPointOnYuan(CPoint& _oPoint)
	{

	}
private:
	double m_dbBanJing;		/*\ 圆的半径 \*/
	double m_dbPosX;		/*\ x坐标 \*/
	double m_dbPosY;		/*\ y坐标 \*/
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