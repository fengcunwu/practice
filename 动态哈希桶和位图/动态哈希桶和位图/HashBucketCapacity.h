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


//��̬��ϣͰ
typedef struct HashBC
{
	pList* table;//��Žڵ��ַ��ָ�룬�����Ƕ���ָ��
	int size;//��ʾ��ϣͰ��ЧԪ�صĸ���
	int capacity;//��ʾ��ϣͰ��������С
	//PDToInt pDTInt;//����ָ�룬��data����ֵת��Ϊint
}HashBC;

void InitHashBC(HashBC* pHBC, int capacity/*PDToInt pDTInt*/);//��ʼ��
void InsertHashBC(HashBC* pHBC, HBCDataType data);//����
void DeleteHashBC(HashBC* pHBC, HBCDataType data);//ɾ��
int FindHashBC(HashBC* pHBC, HBCDataType data);//����
int SizeHashBC(HashBC* pHBC);//���ش�С
int IsEmptyHashBC(HashBC* pHBC);//�����Ƿ�Ϊ��
void DestoryHashBC(HashBC* pHBC);//����
int HashBucketFunc(HashBC* pHBC, HBCDataType data);//��ϣ����
pList BuyHashBucketNode(HBCDataType data);//����һ���µĽڵ�
unsigned long GetNextPrime(unsigned long capacity);
unsigned long DataToInt(const char* str);
void PrintHashBC(HashBC* pHBC);
//��̬��ϣͰ������������size == capacity

#endif //__HASHBUCKETCAPACITY_H__