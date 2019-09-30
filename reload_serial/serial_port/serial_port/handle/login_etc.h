#pragma once
#ifndef _LOGIN_ETC_H_
#define _LOGIN_ETC_H_

#ifndef _BOOL_H_
#include "../utils/bool.h"
#endif

#ifndef _SAVEINIFILE_H_
#include "../iniFile/SaveIni.h"
#endif

/*\ ���ý������Ĳ������� \*/
typedef enum CMD
{
	INTERCHANGER_NONE   = -1,		//�൱�ڻָ�Ĭ��
	INTERCHANGER_ONE    = 1,		//��һ��������Ȩģʽ      ���û�ģʽ�²�����
	INTERCHANGER_TWO    = 2,		//�ڶ�������ȫ��ģʽ      ����Ȩģʽ�²�����
	INTERCHANGER_THREE  = 3,		//������ע��Ự	      ��ȫ��ģʽ�²�����
	INTERCHANGER_FOUR   = 4,		//���Ĳ����ûỰ��˵��    ��ȫ��ģʽ�²�����
	INTERCHANGER_FIVE   = 5,		//���岽���ûỰԴ�˿�    ��ȫ��ģʽ�²�����
	INTERCHANGER_SIX    = 6,		//���������ûỰĿ�Ķ˿�  ��ȫ��ģʽ�²�����
	INTERCHANGER_SIX_1	= 600001,	//�������еĵ�һ���˳���ȫ��ģʽ
	INTERCHANGER_SEVEN  = 7,		//���߲�����802.1x��֤	  ��ȫ��ģʽ�²�����
	INTERCHANGER_EIGHT  = 8,		//�ڰ˲����ö˿�		  ��ȫ��ģʽ�²�����
	INTERCHANGER_NINE   = 9,		//�ھŲ������˿�		  ���ӿ�ģʽ�²�����
	INTERCHANGER_TEN    = 10,	    //��ʮ���˳���ȫ��ģʽ	  ���ӿ�ģʽ�²�����
	INTERCHANGER_ELEVEN = 11,	    //��ʮһ������redius��������ȫ��ģʽ�²�����
	INTERCHANGER_TWELVE = 12,		//��ʮ����
}InterChangerCMD;

/*\ ������ʶ״̬ \*/
typedef enum
{
	CMDSTATUS_NONE		= -1,		// Ĭ��״̬��
	CMDSTATUS_INIT		= 0,		// ������������ 
	CMDSTATUS_USER		= 1,		// �����û���״̬ 
	CMDSTATUS_PASS		= 2,		// ��������״̬
	CMDSTATUS_USERMODE	= 3,		// �û�ģʽ״̬
	CMDSTATUS_PRIMODE	= 4,		// ��Ȩģʽ״̬
	CMDSTATUS_GLBMODE	= 5,		// ȫ��ģʽ״̬
	CMDSTATUS_INTERMODE = 6,		// �ӿ�ģʽ״̬
	CMDSTATUS_CONPORT   = 7,			// ���ö˿�״̬
	CMSTSATUS_YES		= 8
}CMDSTATUS;

/****************************************!
*@brief  �ж��ַ������������жϽ������Ƿ���سɹ���Ȼ���½
*@author Jinzi
*@date   2019/05/08 8:40:19
*@param[in]  _Fd ���ھ��
			 _InterChanger �洢�����ý���������Ϣ
			 _Ini8021x �洢����8021x����Ϣ
*@param[out]
*@return
****************************************/
void JuageStrOpt(int _Fd, PSAVEINI _InterChanger, PINI8021X _Ini8021x);
/****************************************!
*@brief  ����������Ȩģʽ�²�������������
*@author Jinzi
*@date   2019/05/09 17:44:42
*@param[in]  _Fd ���ھ��
			 _InterChanger �洢�������ļ��еĽ�������Ϣ
			 _Ini8021x	�洢����8021x����Ϣ
*@param[out]
*@return
****************************************/
void OperPriModeCMD(int _Fd, PSAVEINI _InterChanger, PINI8021X _Ini8021x);
/****************************************!
*@brief  ��������ȫ��ģʽ�²�������������
*@author Jinzi
*@date   2019/05/09 17:44:42
*@param[in]  _Fd ���ھ��
			 _InterChanger �洢�������ļ��еĽ�������Ϣ
			 _Ini8021x	�洢����8021x����Ϣ
*@param[out]
*@return
****************************************/
void OperGlobModeCMD(int _Fd, PSAVEINI _InterChanger, PINI8021X _Ini8021x);
/****************************************!
*@brief  ���������û�ģʽ�²�������������(SWITCH>)
*@author Jinzi
*@date   2019/05/09 17:44:42
*@param[in]  _Fd ���ھ��
*@param[out]
*@return
****************************************/
void OperUserModeCMD(int _Fd);
 /****************************************!
 *@brief  ģ���û���¼�������˺ţ�
 *@author Jinzi
 *@date   2019/05/09 17:56:46
 *@param[in]  _Fd ���ھ��
			  _UserName �û���
 *@param[out] 
 *@return     
 ****************************************/
void UserLogin(int _Fd, const char* _UserName);
 /****************************************!
 *@brief  ģ���û���������
 *@author Jinzi
 *@date   2019/05/10 8:23:33
 *@param[in]  _Fd ���ھ��
			  _PassWord �û�����
 *@param[out] 
 *@return     
 ****************************************/
void UserPass(int _Fd, const char* _PassWord);
/****************************************!
*@brief  ��������ָ��
*@author Jinzi
*@date   2019/05/10 8:41:14
*@param[in]  _Fd ���ھ��
			 _Type ��������_OptStat�Ĳ�����Ϣ ��#InterChangerCMD��
			 _Cmd ���͵�ָ��
*@param[out]
*@return
****************************************/
void SendCMD(int _Fd, InterChangerCMD _Type, char* _Cmd);
/****************************************!
*@brief  �������нӿ�ģʽ�²�������������
*@author Jinzi
*@date   2019/05/09 17:44:42
*@param[in]  _Fd ���ھ��
			 _OptStat ����״̬
			 _InterChanger �洢�������ļ��еĽ�������Ϣ
			 _Ini8021x	�洢����8021x����Ϣ
*@param[out]
*@return
****************************************/
void OperInterModeCMD(int _Fd, PSAVEINI _InterChanger, PINI8021X _Ini8021x);
 /****************************************!
 *@brief  ˵�����������ڳ�ʼ������
 *@author Jinzi
 *@date   2019/05/10 11:10:04
 *@param[in]  _Fd���Ǵ��ھ��
 *@param[out] 
 *@return     
 ****************************************/
void InterChangeInitData(int _Fd);
/****************************************!
*@brief  �������нӿ�ģʽ�²�������������
*@author Jinzi
*@date   2019/05/09 17:44:42
*@param[in]  _Fd ���ھ��
			 _OptStat ����״̬
			 _InterChanger �洢�������ļ��еĽ�������Ϣ
			 _Ini8021x	�洢����8021x����Ϣ
*@param[out]
*@return
****************************************/
void OperPortModeCMD(int _Fd, PSAVEINI _InterChanger, PINI8021X _Ini8021x);
#endif
