#ifndef __HASH_H__
#define __HASH_H__

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define PRIMEMAXSIZE 21

typedef int HTDataType;
typedef int(*PDToInt)(HTDataType data);

typedef enum {EMPTY, EXIST, DELETE}State;//枚举结构，这个表示哈希表当前下标的状态
//表示当前下标下是否有数据，

typedef struct HTElem//这个结构体是哈希表里存放的类型
{//哈希表里每个位置存放一个结构体，这个结构体里有数据和当前状态
	HTDataType data;//数据
	State state;//当前状态
}HTElem;

typedef struct HashTable//实现哈希表的结构体，
{
	HTElem* array;//数组，存放元素
	int size;//表示哈希表的大小
	int capacity;//哈希表的容量
	int total;//保存哈希表中状态为 存在 和 状态 为删除个数之和
	PDToInt pDataToInt;
}HashTable;

typedef struct LinkList
{
	HTDataType data;//存放数据
	struct LinkList* next;//存放下一个数据的地址
}List, *pList;

typedef struct HashBucket//静态哈希桶
{
	pList array[MAXSIZE];//一个数组存放链表的地址
	int size;//表示哈希表的大小
}HashBucket;

//静态哈希表的基本实现

void InitHashTable(HashTable* pHT);//哈希表的初始化
void InsertHashTable(HashTable* pHT, HTDataType data);//哈希表的插入
void DeleteHashTable(HashTable* pHT, HTDataType data);//哈希表的删除
int FindHashTable(HashTable* pHT, HTDataType data);//在哈希表里查找某一个数据
int IsEmptyHashTable(HashTable* pHT);//判断哈希表是否为空 为空返回1 不为空返回0
int SizeHashTable(HashTable* pHT);//求哈希表的大小
int HashFun(HTDataType data);//哈希函数的实现

//动态哈希表的基本实现

void InitHashTable_(HashTable* pHT, int capacity, PDToInt pDToInt);//哈希表的初始化
void InsertHashTable_(HashTable* pHT, HTDataType data);//哈希表的插入
int HashFun_(HashTable* pHT, HTDataType data);//哈希函数的实现
void CleakCapacity(HashTable* pHT);
void PrintHashTable(HashTable* pHT);
void DeleteHashTable_(HashTable* pHT, HTDataType data);
unsigned long GetNextPrime(unsigned long capacity);
unsigned long DataToInt(HTDataType data);

//静态哈希桶的基本实现

void InitHashBucket(HashBucket* pHB);//初始化哈希桶
void DestoryHashBucket(HashBucket* pHB);
void InsertHashBucket(HashBucket* pHB, HTDataType data);
pList BuyNodeHashBucket(HTDataType data);
void PrintHashBucket(HashBucket* pHB);
void DeleteHashBucket(HashBucket* pHB, HTDataType data);
int FindHashBucket(HashBucket* pHB, HTDataType data);

#endif //__HASH_H__