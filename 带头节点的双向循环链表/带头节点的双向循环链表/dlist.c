#include "DList.h"

void InitDList(DList** pHead)//����Ͳ����������βεĸı���Դ���ȥ
{
	assert(pHead);

	*pHead = BuyNode(0);

	(*pHead)->pNext = *pHead;
	(*pHead)->pPre = *pHead;
}

DList* BuyNode(DataType data)
{
	DList* pNewNode = (DList*)malloc(sizeof(DList));
	if (pNewNode == NULL)
	{
		printf("���ٿռ�ʧ�ܣ�����\n");
		assert(0);
		return NULL;
	}

	pNewNode->data = data;
	pNewNode->pNext = NULL;
	pNewNode->pPre = NULL;

	return pNewNode;
}

void PushBackDList(DList* pHead, DataType data)
{
	DList* pNewNode = NULL;
	assert(pHead);
	pNewNode = BuyNode(data);

	pNewNode->pPre = pHead->pPre;
	pNewNode->pNext = pHead;
	pHead->pPre = pNewNode;
	pNewNode->pPre->pNext = pNewNode;
}

void PopBackDList(DList* pHead)
{
	DList* pDel = NULL;
	assert(pHead);

	pDel = pHead->pPre;
	if (pDel != pHead)//һ��ͷ��㲻��ɾ��
	{
		pDel->pPre->pNext = pDel->pNext;
		pDel->pNext->pPre = pDel->pPre;
		free(pDel);
		pDel = NULL;
	}
}

void InsertDList(DList* pos, DataType data)
{
	DList* pNewNode = BuyNode(data);
	if (NULL == pos)
	{
		printf("����λ�ò����ڣ���\n");
		return;
	}
	pNewNode->pNext = pos;
	pNewNode->pPre = pos->pPre;
	pos->pPre->pNext = pNewNode;
	pos->pPre = pNewNode;
}

void EraseDList(DList* pos)
{
	if (NULL == pos)
	{
		printf("ɾ��λ�ò����ڣ���\n");
		return;
	}
	pos->pPre->pNext = pos->pNext;
	pos->pNext->pPre = pos->pPre;
	free(pos);
	pos = NULL;
}

DList* FindDList(DList* pHead, DataType data)
{
	DList* pCur = NULL;
	assert(pHead);
	pCur = pHead->pNext;

	while (pCur != pHead)
	{
		if (data == pCur->data)
			return pCur;
		pCur = pCur->pNext;
	}

	return NULL;
}

void PrintDList(DList* pHead)
{
	DList* pCur = NULL;
	if (pHead->pNext == pHead)
	{
		printf("������Ϊ��,�޷���ӡ!!!\n");
		return;
	}
	else
	{
		pCur = pHead->pNext;

		while (pCur != pHead)
		{
			printf("%d->", pCur->data);
			pCur = pCur->pNext;
		}
		printf("NULL\n");
	}
}

void DestroyDList(DList** pHead)
{
	DList* pCur = NULL;
	DList* pDel = NULL;
	assert(pHead);

	if (*pHead == NULL)
	{
		printf("������Ϊ��!!!\n");
		return;
	}
	
	pCur = (*pHead)->pNext;
	while (pCur != (*pHead))
	{
		pDel = pCur;
		pCur = pCur->pNext;
		free(pDel);
		pDel = NULL;
		
	}
}

void PushFrontDList(DList* pHead, DataType data)
{
	DList* pNewNode = BuyNode(data);

	assert(pHead);

	if (pHead->pNext == pHead)
	{
		pHead->pNext = pNewNode;
		pHead->pPre = pNewNode;
		pNewNode->pNext = pHead;
		pNewNode->pPre = pHead;
	}
	else
	{
		pNewNode->pNext = pHead->pNext;
		pNewNode->pPre = pHead;
		pHead->pNext->pPre = pNewNode;
		pHead->pNext = pNewNode;
	}
}

void PopFrontDList(DList* pHead)
{
	DList* pDel = NULL;
	assert(pHead);

	if (pHead->pNext == pHead)
	{
		printf("������Ϊ�գ��޷�ɾ��������\n");
		return;
	}
	else
	{
		pDel = pHead->pNext;
		pHead->pNext = pDel->pNext;
		pDel->pNext->pPre = pHead;
		free(pDel);
		pDel = NULL;
	}
}