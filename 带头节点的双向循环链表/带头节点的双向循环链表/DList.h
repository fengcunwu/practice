#ifndef __DLIST_H__
#define __DLIST_H__

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int DataType;

typedef struct DList
{
	DataType data;
	struct DList* pNext;
	struct DList* pPre;
}DList;

//////////////////////////////////////////////////////////////
//带头结点的双向循环链表

void InitDList(DList** pHead);
void PrintDList(DList* pHead);
DList* BuyNode(DataType data);
void PushBackDList(DList* pHead, DataType data);
void PopBackDList(DList* pHead);
void PushFrontDList(DList* pHead, DataType data);
void PopFrontDList(DList* pHead);
void InsertDList(DList* pos, DataType data);
void EraseDList(DList* pos);
DList* FindDList(DList* pHead, DataType data);
void DestroyDList(DList** pHead);

#endif //__DLIST_H__