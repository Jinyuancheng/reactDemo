#pragma once
#ifndef _POKENMON_H_
#define _POKENMON_H_

typedef int RACEVALUE;		/*\ ����ֵ���������� \*/
typedef int EFFORTSVALUE;	/*\ Ŭ��ֵ���������� \*/

/*\ ����ֵ \*/
class CRaceValue
{
public:
	CRaceValue();
	~CRaceValue();
protected:
	RACEVALUE m_iLife;		/*\ ���� \*/
	RACEVALUE m_iPAtk;		/*\ �﹥ \*/
	RACEVALUE m_iPDef;		/*\ ��� \*/
	RACEVALUE m_iPSa;		/*\ �ع� \*/
	RACEVALUE m_iPSd;		/*\ �ط� \*/
	RACEVALUE m_iPSpeed;	/*\ �ٶ� \*/
};

/*\ Ŭ��ֵ \*/
class CEffortsValue
{
public:
	CEffortsValue();
	~CEffortsValue();
protected:
	EFFORTSVALUE m_iEffortsLife;	/*\ ���� \*/
	EFFORTSVALUE m_iEffortsPAtk;	/*\ �﹥ \*/
	EFFORTSVALUE m_iEffortsPAtk;	/*\ ��� \*/
	EFFORTSVALUE m_iEffortsPAtk;	/*\ �ع� \*/
	EFFORTSVALUE m_iEffortsPAtk;	/*\ �ط� \*/
	EFFORTSVALUE m_iEffortsPAtk;	/*\ �ٶ� \*/
};



/*\ ���� \*/
class CPokenMon
{
public:
	CPokenMon();
	~CPokenMon();
protected:
	CRaceValue		m_oRaceValue;		/*\ ����ֵ \*/
	CEffortsValue	m_oEffortsValue;	/*\ Ŭ��ֵ \*/
};

#endif
