/**********************************************************************
* Copyright (C) 2019-2020 天津白泽技术有限公司
* 文件名: kehua
* 描述: 用来定义科华的rs485协议信息
**********************************************************************/
#pragma once
#ifndef _KEHUA_H_
#define _KEHUA_H_

#define CR				0x0d		/*\ 校验位 \*/

/*\ 定义协议指令 \*/
typedef enum 
{
	TRANSPOSTCMD_Q1,	    /*\ ups状态查询请求 \*/
	TRANSPOSTCMD_T,		    /*\ 测试10秒钟 \*/
	TRANSPOSTCMD_TL,	    /*\ 测试电池欠压 \*/
	TRANSPOSTCMD_TTIME,		/*\ 测试规定时间,下一个字节为时间01-99 T<n>\*/
	TRANSPOSTCMD_Q,		    /*\ 开关蜂鸣器 \*/
	TRANSPOSTCMD_STIME,		/*\ 多少分钟后关机，下一个字节为时间0-10 S<n>\*/
	TRANSPOSTCMD_STIMER,	/*\ 多少分钟后关机，相隔多少分钟后再开机S<n>R<m> \*/
	TRANSPOSTCMD_C,		    /*\ 取消关机指令 \*/
	TRANSPOSTCMD_CT,	    /*\ 取消测试指令 \*/	
	TRANSPOSTCMD_I,		    /*\ 厂家信息查询指令 \*/
	TRANSPOSTCMD_F		    /*\ ups额定信息查询 \*/
}TRANSPOSTCMD;

#endif
