/**********************************************************************
* Copyright (C) 2018-2019 �����������޹�˾
* �ļ���: rs485_protocol
* ����: ��������λ��ͨ�ŵ�Э��
**********************************************************************/
#pragma once
#ifndef _RS485_PROTOCOL_H_
#define _RS485_PROTOCOL_H_

#define RS485_FLAGBIT  0xE55E		/*\ Э���־λ \*/

/*\ �����ֱ�־ \*/
typedef enum RS485CMDFLAG
{
	RS485CMDFLAG_SELECT		        = 0x01,		    /*\ ��ʾ״̬��ѯ���� \*/
	RS485CMDFLAG_SELECT_REPLAY		= 0x02,		    /*\ ��ʾ��λ�����ص��������� \*/
	RS485CMDFLAG_CONTROL	        = 0x03, 		/*\ ���ؿ������� \*/
	RS485CMDFLAG_CONTROL_REPLAY     = 0x04			/*\ ��ʾ���ؿ���ָ��ķ��ؽ�� \*/
}eRS485CMDFLAG;

/*\ ��λ��ִ��״̬��ѯ����(�ɹ�)���ؽ�� \*/
typedef enum RS485_SELECT_SUCCESS
{
	RS485_SELECT_SUCCESS_AC220V = 0x01,		/*\ ��ʾAC220V \*/
	RS485_SELECT_SUCCESS_AC24V  = 0X02,		/*\ ��ʾAC24V \*/
}eRS485_SELECT_SUCCESS;

/*\ ��λ��������� \*/
typedef enum RS485_OPT_RESULT
{
	RS485_OPT_RESULT_SUCCESS	= 0x00,		/*\ ��ʾ�����ɹ� \*/
	RS485_OPT_RESULT_ERROR		= 0x01,		/*\ ��ʾЭ����� \*/
	RS485_OPT_RESULT_NONE_PORT	= 0x02,		/*\ ��ʾ����˿ڲ����� \*/
}eRS485_OPT_RESULT;

/*\ �������ƿ��ؿ������ǹر� \*/
typedef enum RS485_CONTROL_STATUS
{
	RS485_CONTROL_STATUS_ON		= 0x01,		/*\ ��ʾ���� \*/
	RS485_CONTROL_STATUS_OFF	= 0x00,		/*\ ��ʾ�ر� \*/
}eRS485_CONTROL_STATUS;

/*\ ״̬��ѯ����Ľṹ��(��λ������) \*/
typedef struct 
{
	unsigned char chFlagBit[2];	                /*\ Э���־λ \*/
	unsigned char chDevAddr;		            /*\ �豸��ַ \*/
	eRS485CMDFLAG eCmdFlag;	                    /*\ �����־ \*/
	unsigned char chDatalen;			        /*\ ���ݵĳ��� ����ʾchpData�����ݳ��ȣ� \*/
	unsigned char chFixData[2];					/*\ �̶� 00 00 \*/
	unsigned char chpData;					    /*\ ���� ��У��  �ۼӺ�ȡ��8λ�� \*/
}stStateSelectCmd, *stpStateSelectCmd;

/*\ ���ؿ��������λ�����ͣ� \*/
typedef struct
{
	unsigned char chFlagBit[2];		            /*\ Э���־λ \*/
	unsigned char chDevAddr;			        /*\ �豸��ַ \*/
	eRS485CMDFLAG eCmdFlag;                     /*\ �����־ \*/
	unsigned char chDataLen;			        /*\ ���ݳ��� \*/
	unsigned char chPowerSerN;		            /*\ �������� \*/
	eRS485_CONTROL_STATUS eOptCmd;	            /*\ 0x01��ʾ������0x00��ʾ�ر� \*/
	unsigned char chpData;					    /*\ ���� \*/
}stSwitchControlCmd, *stpSwitchControlCmd;

/*\ ӵ���洢��λ��״̬��ѯ�ɹ���������Ϣ \*/
typedef struct
{
	unsigned char chFlagBit[2];				    /*\ Э���־λ \*/
	unsigned char chDevAddr;					/*\ �豸��ַ \*/
	eRS485CMDFLAG eCmdFlag;			            /*\ �����־ \*/
	unsigned char chDataLen;					/*\ ���ݳ��� \*/
	eRS485_SELECT_SUCCESS eCmdSucc;             /*\ ��ѯ�ɹ�����ָ�� \*/
	unsigned char chPowerStatus1_8;			    /*\ ����˿�1-8�Ŀ���״̬ \*/
	unsigned char chPowerStatus9_12;			/*\ ����˿�9-12�Ŀ���״̬ \*/
	unsigned char chElectData[72];				    /*\ SRC16У�� \*/
}stLowerStaSelSucc, *stpLowerStaSelSucc;

/*\ �����洢��λ�����صĻ���������Ϣ \*/
typedef struct  
{
	unsigned char chFlagBit[2];				    /*\ Э���־λ \*/
	unsigned char chDevAddr;					/*\ �豸��ַ \*/
	eRS485CMDFLAG eCmdFlag;			            /*\ �����־ \*/
	unsigned char chDataLen;					/*\ ���ݳ��� \*/
	unsigned char chFixData;					/*\ �̶�ֵ00 \*/
	eRS485_OPT_RESULT eOptRes;		            /*\ ������� \*/
	unsigned char chData;					    /*\ У��λ \*/
}stLowerSaveBase, *stpLowerSaveBase;

#endif