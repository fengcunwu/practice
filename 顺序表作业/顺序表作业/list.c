#include "seqlist.h"

void Initseqlist(pSeqlist pSeq)
{
	assert(pSeq);

	pSeq->sz = 0;
	memset(pSeq->data, 0, sizeof(pSeq->data));
}

void Printflist(pSeqlist pSeq)
{
	int i = 0;
	assert(pSeq);

	for (i = 0; i < pSeq->sz; i++)
	{
		printf("%d ", pSeq->data[i]);
	}
	printf("\n");
}

void Pushback(pSeqlist pSeq, DateType num)
{
	assert(pSeq);
	
	if (pSeq->sz == MAX)
	{
		printf("顺序表已满,无法插入!!!!\n");
		return;
	}

	pSeq->data[pSeq->sz] = num;
	pSeq->sz++;
}

void Popback(pSeqlist pSeq)
{
	assert(pSeq);

	if (pSeq->sz == 0)
	{
		printf("顺序表为空，不能删除！！！");
		return;
	}
	pSeq->sz--;
}

void Pushfount(pSeqlist pSeq, DateType num)
{
	int i = 0;
	assert(pSeq);

	if (pSeq->sz == MAX)
	{
		printf("顺序表已满,无法插入?");
		return;
	}

	for (i = pSeq->sz - 1; i >= 0; i--)
	{
		pSeq->data[i + 1] = pSeq->data[i];
	}
	pSeq->data[0] = num;
	pSeq->sz++;
}

void Popfount(pSeqlist pSeq)
{
	int i = 0;
	assert(pSeq);

	if (pSeq->sz == 0)
	{
		printf("顺序表为空，无法删除！！！");
	}

	for (i = 0; i <= pSeq->sz - 1; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->sz--;
}

int find(pSeqlist pSeq, DateType num)
{
	int i = 0;
	assert(pSeq);

	if (pSeq->sz == 0)
	{
		printf("顺序表为空，无法查找！！！");
		return 0;
	}

	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->data[i] == num)
		{
			return i;
		}
	}
	return -1;
}

void Insert(pSeqlist pSeq, int pos, DateType num)
{
	int i = 0;
	int j = 0;
	assert(pSeq);

	for (i = 0; i < pSeq->sz; i++)
	{
		if (i == pos)
		{
			for (j = pSeq->sz - 1; j >= i; j--)
			{
				pSeq->data[j + 1] = pSeq->data[j];
			}
			pSeq->data[i] = num;
		}
	}
	pSeq->sz++;
}

void Erase(pSeqlist pSeq, int pos)
{
	int i = 0;
	assert(pSeq);

	if (pSeq->sz == 0)
	{
		printf("顺序表为空,无法删除!!!");
	}

	for (i = pos; i < pSeq->sz - 1; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->sz--;
}

void Remove(pSeqlist pSeq, DateType num)
{
	int i = 0;
	int j = 0;
	assert(pSeq);

	if (pSeq->sz == 0)
	{
		printf("顺序表为空,无法删除!!!");
	}

	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->data[i] == num)
		{
			break;
		}
	}
	for (j = i; j < pSeq->sz - 1; j++)
	{
		pSeq->data[j] = pSeq->data[j + 1];
	}
	pSeq->sz--;
}

void RemoveALL(pSeqlist pSeq, DateType num)
{
	int i = 0;
	assert(pSeq);

	if (pSeq->sz == 0)
	{
		printf("顺序表为空,无法删除!!!");
	}

	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->data[i] == num)
		{
			int j = 0;
			for (j = i ; j < pSeq->sz - 1; j++)
			{
				pSeq->data[j] = pSeq->data[j + 1];
			}
			pSeq->sz--;
		}
	}
}

void RemoveALL_OP(pSeqlist pSeq, DateType num)
{
	int i = 0;
	int count = 0;
	assert(pSeq);

	if (pSeq->sz == 0);
	{
		printf("顺序表为空,无法删除!!!!");
	}
	
	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->data[i] != num)
		{
			pSeq->data[count++] = pSeq->data[i];
		}
	}
	pSeq->sz = count;
}

int Size(pSeqlist pSeq)
{
	assert(pSeq);
	return pSeq->sz;
}

int Empty(pSeqlist pSeq)
{
	assert(pSeq);
	if (pSeq->sz != 0);
	{
		return 1;
	}
}

void Swap(DateType* pSeq1, DateType* pSeq2)
{
	DateType tmp;
	assert(pSeq1 && pSeq2);
	tmp = *pSeq1;
	*pSeq1 = *pSeq2;
	*pSeq2 = tmp;
}

void Bubblesort(pSeqlist pSeq)
{
	int i = 0;//确定次数
	int j = 0;//一次交换多少回
	assert(pSeq);

	for (i = 0; i < pSeq->sz; i++)
	{
		for (j = 0; j < pSeq->sz - 1 - i; j++)
		{
			if (pSeq->data[j] < pSeq->data[j + 1])
			{
				Swap(pSeq->data + j, pSeq->data + j + 1);
			}
		}
	}
}

void Selectsort(pSeqlist pSeq)
{
	int i = 0;
	assert(pSeq);
	
	for (i = 0; i < pSeq->sz; i++)//控制插入次数
	{
		int j = 0;
		int Maxpos = 0;
		for (j = 0; j <= pSeq->sz - 1 - i; j++)//控制比较
		{
			if (pSeq->data[j] > pSeq->data[Maxpos])
			{
				Maxpos = j;
			}
		}
		if (Maxpos != pSeq->sz - 1 - i)
		{
			Swap(pSeq->data + (pSeq->sz - 1 - i), pSeq->data + Maxpos);
		}
	}
}

int Binarysearch(pSeqlist pSeq, DateType num)
{
	int left = 0;
	int right = pSeq->sz - 1;
	int mid = 0;
	assert(pSeq);

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (pSeq->data[mid] < num)
		{
			left = mid + 1;
		}
	    else if(pSeq->data[mid] > num)
		{
			right = mid - 1;
		}
		else 
		{
			return mid;
		}
	}
	return -1;
}

int Binarysearch_R(pSeqlist pSeq, int left, int right, DateType num)
{
	int mid = left + (right - left) / 2;
	if (left > right)
	{
		return -1;
	}
	if (pSeq->data[mid] < num)
	{
		Binarysearch_R(pSeq, mid + 1, right, num);
	}
	else if (pSeq->data[mid] > num)
	{
		Binarysearch_R(pSeq, left, mid - 1, num);
	}
	else
	{
		return mid;
	}
}