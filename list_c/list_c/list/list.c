#ifndef _JINZI_LIST_H_
#include "./list.h"
#endif
/****************************************!
*@brief  创建链表中第一个节点
*@author Jinzi
*@date   2019/05/17 17:37:17
*@param[in]
*@param[out]
*@return
****************************************/
PLINK CreateLink(void* _Data, UINT _Length)
{
	PLINK pLinkHeadNode = (PLINK)malloc(sizeof(LINK));
	if (pLinkHeadNode == NULL)
	{
		goto ERR;
	}
	PNODE pLinkFirstNode = (PNODE)malloc(sizeof(NODE));
	if (pLinkFirstNode == NULL)
	{
		goto ERR;
	}
	pLinkFirstNode->pData = (char*)_Data;
	pLinkFirstNode->pLen = _Length;
	pLinkHeadNode->pHead = NULL;
	pLinkHeadNode->pNode = pLinkFirstNode;
	pLinkHeadNode->pTail = NULL;
	return pLinkHeadNode;
ERR:
	free(pLinkFirstNode);
	free(pLinkHeadNode);
}