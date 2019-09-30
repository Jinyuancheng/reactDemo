

/**************************************************************
 * @file SaveIni.h										  
 * @date 2019/05/09 11:16		
 * @commpany 天津白泽技术有限公司 
 * @author Jinzi                                              
 * @Contact: 2493349541@qq.com							      
 * @brief 该文件是初始化配置文件，将数据存储到内存当中				  
***************************************************************/
#pragma once
#ifndef _SAVEINIFILE_H_
#define _SAVEINIFILE_H_

#ifndef _INIFILE_H_
#include "./iniFile.h"
#endif

#ifndef _BOOL_H_
#include "../utils/bool.h"
#endif

#ifndef _STDLIB_H
#include <stdlib.h>
#endif

/*\ 声明配置文件中的标题[$end] \*/
#define INTERCHANGER		"INTERCHANGER"		/*\ 交换机配置信息 \*/
#define DEV8021X			"DEV8021X"			/*\ 配置802.1x的设备标题 \*/

/*\ 用来存储端口镜像配置文件的信息 \*/
typedef struct  
{
	char chMainPort[64];		/*\ 主干网端口（eth0/1这种类型） \*/
	char chCpuPort[64];			/*\ 主干网映射的端口 将所有接收的数据复制到cpu端口中 \*/
	char chSessDes[64];			/*\ 创建会话的说明 \*/
}SAVEINI,*PSAVEINI;

/*\ 用来存储802.1x配置信息 \*/
typedef struct  
{
	char chIp[64];				/*\ redius服务器的ip地址 \*/
	char chPort[32];			/*\ 端口 \*/
	char chKey[128];			/*\ 系统与redius服务器交互报文时候的共享密钥 \*/	
}INI8021X,*PINI8021X;

///////////////////// BEGIN定义配置文件的全局变量 /////////////////////////////////////////////////////
PSAVEINI					gl_pIniPortMirror;	/*\ 存储端口镜像的配置信息 \*/
PINI8021X					gl_pIni8021X;		/*\ 存储802.1x的配置信息 \*/

///////////////////// END定义配置文件的全局变量 /////////////////////////////////////////////////////

 /****************************************!
 *@brief  初始化配置文件 将配置文件中的数据存储到内存中
 *@author Jinzi
 *@date   2019/05/09 11:22:09
 *@param[in]  _FileName 配置文件的路径-文件名
			  _SaveIni 存储的配置文件的结构体
 *@param[out] 
 *@return     成功返回true 失败返回false
 ****************************************/
int InitIniFile(const char* _FileName);
 /****************************************!
 *@brief  释放存储的配置文件的信息
 *@author Jinzi
 *@date   2019/05/09 15:51:58
 *@param[in]  
 *@param[out] 
 *@return     
 ****************************************/
void DestroyIniFile();
#endif