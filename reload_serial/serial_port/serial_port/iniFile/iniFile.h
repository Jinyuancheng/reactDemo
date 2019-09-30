#pragma once
#ifndef _INIFILE_H_
#define _INIFILE_H_

#include <stdio.h>  
#include <string.h>

/****************************************!
*@brief  得到配置文件中的指定key对应的值
*@author Jinzi
*@date   2019/05/09 10:07:02
*@param[in]  title 配置文件中一组数据的标识
			 key 该组数据中药独处的值的标识
			 filename 要读取的文件路径
			 buf 存储与key值对应的数据
*@param[out]
*@return     成功返回0 失败返回-1
****************************************/
int GetIniKeyString(const char *title,const char *key,const char *filename,const char *buf);
/****************************************!
*@brief  像配置文件中写入数据
*@author Jinzi
*@date   2019/05/09 10:09:43
*@param[in]  title 配置文件中一组数据的标识
			 key 这组数据中的key
			 val 修改后的值
			 filename 文件路径
*@param[out]
*@return     失败返回 -1
****************************************/
int PutIniKeyString(const char *title,const char *key,const char *val,const char *filename);

#endif
