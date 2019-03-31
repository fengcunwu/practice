#include "HashBucketCapacity.h"

void InitHashBC(HashBC* pHBC, int capacity/*, PDToInt pDTInt*/)//初始化
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

	//每个位置变成空
	for (i = 0; i < capacity; i++)
		pHBC->table[i] = NULL;


	pHBC->size = 0;
	pHBC->capacity = capacity;
	//pHBC->pDTInt = pDTInt;
}

void InsertHashBC(HashBC* pHBC, HBCDataType data)//插入
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
			printf("插入的数据已经存在，不再插入！！！\n");
			return;
		}
		pCur = pCur->next;
	}

	pNewNode = BuyHashBucketNode(data);

	//头插法
	pNewNode->next = pHBC->table[ret];
	pHBC->table[ret] = pNewNode;
	pHBC->size++;

}

void DeleteHashBC(HashBC* pHBC, HBCDataType data)//删除
{
	pList pCur = NULL;
	pList pDel = NULL;
	int ret = 0;

	assert(pHBC);

	ret = HashBucketFunc(pHBC, data);
	pCur = pHBC->table[ret];
	while (pCur)
	{
		//删除数据在第一个位置
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
	printf("该数据在哈希桶里不存在！！！无法删除！！！\n");
}

int FindHashBC(HashBC* pHBC, HBCDataType data)//查找
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

int SizeHashBC(HashBC* pHBC)//返回大小
{
	assert(pHBC);
	return pHBC->size;
}

int IsEmptyHashBC(HashBC* pHBC)//返回是否为空 返回0不为空，返回1 为空
{
	assert(pHBC);
	return 0 == pHBC->size;
}

void DestoryHashBC(HashBC* pHBC)//销毁
{
	;
}

int HashBucketFunc(HashBC* pHBC, HBCDataType data)//哈希函数
{
	assert(pHBC);
	//return pHBC->pDTInt(data) % pHBC->capacity;
	return data % pHBC->capacity;
}

pList BuyHashBucketNode(HBCDataType data)//创建一个新的节点
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
		printf("第%d号桶的数据为：", i);
		while (pCur)
		{
			printf("%d->", pCur->data);
			pCur = pCur->next;
		}
		printf("NULL\n");
	}

}