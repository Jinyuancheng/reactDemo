#include <iostream>
#include <cmath>
using namespace std;

class CShape
{
public:
	virtual void OptVolume() = 0;
	virtual void OptArea() = 0;
protected:
	float m_fVolume;
	float m_fArea;
};

class CRectangle :public CShape
{
public:
	CRectangle(CRectangle& _Rectangle)
	{
		this->m_fLong = _Rectangle.m_fLong;
		this->m_fWide = _Rectangle.m_fWide;
		this->m_fHeight = _Rectangle.m_fHeight;
	}
	CRectangle(float _fLong, float _fWide, float _fHeight)
		:m_fLong(_fLong), m_fWide(_fWide), m_fHeight(_fHeight) {}
	~CRectangle() {}
public:
	void operator=(CRectangle& _Rectangle)
	{
		this->m_fLong = _Rectangle.m_fLong;
		this->m_fWide = _Rectangle.m_fWide;
		this->m_fHeight = _Rectangle.m_fHeight;
	}
	bool operator==(CRectangle& _Rectangle)
	{
		bool bRet = false;
		if ((this->m_fLong == _Rectangle.m_fLong) &&
			(this->m_fWide == _Rectangle.m_fWide) &&
			(this->m_fHeight == _Rectangle.m_fHeight))
		{
			bRet = true;
		}
		return bRet;
	}
	void operator+(CRectangle& _Rectangle)
	{
		this->m_fLong += _Rectangle.m_fLong;
		this->m_fWide += _Rectangle.m_fWide;
		this->m_fHeight += _Rectangle.m_fHeight;
	}
public:
	void OptVolume() 
	{
		this->m_fVolume = m_fLong * m_fWide * m_fHeight;
	}
	void OptArea() 
	{
		this->m_fArea = (m_fLong * m_fWide) + (m_fLong * m_fHeight) + (m_fWide * m_fHeight);
	}
	float GetVolume()
	{
		return this->m_fVolume;
	}
	float GetArea()
	{
		return this->m_fArea;
	}
private:
	float m_fLong;
	float m_fWide;
	float m_fHeight;
};

class CBall : public CShape
{
public:
	CBall(float _Radius) :m_Radius(_Radius) {}
	CBall(CBall& _Ball)
	{
		this->m_Radius = _Ball.m_Radius;
	}
	~CBall() {}
public:
	void OptVolume()
	{
	}
	void OptArea()
	{

	}
	float GetVolume()
	{
		return m_fVolume;
	}
	float GetArea()
	{
		return m_fArea;
	}
private:
	float m_Radius;
};

int main(int argc, char *argv[])
{
	system("pause");
	return 0;
}