#include "Linklist.h"

void Initlinklist(pList* pplist)
{
	assert(pplist);

	*pplist = NULL;
}

void Printflinklist(pList plist)
{
	pNode pCur = plist;
	if (pCur == NULL)
	{
		printf("链表为空,无法打印!!!\n");
	}
	else
	{
		while (pCur != NULL)
		{
			printf("%d->", pCur->data);
			pCur = pCur->next;
		}
		printf("NULL\n");
	}
}

pList Buynode(int data)
{
	pNode pNewnode = (pNode)malloc(sizeof(Node));
	assert(pNewnode);
	pNewnode->data = data;
	pNewnode->next = NULL;
	return pNewnode;
}

void Pushback(pList *pplist, int data)
{
	assert(pplist);

	pNode pNewnode = Buynode(data);
	pNode pCur = *pplist;
	if ((*pplist) == NULL)
	{
		(*pplist) = pNewnode;
	}
	else
	{
		while (pCur->next)
			pCur = pCur->next;

		pCur->next = pNewnode;
	}
}

void Popback(pList *pplist)
{
	pList pCur = *pplist;
	pList pPer = NULL;
	assert(pplist);
	if ((*pplist) == NULL)
		printf("链表为空，无法删除！！！\n");
	else
	{
		while (pCur->next)
		{
			pPer = pCur;
			pCur = pCur->next;
		}
		pPer->next = NULL;
		free(pCur);
	}
}

void Pushfront(pList *pplist, int data)
{
	pNode pNewnode = Buynode(data);
	assert(pplist);
	pNewnode->next = *pplist;
	*pplist = pNewnode;
}

void Popfront(pList *pplist)
{
	pNode pCur = *pplist;
	assert(pplist);

	if (*pplist == NULL)
	{
		printf("链表为空,无法删除!!!\n");
	}
	else
	{
		*pplist = pCur->next;
		pCur->next = NULL;
		free(pCur);
	}
}

pList Find(pList plist, DataType data)
{
	pNode pCur = plist;
	if (plist == NULL)
	{
		printf("链表为空,无法查找!!!\n");
	}
	else
	{
		while (pCur)
		{
			if (pCur->data == data)
				return pCur;
			pCur = pCur->next;
		}
		return NULL;
	}
}

void Insert(pList* pplist, pNode pos, DataType data)
{
	pNode pNewnode = Buynode(data);
	pNode pCur = *pplist;
	pNode pPer = NULL;
	assert(pplist && pos);
	if (*pplist == NULL)
	{
		printf("链表为空,没有找到指定位置");
	}
	else if (pos == *pplist)
	{
		pNewnode->next = *pplist;
		*pplist = pNewnode;
	}
	else
	{
		while (pCur->next != pos)
		{
			pCur = pCur->next;
		}
		pNewnode->next = pos;
		pCur->next = pNewnode;
	}
}

void DestroyLinkList(pList* pplist)
{
	pNode pCur = *pplist;
	pNode pPer = NULL;
	assert(pplist);
	while (pCur)
	{
		pPer = pCur->next;
		free(pCur);
		pCur = NULL;
		pCur = pPer;
	}
}

void Erase(pList* pplist, pNode pos)
{
	pNode pCur = *pplist;

	assert(pplist && pos);
	if (*pplist == NULL)
	{
		printf("链表为空,无法删除!!!\n");
	}
	else if (pos == *pplist)
	{
		*pplist = pos->next;
		free(pos);
	}
	else
	{
		while (pCur->next != pos)
		{
			pCur = pCur->next;
		}
		pCur->next = pos->next;
		free(pos);
	}
}

void Remove(pList* pplist, DataType data)
{
	pNode pCur = *pplist;
	pNode pPer = NULL;
	assert(pplist);
	if (*pplist == NULL)
	{
		printf("链表为空,无法删除!!!\n");
	}
	else if (pCur->data == data)
	{
		*pplist = pCur->next;
		free(pCur);
	}
	else
	{
		while (pCur)
		{
			if (pCur->data == data)
			{
				pPer->next = pCur->next;
				free(pCur);
				break;
			}
			else
			{
				pPer = pCur;
				pCur = pCur->next;
			}
		}
	}
}

void RemoveAll(pList* pplist, DataType data)
{
	pNode pCur = *pplist;
	pNode pPer = NULL;
	pNode pDev = NULL;
	assert(pplist);
	if (*pplist == NULL)
	{
		printf("链表为空，无法删除!!!\n");
	}
	else 
	{
		while (pCur && (pCur->data == data))
		{
			*pplist = pCur->next;
			free(pCur);
			pCur = *pplist;
		}
		while (pCur)
		{
			if (pCur->data == data)
			{
				pDev = pCur->next;
				pPer->next = pDev;
				free(pCur);
				pCur = pDev;
			}
			else
			{
				pPer = pCur;
				pCur = pCur->next;
			}
		}
	}
}

int GetListLength(pList plist)
{
	pNode pCur = plist;
	int count = 0;
	while(pCur)
	{
		pCur = pCur->next;
		count++;
	}
	return count;
	
}

void EraseNotTailNode(pNode pos)
{
	pNode pDev = NULL;
	assert(pos);
	pDev = pos->next;
	DataType tmp = pos->data;
	pos->data = pDev->data;
	pDev->data = tmp;
	pos->next = pDev->next;
}
