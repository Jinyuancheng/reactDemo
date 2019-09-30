
/**************************************************************
 * @file list.h										  
 * @date 2019/05/17 17:35		
 * @commpany �����������޹�˾ 
 * @author Jinzi                                              
 * @Contact: 2493349541@qq.com							      
 * @brief	ʵ�ֵ������� 				  
***************************************************************/
#pragma once
#ifndef _JINZI_LIST_H_
#define _JINZI_LIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int UINT;

/*\ �ڵ����� \*/
typedef struct
{
	char* pData;	/*\ �ڵ�洢������ \*/
	UINT pLen;		/*\ �ڵ�洢���ݵĴ�С \*/
}NODE, *PNODE;

/*\ ����ṹ \*/
typedef struct
{
	PLINK pHead;	/*\ �洢��ͷ���洢ָ��ýڵ�ĵ�ַ \*/
	PNODE pNode;	/*\ �洢������ \*/
	PLINK pTail;	/*\ ָ����һ���ڵ��ͷ \*/
}LINK, *PLINK;

 /****************************************!
 *@brief  ���������е�һ���ڵ�
 *@author Jinzi
 *@date   2019/05/17 17:37:17
 *@param[in]  
 *@param[out] 
 *@return     
 ****************************************/
PLINK CreateLink(void* _Data, UINT _Length);

#endif