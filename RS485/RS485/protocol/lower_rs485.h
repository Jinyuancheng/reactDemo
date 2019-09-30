/**********************************************************************
* Copyright (C) 2018-2019 天津白泽技术有限公司
* 文件名: rs485_protocol
* 描述: 定义与下位机通信的协议
**********************************************************************/
#pragma once
#ifndef _RS485_PROTOCOL_H_
#define _RS485_PROTOCOL_H_

#define RS485_FLAGBIT  0xE55E		/*\ 协议标志位 \*/

/*\ 命令字标志 \*/
typedef enum RS485CMDFLAG
{
	RS485CMDFLAG_SELECT		        = 0x01,		    /*\ 表示状态查询命令 \*/
	RS485CMDFLAG_SELECT_REPLAY		= 0x02,		    /*\ 表示下位机返回的数据命令 \*/
	RS485CMDFLAG_CONTROL	        = 0x03, 		/*\ 开关控制命令 \*/
	RS485CMDFLAG_CONTROL_REPLAY     = 0x04			/*\ 表示开关控制指令的返回结果 \*/
}eRS485CMDFLAG;

/*\ 下位机执行状态查询命令(成功)返回结果 \*/
typedef enum RS485_SELECT_SUCCESS
{
	RS485_SELECT_SUCCESS_AC220V = 0x01,		/*\ 表示AC220V \*/
	RS485_SELECT_SUCCESS_AC24V  = 0X02,		/*\ 表示AC24V \*/
}eRS485_SELECT_SUCCESS;

/*\ 下位机操作结果 \*/
typedef enum RS485_OPT_RESULT
{
	RS485_OPT_RESULT_SUCCESS	= 0x00,		/*\ 表示操作成功 \*/
	RS485_OPT_RESULT_ERROR		= 0x01,		/*\ 表示协议错误 \*/
	RS485_OPT_RESULT_NONE_PORT	= 0x02,		/*\ 表示供电端口不存在 \*/
}eRS485_OPT_RESULT;

/*\ 用来控制开关开启还是关闭 \*/
typedef enum RS485_CONTROL_STATUS
{
	RS485_CONTROL_STATUS_ON		= 0x01,		/*\ 表示开启 \*/
	RS485_CONTROL_STATUS_OFF	= 0x00,		/*\ 表示关闭 \*/
}eRS485_CONTROL_STATUS;

/*\ 状态查询命令的结构体(上位机发送) \*/
typedef struct 
{
	unsigned char chFlagBit[2];	                /*\ 协议标志位 \*/
	unsigned char chDevAddr;		            /*\ 设备地址 \*/
	eRS485CMDFLAG eCmdFlag;	                    /*\ 命令标志 \*/
	unsigned char chDatalen;			        /*\ 数据的长度 （表示chpData的数据长度） \*/
	unsigned char chFixData[2];					/*\ 固定 00 00 \*/
	unsigned char chpData;					    /*\ 数据 （校验  累加和取低8位） \*/
}stStateSelectCmd, *stpStateSelectCmd;

/*\ 开关控制命令（上位机发送） \*/
typedef struct
{
	unsigned char chFlagBit[2];		            /*\ 协议标志位 \*/
	unsigned char chDevAddr;			        /*\ 设备地址 \*/
	eRS485CMDFLAG eCmdFlag;                     /*\ 命令标志 \*/
	unsigned char chDataLen;			        /*\ 数据长度 \*/
	unsigned char chPowerSerN;		            /*\ 供电口序号 \*/
	eRS485_CONTROL_STATUS eOptCmd;	            /*\ 0x01表示开启，0x00表示关闭 \*/
	unsigned char chpData;					    /*\ 数据 \*/
}stSwitchControlCmd, *stpSwitchControlCmd;

/*\ 拥来存储下位机状态查询成功的数据信息 \*/
typedef struct
{
	unsigned char chFlagBit[2];				    /*\ 协议标志位 \*/
	unsigned char chDevAddr;					/*\ 设备地址 \*/
	eRS485CMDFLAG eCmdFlag;			            /*\ 命令标志 \*/
	unsigned char chDataLen;					/*\ 数据长度 \*/
	eRS485_SELECT_SUCCESS eCmdSucc;             /*\ 查询成功返回指令 \*/
	unsigned char chPowerStatus1_8;			    /*\ 供电端口1-8的开关状态 \*/
	unsigned char chPowerStatus9_12;			/*\ 供电端口9-12的开关状态 \*/
	unsigned char chElectData[72];				    /*\ SRC16校验 \*/
}stLowerStaSelSucc, *stpLowerStaSelSucc;

/*\ 用来存储下位机返回的基本数据信息 \*/
typedef struct  
{
	unsigned char chFlagBit[2];				    /*\ 协议标志位 \*/
	unsigned char chDevAddr;					/*\ 设备地址 \*/
	eRS485CMDFLAG eCmdFlag;			            /*\ 命令标志 \*/
	unsigned char chDataLen;					/*\ 数据长度 \*/
	unsigned char chFixData;					/*\ 固定值00 \*/
	eRS485_OPT_RESULT eOptRes;		            /*\ 操作结果 \*/
	unsigned char chData;					    /*\ 校验位 \*/
}stLowerSaveBase, *stpLowerSaveBase;

#endif