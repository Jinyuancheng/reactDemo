#pragma once
#ifndef _READPIC_H_
#define _READPIC_H_

#include <iostream>
#using "../bin/ReadPicDll.dll"

#define EXTERN extern "C" _declspec(dllexport)

using namespace std;
using namespace ReadPicDll;


 /****************************************!
 *@brief  读取图片信息到内存中
 *@author Jinzi
 *@date   2019/09/19 17:22:55
 *@param[in]  
	_cchpPicPath	:	图片路径
	_chpSavePicInfo	:	传递过来的地址 用来存储数据
	_ipPicInfoLen	:	数据的长度
 *@param[out] 
 *@return     
 ****************************************/
EXTERN bool ReadPictureInfo(const char* _cchpPicPath, std::string& _sSavePicInfo);

#endif // !1
