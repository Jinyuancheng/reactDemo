/**********************************************************************
* Copyright (C) 2017-2018 天津蔚蓝玄通科技有限公司
* 文件名: envpm.h
* 描述: 环境监测模块
**********************************************************************/
#ifndef ENVPM_H
#define ENVPM_H
/************************************************************************/
/*打开环境监测串口                                                      */
/************************************************************************/
int OpenENVPMPort();
/************************************************************************/
/*关闭环境监测串口                                                      */
/************************************************************************/
void CloseENVPMPort(int fd);
/************************************************************************/
/*修改环境监测地址0x03                                                  */
/************************************************************************/
void SetENVPMAddr(int fd);
/************************************************************************/
/*读取环境监测数据                                                       */
/************************************************************************/
int ReadENVPMData(int fd,unsigned short* data);
 /****************************************!
 *@brief  打开科华串口
 *@author Jinzi
 *@date   2019/06/12 9:33:08
 *@param[in]  _port要打开的串口
 *@param[out] 
 *@return     
 ****************************************/
int OpenKeHuaPort(int _port);
 /****************************************!
 *@brief  关闭打开的串口
 *@author Jinzi
 *@date   2019/06/12 9:37:55
 *@param[in]  _fd 打开的串口句柄
 *@param[out] 
 *@return     
 ****************************************/
void CloseKeHuaPort(int _fd);
 /****************************************!
 *@brief  ups状态请求
 *@author Jinzi
 *@date   2019/06/12 9:40:23
 *@param[in]  _fd 串口句柄
			  _dest 用来存储ups返回的数据
 *@param[out] 
 *@return     
 ****************************************/
void UpsStautsReq(int _fd, char* _dest);
 /****************************************!
 *@brief  用来区分是请求哪个数据
 *@author Jinzi
 *@date   2019/06/12 10:03:59
 *@param[in]  _fd 文件句柄
			  _type 请求ups类型
			  _dest 用来存储ups返回数据
 *@param[out] 
 *@return     
 ****************************************/
void UpsReqCmdType(int _fd, TRANSPOSTCMD _type, char* _dest);
 /****************************************!
 *@brief  ups测试十秒钟
 *@author Jinzi
 *@date   2019/06/12 10:14:24
 *@param[in]  _fd 串口句柄
			  _dest 存储ups返回的数据
 *@param[out] 
 *@return     
 ****************************************/
void UpsTestTenS(int _fd, char* _dest);
/****************************************!
*@brief  ups电池欠压
*@author Jinzi
*@date   2019/06/12 10:14:24
*@param[in]  _fd 串口句柄
			 _dest 存储ups返回的数据
*@param[out]
*@return
****************************************/
void UpsPowerLowerV(int _fd, char* _dest);
/****************************************!
*@brief  ups测试规定时间
*@author Jinzi
*@date   2019/06/12 10:14:24
*@param[in]  _fd 串口句柄
			 _dest 存储ups返回的数据
			 _minute 相隔多长时间
*@param[out]
*@return	
****************************************/
void UpsSetTime(int _fd, char* _dest, unsigned char _minute);
/****************************************!
*@brief  ups开关蜂鸣器
*@author Jinzi
*@date   2019/06/12 10:14:24
*@param[in]  _fd 串口句柄
			 _dest 存储ups返回的数据
*@param[out]
*@return
****************************************/
void UpsOnOffBuzzer(int _fd, char* _dest);
/****************************************!
*@brief  ups多少分钟后关机
*@author Jinzi
*@date   2019/06/12 10:14:24
*@param[in]  _fd 串口句柄
			 _dest 存储ups返回的数据
			 _minute 相隔多长时间
*@param[out]
*@return
****************************************/
void UpsShutDownTime(int _fd, char* _dest, unsigned char _minute);
/****************************************!
*@brief  ups多少分钟后关机，多少分钟后重启
*@author Jinzi
*@date   2019/06/12 10:14:24
*@param[in]  _fd 串口句柄
			 _dest 存储ups返回的数据
			 _sminute 相隔多长时间
			 _reminute 相隔多长时间后开机
*@param[out]
*@return
****************************************/
void UpsSTimeRTime(int _fd, char* _dest, unsigned char _sminute, unsigned char _rminute);
/****************************************!
*@brief  ups取消关机指令
*@author Jinzi
*@date   2019/06/12 10:14:24
*@param[in]  _fd 串口句柄
			 _dest 存储ups返回的数据
*@param[out]
*@return
****************************************/
void UpsCancelSCmd(int _fd, char* _dest);
/****************************************!
*@brief  ups取消测试指令
*@author Jinzi
*@date   2019/06/12 10:14:24
*@param[in]  _fd 串口句柄
			 _dest 存储ups返回的数据
*@param[out]
*@return
****************************************/
void UpsCancelTestCmd(int _fd, char* _dest);
/****************************************!
*@brief  ups厂家信息命令查询
*@author Jinzi
*@date   2019/06/12 10:14:24
*@param[in]  _fd 串口句柄
			 _dest 存储ups返回的数据
*@param[out]
*@return
****************************************/
void UpsSelFactInfo(int _fd, char* _dest);
/****************************************!
*@brief  ups额定值信息查询
*@author Jinzi
*@date   2019/06/12 10:14:24
*@param[in]  _fd 串口句柄
			 _dest 存储ups返回的数据
*@param[out]
*@return
****************************************/
void UpsSelRatedInfo(int _fd, char* _dest);
#endif
