#include "Hash.h"


void test()
{
	HashTable pHT;

	InitHashTable(&pHT);
	InsertHashTable(&pHT, 28);
	InsertHashTable(&pHT, 13);
	InsertHashTable(&pHT, 16);
	InsertHashTable(&pHT, 49);
	InsertHashTable(&pHT, 45);
	InsertHashTable(&pHT, 18);
	DeleteHashTable(&pHT, 18);
	if (FindHashTable(&pHT, 18) == -1)
		printf("该数据在哈希表里不存在！！！\n");
	else
		printf("该数据的下标为 %d ", FindHashTable(&pHT, 18));
	printf("该哈希表的大小为 %d \n", SizeHashTable(&pHT));
}

void testCapacity()
{
	HashTable pHT;

	InitHashTable_(&pHT, 10, DataToInt);

	InsertHashTable_(&pHT, 1);
	InsertHashTable_(&pHT, 12);
	InsertHashTable_(&pHT, 43);
	InsertHashTable_(&pHT, 64);
	InsertHashTable_(&pHT, 53);
	InsertHashTable_(&pHT, 75);
	InsertHashTable_(&pHT, 97);
	PrintHashTable(&pHT);
	InsertHashTable_(&pHT, 84);
	InsertHashTable_(&pHT, 36);
	DeleteHashTable_(&pHT, 43);
	PrintHashTable(&pHT);
	if (FindHashTable(&pHT, 43) != -1)
		printf("找到了，下标为%d\n", FindHashTable(&pHT, 43));
	else
		printf("找不到，该数据在哈希表里不存在\n");
	printf("哈希表的大小为%d\n", SizeHashTable(&pHT));

}

void testHashBucket()
{
	HashBucket pHB;
	int ret = 0;

	InitHashBucket(&pHB);
	InsertHashBucket(&pHB, 64);
	InsertHashBucket(&pHB, 86);
	InsertHashBucket(&pHB, 24);
	InsertHashBucket(&pHB, 53);
	InsertHashBucket(&pHB, 82);
	InsertHashBucket(&pHB, 91);
	InsertHashBucket(&pHB, 14);
	PrintHashBucket(&pHB);
	DeleteHashBucket(&pHB, 64);
	DeleteHashBucket(&pHB, 91);
	printf("////////////////////////////////////\n");
	printf("删除数据 90 : ");
	DeleteHashBucket(&pHB, 90);
	//PrintHashBucket(&pHB);
	ret = FindHashBucket(&pHB, 90);
	if (ret >= 0)
		printf("找到了，该数据的桶号为：%d\n", ret);
	else
		printf("没找到，该数据不存在于该哈希桶！！\n");

	DestoryHashBucket(&pHB);
	PrintHashBucket(&pHB);
}

int main()
{
	//test();//普通静态
	//testCapacity();
	testHashBucket();
	system("pause");
	return 0;
}