#pragma once
#ifndef _READPIC_H_
#define _READPIC_H_

#include <iostream>
#using "../bin/ReadPicDll.dll"

#define EXTERN extern "C" _declspec(dllexport)

using namespace std;
using namespace ReadPicDll;


 /****************************************!
 *@brief  ��ȡͼƬ��Ϣ���ڴ���
 *@author Jinzi
 *@date   2019/09/19 17:22:55
 *@param[in]  
	_cchpPicPath	:	ͼƬ·��
	_chpSavePicInfo	:	���ݹ����ĵ�ַ �����洢����
	_ipPicInfoLen	:	���ݵĳ���
 *@param[out] 
 *@return     
 ****************************************/
EXTERN bool ReadPictureInfo(const char* _cchpPicPath, std::string& _sSavePicInfo);

#endif // !1
