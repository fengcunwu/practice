#include "Hash.h"

void InitHashTable(HashTable* pHT)//��ʼ����ϣ��
{
	int i = 0;
	assert(pHT);
	for (i = 0; i < MAXSIZE; i++)//��ʼ����ϣ����ǰѹ�ϣ��ÿ��λ�����״̬�ĳɿ�
		pHT->array[i].state = EMPTY;
	pHT->size = 0;//�ѹ�ϣ��Ĵ�С��Ϊ0
}

int HashFun(HTDataType data)//��ϣ����ʵ��
{
	return data % MAXSIZE;
}

void InsertHashTable(HashTable* pHT, HTDataType data)//����Ԫ��
{
	int ret = 0;
	assert(pHT);

	ret = HashFun(data);//�ȼ�������λ�ã��ù�ϣ��������

	while (pHT->array[ret].state != EMPTY)//
	{
		if (pHT->array[ret].state == EXIST && pHT->array[ret].data == data)
			//�����ǰλ����Ԫ�ز�������Ϊdata,�Ͳ����벢�ҷ���
			return;
		//��һ��if���û�н�ȥ��������� 1.��ǰλ�õ�״̬��ɾ��״̬
		//2.��ǰλ��������,�����ݲ�Ϊdata��ret++�����
		//3.��ǰλ�õ�״̬Ϊ ɾ�� ret++ҲҪ�����
		ret++;
		if (ret == MAXSIZE)//���ret�������ֵӦ��������ͷ��ʼ������
			ret = 0;
	}
	//������ѭ����˵���ҵ��ˣ����˽��в������
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
	printf("�������ڹ�ϣ���ڲ�����,�޷�ɾ��������\n");
	return;
}

int FindHashTable(HashTable* pHT, HTDataType data)
{
	int ret = 0;
	assert(pHT);
	if (IsEmptyHashTable(pHT))
	{
		printf("�ù�ϣ��Ϊ�գ��޷����ң�����\n");
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

int HashFun_(HashTable* pHT, HTDataType data)//��ϣ������ʵ��
{
	assert(pHT);
	return data % pHT->capacity;
}

void InitHashTable_(HashTable* pHT, int capacity, PDToInt pDToInt)//��ϣ��ĳ�ʼ��
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

void CleakCapacity(HashTable* pHT)//�Թ�ϣ������
{
	HTElem* pNew;
	int i = 0;
	int Oldcapacity = pHT->capacity;
	int Newcapacity = GetNextPrime(Oldcapacity);
	assert(pHT);
	//���ٿռ䣬�¿ռ��Ǿɿռ�Ķ���
	pNew = (HTElem*)malloc(sizeof(HTElem)* Newcapacity);
	if (pNew == NULL)//���ٿռ�������м��
	{
		assert(0);
		return;
	}
	//���ٳɹ�
	
	for (i = 0; i < Newcapacity; i++)
		pNew[i].state = EMPTY;
	pHT->capacity = Newcapacity;
	pHT->size = 0;
	pHT->total = 0;
   //����Ԫ�أ�ֻ����״̬Ϊexist��Ԫ��
	  //�����ɵĹ�ϣ����Ԫ��һ��һ�������ȥ
	for (i = 0; i < Oldcapacity; i++)
	{
		if (pHT->array[i].state == EXIST)
		{
			int ret = HashFun_(pHT, pHT->array[i].data);
			while (pNew[ret].state != EMPTY)
			{
				//�ӾɵĹ�ϣ�������Ԫ�أ������ж�Ԫ����ֵ�Ƿ����
				ret++;
				if (ret == pHT->capacity)
					ret = 0;
			}
			//�ҵ�����λ��
			pNew[ret].data = pHT->array[i].data;
			pNew[ret].state = EXIST;
			pHT->size++;
			pHT->total++;
		}
	}
	//�ͷžɿռ�
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
	printf("�������ڹ�ϣ���ڲ�����,�޷�ɾ��������\n");
	return;
}

void InsertHashTable_(HashTable* pHT, HTDataType data)//��ϣ��Ĳ���
{
	int ret = 0;//�������λ�õ������±�
	assert(pHT);
	
	if ((pHT->total * 10) / pHT->capacity >= 7)//�������Ӵ���0.7
		CleakCapacity(pHT);//��Ҫ����

	ret = HashFun_(pHT, data);

	while (pHT->array[ret].state != EMPTY)
	{
		if (pHT->array[ret].state == EXIST && pHT->array[ret].data == data)
		{
			printf("Ҫ����������Ѿ����ڣ�������Ҫ���룡��\n");
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
	//���ٿռ�,һ��ֵΪdata�Ľڵ�
	pNewNode = BuyNodeHashBucket(data);

	//����Ҫ��ŵĹ�ϣ��ַ
	ret = HashFun(data);

	if (pHB->array[ret] == NULL)//���±�Ϊ�գ���û�д������
	{
		pHB->array[ret] = pNewNode;
	}
	else//�±겻Ϊ�� ͷ�巨�ѽڵ�����ȥ
	{
		pNewNode->next = pHB->array[ret];
		pHB->array[ret] = pNewNode;
	}

	pHB->size++;
}

void DeleteHashBucket(HashBucket* pHB, HTDataType data)//ɾ����ϣͰ�е�����
{
	int ret = 0;
	pList pCur = NULL;
	pList pPre = NULL;
	assert(pHB);

	ret = HashFun(data);//�����ϣ��ַ

	if (pHB->array[ret] == NULL)//�ù�ϣ��ַ��ŵ���NULL��˵�������ݲ��ٹ�ϣͰ��
	{
		printf("�����ݲ��ڹ�ϣͰ���\n");
		return;
	}

	pCur = pHB->array[ret];
	pPre = pCur;

	if (pCur->data == data)//��һ���ڵ�Ϊɾ���ڵ�
	{
		pHB->array[ret] = pCur->next;
		free(pCur);
		pCur = NULL;
		pHB->size--;
	}
	else//ɾ���Ĳ�Ϊ��һ���ڵ�
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
		printf("�����ݲ��ڹ�ϣͰ���\n");
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
			printf("��%d��Ͱ��", i);
			pCur = pHB->array[i];
			while (pCur)
			{
				printf("%d ", pCur->data);
				pCur = pCur->next;
			}
			printf("\n");
		}
		else
			printf("��%d��Ͱ��NULL\n", i);
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
