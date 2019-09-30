
/**************************************************************
 * @file list.h										  
 * @date 2019/05/17 17:35		
 * @commpany 天津白泽技术有限公司 
 * @author Jinzi                                              
 * @Contact: 2493349541@qq.com							      
 * @brief	实现单向链表 				  
***************************************************************/
#pragma once
#ifndef _JINZI_LIST_H_
#define _JINZI_LIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int UINT;

/*\ 节点属性 \*/
typedef struct
{
	char* pData;	/*\ 节点存储的数据 \*/
	UINT pLen;		/*\ 节点存储数据的大小 \*/
}NODE, *PNODE;

/*\ 链表结构 \*/
typedef struct
{
	PLINK pHead;	/*\ 存储的头，存储指向该节点的地址 \*/
	PNODE pNode;	/*\ 存储的数据 \*/
	PLINK pTail;	/*\ 指向下一个节点的头 \*/
}LINK, *PLINK;

 /****************************************!
 *@brief  创建链表中第一个节点
 *@author Jinzi
 *@date   2019/05/17 17:37:17
 *@param[in]  
 *@param[out] 
 *@return     
 ****************************************/
PLINK CreateLink(void* _Data, UINT _Length);

#endif