#ifndef __HASHBUCKETCAPACITY_H__
#define __HASHBUCKETCAPACITY_H__

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define PRIMEMAXSIZE 21
//typedef int(*PDToInt)(Node data);
typedef int HBCDataType;

typedef struct LinkList
{
	HBCDataType data;
	struct LinkList* next;
}*pList, Node;


//动态哈希桶
typedef struct HashBC
{
	pList* table;//存放节点地址的指针，所以是二级指针
	int size;//表示哈希桶有效元素的个数
	int capacity;//表示哈希桶的容量大小
	//PDToInt pDTInt;//函数指针，把data的数值转化为int
}HashBC;

void InitHashBC(HashBC* pHBC, int capacity/*PDToInt pDTInt*/);//初始化
void InsertHashBC(HashBC* pHBC, HBCDataType data);//插入
void DeleteHashBC(HashBC* pHBC, HBCDataType data);//删除
int FindHashBC(HashBC* pHBC, HBCDataType data);//查找
int SizeHashBC(HashBC* pHBC);//返回大小
int IsEmptyHashBC(HashBC* pHBC);//返回是否为空
void DestoryHashBC(HashBC* pHBC);//销毁
int HashBucketFunc(HashBC* pHBC, HBCDataType data);//哈希函数
pList BuyHashBucketNode(HBCDataType data);//创建一个新的节点
unsigned long GetNextPrime(unsigned long capacity);
unsigned long DataToInt(const char* str);
void PrintHashBC(HashBC* pHBC);
//动态哈希桶的增容条件是size == capacity

#endif //__HASHBUCKETCAPACITY_H__