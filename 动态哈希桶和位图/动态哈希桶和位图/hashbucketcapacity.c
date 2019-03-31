#include "HashBucketCapacity.h"

void InitHashBC(HashBC* pHBC, int capacity/*, PDToInt pDTInt*/)//��ʼ��
{
	int i = 0;
	assert(pHBC);
	capacity = GetNextPrime(capacity);
	pHBC->table = (pList*)malloc(sizeof(Node)* capacity);
	if (NULL == pHBC->table)
	{
		assert(0);
		return;
	}

	//ÿ��λ�ñ�ɿ�
	for (i = 0; i < capacity; i++)
		pHBC->table[i] = NULL;


	pHBC->size = 0;
	pHBC->capacity = capacity;
	//pHBC->pDTInt = pDTInt;
}

void InsertHashBC(HashBC* pHBC, HBCDataType data)//����
{
	pList pNewNode = NULL;
	pList pCur = NULL;
	int ret = 0;

	assert(pHBC);

	ret = HashBucketFunc(pHBC, data);
	pCur = pHBC->table[ret];

	while (pCur)
	{
		if (pCur->data == data)
		{
			printf("����������Ѿ����ڣ����ٲ��룡����\n");
			return;
		}
		pCur = pCur->next;
	}

	pNewNode = BuyHashBucketNode(data);

	//ͷ�巨
	pNewNode->next = pHBC->table[ret];
	pHBC->table[ret] = pNewNode;
	pHBC->size++;

}

void DeleteHashBC(HashBC* pHBC, HBCDataType data)//ɾ��
{
	pList pCur = NULL;
	pList pDel = NULL;
	int ret = 0;

	assert(pHBC);

	ret = HashBucketFunc(pHBC, data);
	pCur = pHBC->table[ret];
	while (pCur)
	{
		//ɾ�������ڵ�һ��λ��
		if (pCur->data == data)
		{
			if (pHBC->table[ret]->data == data)
			{
				pHBC->table[ret]->next = pCur->next;
				free(pCur);
				pCur = NULL;
			}
			else
			{
				pDel->next = pCur->next;
				free(pCur);
				pCur = NULL;
			}
		}
		pDel = pCur;
		pCur = pCur->next;
	}
	printf("�������ڹ�ϣͰ�ﲻ���ڣ������޷�ɾ��������\n");
}

int FindHashBC(HashBC* pHBC, HBCDataType data)//����
{
	int ret = 0;
	pList pCur = NULL;
	assert(pHBC);

	ret = HashBucketFunc(pHBC, data);

	pCur = pHBC->table[ret];
	while (pCur)
	{
		if (pCur->data == data)
			return 1;

		pCur = pCur->next;
	}
	return 0;
}

int SizeHashBC(HashBC* pHBC)//���ش�С
{
	assert(pHBC);
	return pHBC->size;
}

int IsEmptyHashBC(HashBC* pHBC)//�����Ƿ�Ϊ�� ����0��Ϊ�գ�����1 Ϊ��
{
	assert(pHBC);
	return 0 == pHBC->size;
}

void DestoryHashBC(HashBC* pHBC)//����
{
	;
}

int HashBucketFunc(HashBC* pHBC, HBCDataType data)//��ϣ����
{
	assert(pHBC);
	//return pHBC->pDTInt(data) % pHBC->capacity;
	return data % pHBC->capacity;
}

pList BuyHashBucketNode(HBCDataType data)//����һ���µĽڵ�
{
	pList pNewNode = (pList)malloc(sizeof(Node));
	if (pNewNode == NULL)
	{
		assert(0);
		return NULL;
	}

	pNewNode->data = data;
	pNewNode->next = NULL;

	return pNewNode;
}

unsigned long GetNextPrime(unsigned long capacity)
{
	static unsigned long PrimeList[PRIMEMAXSIZE] =
	{
		11ul, 23ul, 53ul, 193ul, 389ul, 769ul,
		1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
		49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
		1572869ul, 3145739ul, 6291469ul, 12582917ul,
		25165843ul
	};
	int i = 0;

	for (i = 0; i < PRIMEMAXSIZE; i++)
	{
		if (PrimeList[i] > capacity)
			return PrimeList[i];
	}

	return PrimeList[PRIMEMAXSIZE - 1];
}

unsigned long DataToInt(const char* str)
{
	unsigned int seed = 131;
	unsigned int hash = 0;

	while (*str)
	{
		hash = hash * seed + (*str++);
	}
	return (hash & 0x7FFFFFFF);
}

void PrintHashBC(HashBC* pHBC)
{
	int i = 0;
	pList pCur = NULL;
	assert(pHBC);

	for (i = 0; i < pHBC->capacity; i++)
	{
		pCur = pHBC->table[i];
		printf("��%d��Ͱ������Ϊ��", i);
		while (pCur)
		{
			printf("%d->", pCur->data);
			pCur = pCur->next;
		}
		printf("NULL\n");
	}

}