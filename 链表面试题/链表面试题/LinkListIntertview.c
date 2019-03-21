#include "LinkListInterview.h"

void InitLinkList(pList* pplist)
{
	assert(pplist);
	*pplist = NULL;
}

void PrintLinkList(pList plist)
{
	pNode pCur = plist;
	if (plist == NULL)
	{
		printf("链表为空，无法打印!!!");
	}
	else
	{
		while (pCur)
		{
			printf("%d->", pCur->data);
			pCur = pCur->next;
		}
		printf("NULL\n");
	}
}

pList BuyNode(DataType data)
{
	pNode pNewnode = (pList)malloc(sizeof(struct Linklist));
	if (pNewnode == NULL)
	{
		printf("开辟内存失败!!!");
		return NULL;
	}
	pNewnode->data = data;
	pNewnode->next = NULL;
	return pNewnode;
}

void Pushback(pList* pplist, DataType data)
{
	pNode pCur = *pplist;
	pNode pNewnode = BuyNode(data);
	assert(pplist);
	if (*pplist == NULL)
	{
		*pplist = pNewnode;
	}
	else
	{
		while (pCur->next)
			{
				pCur = pCur->next;
			}
			pCur->next = pNewnode;
	}
}

void PrintTailToHead(pList *pplist)//普通遍历逆置链表
{
	pNode pCur = NULL;
	pNode pCurPre = NULL;
	pNode pNext = NULL;
	assert(pplist);
	pCur = *pplist;
	if (*pplist = NULL)
	{
		printf("链表为空\n");
	}
	else
	{
		while (pCur)
		{
			pNext = pCur->next;
			pCur->next = pCurPre;
			pCurPre = pCur;
			pCur = pNext;
		}
		*pplist = pCurPre;
	}
}

void PrintTailToHead_P(pList* pplist)//头插法逆置链表
{
	pNode pNewNode = NULL;
	pNode pCur = NULL;
	pNode pNext = NULL;
	assert(pplist);
	pCur = *pplist;
	if (*pplist == NULL)
		printf("链表为空,无法逆置!!!");
	else
	{
		while (pCur)
		{
			pNext = pCur->next;
			pCur->next = pNewNode;
			pNewNode = pCur;
			pCur = pNext;
		}
		*pplist = pNewNode;
	}
}

void PrintTailToHead_R(pList plist)//逆置递归
{
	if (NULL == plist)
		return;

	PrintTailToHead_R(plist->next);
	printf("%d->", plist->data);	
}

pList Find(pList plist, DataType data)
{
	pNode pCur = plist;
	if (plist == NULL)
	{
		printf("链表为空,无法查找!!!");
		return NULL;
	}
	while (pCur)
	{
		if (pCur->data == data)
			break;
		pCur = pCur->next;
	}
	if (pCur != NULL)
		return pCur;
	return NULL;

}

void DevNode(pList pos)
{
	pNode pCur = NULL;
	pNode pPre = NULL;
	assert(pos && pos->next);
	pPre =    pos->next;
	pCur = pPre->next;
	pos->next = pCur;
	pos->data = pPre->data;
	free(pPre);
	pos = NULL;
}

void InsertNode(pList pos, DataType data)
{
	pNode pNewnode = BuyNode(data);
	DataType tmp = 0;
	assert(pos);
	pNewnode->next = pos->next;
	pos->next = pNewnode;
	tmp = pNewnode->data;
	pNewnode->data = pos->data;
	pos->data = tmp;
}

pList JosephCycle(pList plist, int k)//约瑟夫环
{
	pNode pTail = NULL;
	pNode pCur = NULL;
	pNode pNext = NULL;
	if (NULL == plist)
	{
		printf("链表为空！！！");
		return NULL;
	}
	//构成环
	pTail = plist;
	pCur = plist;
	while (pTail->next)
		pTail = pTail->next;
	pTail->next = plist;
	//报数和删除
	while (pCur->next != pCur)
	{
		int count = k;
		while (--count)
		{
			pCur = pCur->next;
		}
		pNext = pCur->next;
		pCur->next = pNext->next;
		pCur->data = pNext->data;
	}
	return pCur;
}

void BubbleSort(pList plist)//冒泡排序
{
	pNode pCur = NULL;
	pNode pNext = NULL;
	pNode pTail = NULL;
	DataType tmp = 0;
	int flag = 0;
	if (plist == NULL || plist->next == NULL)
		return;
	while (pTail != plist->next)
	{
		pCur = plist;
		pNext = plist->next;
		while (pNext != pTail)
		{
			if (pCur->data > pNext->data)
			{
				tmp = pCur->data;
				pCur->data = pNext->data;
				pNext->data = tmp;
				flag = 1;
			}
			pCur = pCur->next;
			pNext = pNext->next;
		}
		if (flag == 0)
			break;
		pTail = pCur;
	}
}

pList FindLastKNode(pList plist, int K)//找倒数第k个节点
{
	pNode pFast = plist;
	pNode pSlow = plist;
	if (NULL == plist || K <= 0)//参数判断
		return NULL;

	while (K--)
	{
		//K大于链表中节点个数
		if (pFast == NULL)
			return NULL;

		pFast = pFast->next;
	}

	while (pFast)
	{
		pFast = pFast->next;
		pSlow = pSlow->next;
	}

	return pSlow;
}

pList FindMiddleNode(pList plist)//找中间节点
{
	pNode pFast = plist;
	pNode pSlow = plist;
	pNode pCur = NULL;
	if (NULL == plist)
		printf("链表为空,无法查找!!!");
	while (pFast && pFast->next)
	{
		pCur = pSlow;
		pFast = pFast->next->next;
		pSlow = pSlow->next;
	}
	if (pFast == NULL)
		return pCur;
	else
		return pSlow;
}

void DelTailKNode(pList *pplist, int K)//删除倒数第k个节点
{
	pNode pFast = NULL;
	pNode pSlow = NULL;
	pNode pCur = NULL;

	assert(pplist && K > 0);

	pFast = *pplist;
	pSlow = *pplist;

	while (K--)
	{
		if (pFast != NULL)
			pFast = pFast->next;
		else
			return;
	}

	while (pFast)
	{
		pCur = pSlow;
		pFast = pFast->next;
		pSlow = pSlow->next;
	}
	if (pSlow == *pplist)
		*pplist = pSlow->next;
	else
		pCur->next = pSlow->next;
	free(pSlow);
	pSlow = NULL;
}

pList MergeLinkList(pList pHead1, pList pHead2)//合并两个有序链表
{
	pNode pL1 = pHead1;
	pNode pL2 = pHead2;
	pNode pNewNode = NULL;
	pNode pTail = NULL;
	if (NULL == pHead1)
		return pHead2;

	if (NULL == pHead2)
		return pHead2;

	//if (NULL == pHead1 || NULL == pHead2)
		//return pHead1 ? pHead1 : pHead2;
	//放置头节点
	if (pL1->data < pL2->data)
	{
		pNewNode = pL1;
		pL1 = pL1->next;
	}
	else
	{
		pNewNode = pL2;
		pL2 = pL2->next;
	}
	pTail = pNewNode;
	while (pL1 && pL2)
	{
		if (pL1->data < pL2->data)
		{
			pTail->next = pL1;
			pL1 = pL1->next;
		}
		else
		{
			pTail->next = pL2;
			pL2 = pL2->next;
		}
		pTail = pTail->next;
	}
	if (pL1)
		pTail->next = pL1;
	else
		pTail->next = pL2;
	return pNewNode;
}

int IsListCross(pList pHead1, pList pHead2)//判断是否相交
{
	pNode pTail1 = pHead1;
	pNode pTail2 = pHead2;
	if (NULL == pHead1 || NULL == pHead2)
		return 0;

	while (pTail1->next)
		pTail1 = pTail1->next;

	while (pTail2->next)
		pTail2 = pTail2->next;

	return pTail1 == pTail2;
}

pList GetCrossNode(pList pHead1, pList pHead2)//求相交的节点
{
	int ret = 0;
	int size1 = 0;
	int size2 = 0;
	pNode pCur1 = pHead1;
	pNode pCur2 = pHead2;

	while (pCur1)
	{
		pCur1 = pCur1->next;
		size1++;
	}

	while (pCur2)
	{
		pCur2 = pCur2->next;
		size2++;
	}
	pCur1 = pHead1;
	pCur2 = pHead2;
	ret = size1 - size2;
	if (ret > 0)
	{
		while (ret--)
			pCur1 = pCur1->next;
	}
	else
	{
		while (ret++)
			pCur2 = pCur2->next;
	}
	while (pCur1 != pCur2)
	{
		pCur1 = pCur1->next;
		pCur2 = pCur2->next;
	}
	return pCur2;
}

pList LastNode(pList plist)
{
	pNode pCur = plist;
	if (NULL == plist)
		return NULL;
	else
	{
		while (pCur->next)
			pCur = pCur->next;
		return pCur;
	}
}

pList IsLinkListRing(pList plist)
{
	pNode pFast = plist;
	pNode pSlow = plist;
	if (NULL == plist)
		return NULL;
	else
	{
		while (pFast && pFast->next)
		{
			pFast = pFast->next->next;
			pSlow = pSlow->next;

			if (pFast == pSlow)
				return pSlow;
		}
		return NULL;
	}
}

pList GetRingEnter(pList plist, pNode pMeetNode)
{
	pNode pH = plist;
	pNode pM = pMeetNode;

	if (NULL == plist || NULL == pMeetNode)
		return NULL;

	while (pH != pM)
	{
		pH = pH->next;
		pM = pM->next;
	}
	return pM;
}

int GetRingLength(pList plist, pNode pMeetNode)
{
	int ret = 1;
	pNode pCur = pMeetNode;
	if (NULL == plist || NULL == pMeetNode)
		return 0;
	else
	{
		while (pCur->next != pMeetNode)
		{
			ret++;
			pCur = pCur->next;
		}
		return ret;
	}
}

