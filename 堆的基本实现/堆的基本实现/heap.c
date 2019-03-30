#include "Heap.h"

//void InitHeap(Heap* hp, HDataType* array, int size)
//{
//	int i = 0;
//	assert(hp && array && size > 0);
//
//	hp->array = (HDataType *)malloc(sizeof(HDataType)* size);
//	if (hp->array == NULL)
//	{
//		printf("创建失败！！\n");
//		return;
//	}
//	hp->capacity = size;
//	hp->size = size;
//
//	for (i = 0; i < size; i++)
//	{
//		hp->array[i] = array[i];
//	}
//}

void Swap(HDataType* parent, HDataType* child)
{
	HDataType tmp;
	assert(parent && child);

	tmp = *parent;
	*parent = *child;
	*child = tmp;
}

void AdJustDown(Heap* hp, int parent)
{
	int child;
	//assert(hp);

	child = parent * 2 + 1;

	while (child < hp->size)
	{
		if (hp->array[child] > hp->array[child + 1] && child + 1 < hp->size)
			child += 1;

		if (hp->array[parent] > hp->array[child])
		{
			Swap(&hp->array[parent], &hp->array[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
}

void AdJustUp(Heap* hp, int parent)
{
	int child = 0;
	//先取左孩子
	child = parent * 2 + 1;//左孩子和右孩子比较大小，找最大的
	if (hp->array[child] < hp->array[child + 1])
		child += 1;

	//在孩子里找到较大的和双亲节点比较
	if (hp->array[parent] < hp->array[child])
	{
		Swap(&(hp->array[parent]), &(hp->array[child]));
		parent = child;
		child = parent * 2 + 1;
	}
	else
		//双亲节点比孩子大，满足大堆的条件
		return;
}

void CreateHeap(Heap* hp, HDataType* array, int size)
{
	int root = (size - 2) / 2;
	int i = 0;
	assert(hp);

	hp->array = (HDataType*)malloc(sizeof(HDataType)* size * 2);
	if (NULL == hp->array)
	{
		printf("开辟空间失败！！！\n");
		assert(0);
		return;
	}

	hp->capacity = 2 * size;
	memcpy(hp->array, array, size*sizeof(HDataType));
	hp->size = size;
	//调整堆中的数据
	//找到调整的位置，倒数第一个非叶子节点
	for (; root >= 0; root--)
		AdJustDown(hp, root);
}

void PrintHeap(Heap *hp)
{
	for (int i = 0; i < hp->size; i++)
	{
		printf(" %d ", hp->array[i]);
	}
}

void InsertHeap(Heap* hp, HDataType data)
{
	int ret = 0;
	assert(hp);
	if (hp->size > hp->capacity)
	{
		printf("堆的容量已满，无法插入！！！\n");
		return;
	}
	hp->array[hp->size] = data;
	hp->size += 1;

	ret = (hp->size - 2) / 2;
	for (; ret >= 0; ret--)
		AdJustDown(hp, ret);
}

void DeleteHeap(Heap* hp)
{
	int ret = 0;
	if (hp->size == 0)
	{
		printf("该堆为空，无法删除！！！\n");
		return;
	}
	else
	{
		hp->array[0] = hp->array[hp->size - 1];
		hp->size--;
		ret = (hp->size - 2) / 2;
		for (; ret >= 0; ret--)
			AdJustDown(hp, ret);
	}
}