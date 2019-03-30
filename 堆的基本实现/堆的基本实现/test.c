#include "Heap.h"

int main()
{
	Heap hp;
	HDataType array[] = { 32, 52, 13, 59, 10, 74, 9, 83 };
	int sz = sizeof(array) / sizeof(array[0]);
	//InitHeap(&hp, array, sizeof(array)/sizeof(array[0]));
	CreateHeap(&hp, array, sz);
	PrintHeap(&hp);
	InsertHeap(&hp, 11);
	printf("\n");
	PrintHeap(&hp);
	printf("\n");
	DeleteHeap(&hp);
	PrintHeap(&hp);
	printf("\n");
	system("pause");
	return 0;
}