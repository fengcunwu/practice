#include "Hash.h"

void InitHashTable(HashTable* pHT)//初始化哈希表
{
	int i = 0;
	assert(pHT);
	for (i = 0; i < MAXSIZE; i++)//初始化哈希表就是把哈希表每个位置里的状态改成空
		pHT->array[i].state = EMPTY;
	pHT->size = 0;//把哈希表的大小改为0
}

int HashFun(HTDataType data)//哈希函数实现
{
	return data % MAXSIZE;
}

void InsertHashTable(HashTable* pHT, HTDataType data)//插入元素
{
	int ret = 0;
	assert(pHT);

	ret = HashFun(data);//先计算插入的位置，用哈希函数计算

	while (pHT->array[ret].state != EMPTY)//
	{
		if (pHT->array[ret].state == EXIST && pHT->array[ret].data == data)
			//如果当前位置有元素并且数据为data,就不插入并且返回
			return;
		//上一步if语句没有进去有三种情况 1.当前位置的状态是删除状态
		//2.当前位置有数据,但数据不为data，ret++向后走
		//3.当前位置的状态为 删除 ret++也要向后走
		ret++;
		if (ret == MAXSIZE)//如果ret等于最大值应该让他从头开始继续找
			ret = 0;
	}
	//能跳出循环就说明找到了，找了进行插入操作
	pHT->array[ret].data = data;
	pHT->array[ret].state = EXIST;
	pHT->size++;
}

void DeleteHashTable(HashTable* pHT, HTDataType data)
{
	int ret = 0;
	assert(pHT);

	ret = HashFun(data);

	while (pHT->array[ret].state != EMPTY)
	{
		if (pHT->array[ret].state == EXIST && pHT->array[ret].data == data)
		{
			pHT->size--;
			pHT->array[ret].state = DELETE;
			return;
		}
			
		ret++;
		if (ret == MAXSIZE)
			ret = 0;
	}
	printf("该数据在哈希表内不存在,无法删除！！！\n");
	return;
}

int FindHashTable(HashTable* pHT, HTDataType data)
{
	int ret = 0;
	assert(pHT);
	if (IsEmptyHashTable(pHT))
	{
		printf("该哈希表为空，无法查找！！！\n");
		return -1;
	}

	ret = HashFun(data);

	while (pHT->array[ret].state != EMPTY)
	{
		if (pHT->array[ret].data == data && pHT->array[ret].state == EXIST)
			return ret;

		ret++;
		if (ret == MAXSIZE)
			ret = 0;
	}
	return -1;
}

int IsEmptyHashTable(HashTable* pHT)
{
	return 0 == pHT->size;
}

int SizeHashTable(HashTable* pHT)
{
	return pHT->size;
}

int HashFun_(HashTable* pHT, HTDataType data)//哈希函数的实现
{
	assert(pHT);
	return data % pHT->capacity;
}

void InitHashTable_(HashTable* pHT, int capacity, PDToInt pDToInt)//哈希表的初始化
{
	int i = 0;
	assert(pHT);
	pHT->array = (HTElem*)malloc(sizeof(HTElem) * capacity);
	if (pHT->array == NULL)
	{
		assert(0);
		return;
	}
	for (i = 0; i < capacity; i++)
		pHT->array[i].state = EMPTY;
	pHT->capacity = capacity;
	pHT->size = 0;
	pHT->total = 0;
	pHT->pDataToInt = pDToInt;
}

void CleakCapacity(HashTable* pHT)//对哈希表扩容
{
	HTElem* pNew;
	int i = 0;
	int Oldcapacity = pHT->capacity;
	int Newcapacity = GetNextPrime(Oldcapacity);
	assert(pHT);
	//开辟空间，新空间是旧空间的二倍
	pNew = (HTElem*)malloc(sizeof(HTElem)* Newcapacity);
	if (pNew == NULL)//开辟空间后对其进行检测
	{
		assert(0);
		return;
	}
	//开辟成功
	
	for (i = 0; i < Newcapacity; i++)
		pNew[i].state = EMPTY;
	pHT->capacity = Newcapacity;
	pHT->size = 0;
	pHT->total = 0;
   //拷贝元素，只搬移状态为exist的元素
	  //遍历旧的哈希表，把元素一个一个插入进去
	for (i = 0; i < Oldcapacity; i++)
	{
		if (pHT->array[i].state == EXIST)
		{
			int ret = HashFun_(pHT, pHT->array[i].data);
			while (pNew[ret].state != EMPTY)
			{
				//从旧的哈希表里搬移元素，不用判断元素数值是否相等
				ret++;
				if (ret == pHT->capacity)
					ret = 0;
			}
			//找到插入位置
			pNew[ret].data = pHT->array[i].data;
			pNew[ret].state = EXIST;
			pHT->size++;
			pHT->total++;
		}
	}
	//释放旧空间
	free(pHT->array);
	pHT->array = pNew;
}

void DeleteHashTable_(HashTable* pHT, HTDataType data)
{
	int ret = 0;
	assert(pHT);

	ret = HashFun_(pHT, data);

	while (pHT->array[ret].state != EMPTY)
	{
		if (pHT->array[ret].state == EXIST && pHT->array[ret].data == data)
		{
			pHT->size--;
			pHT->array[ret].state = DELETE;
			return;
		}

		ret++;
		if (ret == pHT->capacity)
			ret = 0;
	}
	printf("该数据在哈希表内不存在,无法删除！！！\n");
	return;
}

void InsertHashTable_(HashTable* pHT, HTDataType data)//哈希表的插入
{
	int ret = 0;//计算插入位置的数组下标
	assert(pHT);
	
	if ((pHT->total * 10) / pHT->capacity >= 7)//负载因子大于0.7
		CleakCapacity(pHT);//需要扩容

	ret = HashFun_(pHT, data);

	while (pHT->array[ret].state != EMPTY)
	{
		if (pHT->array[ret].state == EXIST && pHT->array[ret].data == data)
		{
			printf("要插入的数据已经存在！！不需要插入！！\n");
			return;
		}
		ret++;
		if (ret == pHT->capacity)
			ret = 0;
	}

	pHT->array[ret].data = data;
	pHT->array[ret].state = EXIST;
	pHT->size++;
	pHT->total++;
}

void PrintHashTable(HashTable* pHT)
{
	int i = 0;
	assert(pHT);
	for (i = 0; i < pHT->capacity; i++)
	{
		if (pHT->array[i].state == EXIST)
			printf(" %d ", pHT->array[i].data);
	}
	printf("\n");
}

void InitHashBucket(HashBucket* pHB)
{
	int i = 0;
	assert(pHB);
	for (i = 0; i < MAXSIZE; i++)
		pHB->array[i] = NULL;
	pHB->size = 0;
}

pList BuyNodeHashBucket(HTDataType data)
{
	pList pNewNode = (pList)malloc(sizeof(List));
	if (pNewNode == NULL)
	{
		assert(0);
		return NULL;
	}
	
	pNewNode->data = data;
	pNewNode->next = NULL;

	return pNewNode;
}

void InsertHashBucket(HashBucket* pHB, HTDataType data)
{
	int ret = 0;
	pList pNewNode = NULL;

	assert(pHB);
	//开辟空间,一个值为data的节点
	pNewNode = BuyNodeHashBucket(data);

	//计算要存放的哈希地址
	ret = HashFun(data);

	if (pHB->array[ret] == NULL)//该下标为空，即没有存放数据
	{
		pHB->array[ret] = pNewNode;
	}
	else//下标不为空 头插法把节点插入进去
	{
		pNewNode->next = pHB->array[ret];
		pHB->array[ret] = pNewNode;
	}

	pHB->size++;
}

void DeleteHashBucket(HashBucket* pHB, HTDataType data)//删除哈希桶中的数据
{
	int ret = 0;
	pList pCur = NULL;
	pList pPre = NULL;
	assert(pHB);

	ret = HashFun(data);//计算哈希地址

	if (pHB->array[ret] == NULL)//该哈希地址存放的是NULL，说明该数据不再哈希桶里
	{
		printf("该数据不在哈希桶里！！\n");
		return;
	}

	pCur = pHB->array[ret];
	pPre = pCur;

	if (pCur->data == data)//第一个节点为删除节点
	{
		pHB->array[ret] = pCur->next;
		free(pCur);
		pCur = NULL;
		pHB->size--;
	}
	else//删除的不为第一个节点
	{
		while (pCur)
		{
			if (pCur->data == data)
			{
				pPre->next = pCur->next;
				free(pCur);
				pCur = NULL;
				pHB->size--;
				return;
			}
			pPre = pCur;
			pCur = pCur->next;
		}
		printf("该数据不在哈希桶里！！\n");
	}
}

void PrintHashBucket(HashBucket* pHB)
{
	int i = 0;
	pList pCur = NULL;
	assert(pHB);

	for (i = 0; i < MAXSIZE; i++)
	{
		if (pHB->array[i] != NULL)
		{
			printf("第%d号桶：", i);
			pCur = pHB->array[i];
			while (pCur)
			{
				printf("%d ", pCur->data);
				pCur = pCur->next;
			}
			printf("\n");
		}
		else
			printf("第%d号桶：NULL\n", i);
	}
}

int FindHashBucket(HashBucket* pHB, HTDataType data)
{
	pList pCur = NULL;
	int ret = 0;
	assert(pHB);

	ret = HashFun(data);

	if (pHB->array[ret] == NULL)
		return -1;

	pCur = pHB->array[ret];

	while (pCur)
	{
		if (pCur->data == data)
			return ret;
		
		pCur = pCur->next;
	}

	return -1;
}

void DestoryHashBucket(HashBucket* pHB)
{
	int i = 0;
	pList pDel = NULL;
	pList pCur = NULL;
	assert(pHB);

	for (i = 0; i < MAXSIZE; i++)
	{
		pCur = pHB->array[i];
		while (pCur)
		{
			pDel = pCur;
			pCur = pCur->next;
			free(pDel);
		}
		pHB->array[i] = NULL;
	}
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
