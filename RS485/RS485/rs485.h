/**********************************************************************
* Copyright (C) 2017-2018 天津白泽技术有限公司
* 文件名: rs485.h
* 描述: 设备操作
**********************************************************************/
#ifndef ENVPM_H
#define ENVPM_H
#ifndef _RS485_PROTOCOL_H_
#include "./protocol/lower_rs485.h"
#endif

/************************************************************************/
/*打开设备监测串口                                                      */
/************************************************************************/
int OpenENVPMPort();
/************************************************************************/
/*关闭设备监测串口                                                      */
/************************************************************************/
void CloseENVPMPort(int fd);
/*\ 发送查询状态的指令 \*/
 /****************************************!
 *@brief  发送查询状态指令
 *@author Jinzi
 *@date   2019/06/13 15:49:23
 *@param[in]  _fd 串口句柄
			  _pRecvData 操作成功返回的数据
			  _pRecvBase 操作失败返回的数据
			  _cr_bit 标志位 0x03
			  _data_len 数据长度 0x02
 *@param[out] 
 *@return     
 ****************************************/
int SendSelStatus(int fd, stpLowerStaSelSucc pRecvData, stpLowerSaveBase pRecvBase,
	unsigned char cr_bit, unsigned char data_len);
/*\ 开关控制指令 \*/
 /****************************************!
 *@brief  开关控制指令
 *@author Jinzi
 *@date   2019/06/13 15:50:30
 *@param[in]  fd 串口句柄
			  pRecvBase 返回的操作结果
			  power_number 电源端口序列号	0x01
			  on_or_off 关闭还是开启 0x01 开启 0x00关闭
			  cr_bit 标志位 0x06
			  data_len 数据长度 0x03
 *@param[out] 
 *@return     
 ****************************************/
int SendOnOffContorlCmd(int fd, stpLowerSaveBase pRecvBase, unsigned char power_number,
	unsigned char on_or_off, unsigned char cr_bit, unsigned char data_len);
 /****************************************!
 *@brief  处理电流的操作
 *@author Jinzi
 *@date   2019/06/14 8:45:00
 *@param[in]  elect 存储电流的数组
 *@param[out] 
 *@return     成功返回0 失败返回-1
 ****************************************/
int HandleElect(float* elect);
#endif
