#include <iostream>
using namespace std;
//形状
class CShape
{
public:
	CShape()
	{
		m_fArea = -1;
		m_fPerimeter = -1;
	}
	~CShape() {}
public:
	virtual void CalcuArea() = 0;		//计算面积
	virtual void CalcuPerimeter() = 0;	//计算周长
public:
	float m_fArea;		//面积
	float m_fPerimeter; //周长
};
//圆
class CCircle :public CShape
{
public:
	CCircle(float _fRadius) :m_fRadius(_fRadius) {}
	~CCircle() {}
public:
	void CalcuArea()
	{
		m_fArea = 3.14f * m_fRadius * m_fRadius;
	}
	void CalcuPerimeter()
	{
		m_fPerimeter = 2 * 3.14f * m_fRadius;
	}
private:
	float m_fRadius;	//半径
};
//长方形
class CRect : public CShape
{
public:
	CRect(float _fLong, float _fWidth) :m_fLong(_fLong), m_fWidth(_fWidth) {}
	~CRect() {}
public:
	void CalcuArea()
	{
		m_fArea = m_fLong * m_fWidth;
	}
	void CalcuPerimeter()
	{
		m_fPerimeter = 2 * (m_fLong + m_fWidth);
	}
private:
	float m_fLong;		//长
	float m_fWidth;		//宽
};
//三角形
class CTrigon :public CShape
{
public:
	CTrigon(float _fHeight, float _fBottom) :m_fHeight(_fHeight), m_fBoottom(_fBottom) {}
	~CTrigon() {}
public:
	void CalcuArea()
	{
		m_fArea = (m_fHeight * m_fBoottom) / 2;
	}
	void CalcuPerimeter()
	{
		m_fPerimeter = 2 * (m_fHeight + m_fBoottom);
	}
private:
	float m_fHeight;	//三角形高
	float m_fBoottom;	//三角形底
};

int main(int argc, char *argv[])
{
	CCircle* oCircle = new CCircle(10);
	CRect* oRect = new CRect(10, 20);
	CTrigon* oTrigon = new CTrigon(10, 20);

	oCircle->CalcuArea();

	std::cout << "oCircle : " << oCircle->m_fArea << std::endl;

	system("pause");
	return 0;
}