/**********************************************************************
* Copyright (C) 2019-2020 �����������޹�˾
* �ļ���: kehua
* ����: ��������ƻ���rs485Э����Ϣ
**********************************************************************/
#pragma once
#ifndef _KEHUA_H_
#define _KEHUA_H_

#define CR				0x0d		/*\ У��λ \*/

/*\ ����Э��ָ�� \*/
typedef enum 
{
	TRANSPOSTCMD_Q1,	    /*\ ups״̬��ѯ���� \*/
	TRANSPOSTCMD_T,		    /*\ ����10���� \*/
	TRANSPOSTCMD_TL,	    /*\ ���Ե��Ƿѹ \*/
	TRANSPOSTCMD_TTIME,		/*\ ���Թ涨ʱ��,��һ���ֽ�Ϊʱ��01-99 T<n>\*/
	TRANSPOSTCMD_Q,		    /*\ ���ط����� \*/
	TRANSPOSTCMD_STIME,		/*\ ���ٷ��Ӻ�ػ�����һ���ֽ�Ϊʱ��0-10 S<n>\*/
	TRANSPOSTCMD_STIMER,	/*\ ���ٷ��Ӻ�ػ���������ٷ��Ӻ��ٿ���S<n>R<m> \*/
	TRANSPOSTCMD_C,		    /*\ ȡ���ػ�ָ�� \*/
	TRANSPOSTCMD_CT,	    /*\ ȡ������ָ�� \*/	
	TRANSPOSTCMD_I,		    /*\ ������Ϣ��ѯָ�� \*/
	TRANSPOSTCMD_F		    /*\ ups���Ϣ��ѯ \*/
}TRANSPOSTCMD;

#endif
