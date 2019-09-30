#pragma once
#ifndef _POKENMON_H_
#define _POKENMON_H_

typedef int RACEVALUE;		/*\ 种族值的数据类型 \*/
typedef int EFFORTSVALUE;	/*\ 努力值的数据类型 \*/

/*\ 种族值 \*/
class CRaceValue
{
public:
	CRaceValue();
	~CRaceValue();
protected:
	RACEVALUE m_iLife;		/*\ 生命 \*/
	RACEVALUE m_iPAtk;		/*\ 物攻 \*/
	RACEVALUE m_iPDef;		/*\ 物防 \*/
	RACEVALUE m_iPSa;		/*\ 特攻 \*/
	RACEVALUE m_iPSd;		/*\ 特防 \*/
	RACEVALUE m_iPSpeed;	/*\ 速度 \*/
};

/*\ 努力值 \*/
class CEffortsValue
{
public:
	CEffortsValue();
	~CEffortsValue();
protected:
	EFFORTSVALUE m_iEffortsLife;	/*\ 生命 \*/
	EFFORTSVALUE m_iEffortsPAtk;	/*\ 物攻 \*/
	EFFORTSVALUE m_iEffortsPAtk;	/*\ 物防 \*/
	EFFORTSVALUE m_iEffortsPAtk;	/*\ 特攻 \*/
	EFFORTSVALUE m_iEffortsPAtk;	/*\ 特防 \*/
	EFFORTSVALUE m_iEffortsPAtk;	/*\ 速度 \*/
};



/*\ 基类 \*/
class CPokenMon
{
public:
	CPokenMon();
	~CPokenMon();
protected:
	CRaceValue		m_oRaceValue;		/*\ 种族值 \*/
	CEffortsValue	m_oEffortsValue;	/*\ 努力值 \*/
};

#endif
