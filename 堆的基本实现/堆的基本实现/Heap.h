#ifndef __HEAP_H__
#define __HEAP_H__

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef int HDataType;
typedef struct Heap
{
	HDataType *array;//存放数据
	int size; //堆的大小
	int capacity;//堆的容量
}Heap;

//void InitHeap(Heap* hp);
void CreateHeap(Heap* hp, int* array, int size);
void AdJustDown(Heap* hp, int parent);
void Swap(HDataType* parent, HDataType* child);
void PrintHeap(Heap *hp);
void InsertHeap(Heap* hp, HDataType data);
void DeleteHeap(Heap* hp);
void AdJustUp(Heap* hp, int parent);


#endif //__HEAP_H__