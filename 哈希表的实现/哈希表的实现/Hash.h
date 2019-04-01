#ifndef __HASH_H__
#define __HASH_H__

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define PRIMEMAXSIZE 21

typedef int HTDataType;
typedef int(*PDToInt)(HTDataType data);

typedef enum {EMPTY, EXIST, DELETE}State;//ö�ٽṹ�������ʾ��ϣ��ǰ�±��״̬
//��ʾ��ǰ�±����Ƿ������ݣ�

typedef struct HTElem//����ṹ���ǹ�ϣ�����ŵ�����
{//��ϣ����ÿ��λ�ô��һ���ṹ�壬����ṹ���������ݺ͵�ǰ״̬
	HTDataType data;//����
	State state;//��ǰ״̬
}HTElem;

typedef struct HashTable//ʵ�ֹ�ϣ��Ľṹ�壬
{
	HTElem* array;//���飬���Ԫ��
	int size;//��ʾ��ϣ��Ĵ�С
	int capacity;//��ϣ�������
	int total;//�����ϣ����״̬Ϊ ���� �� ״̬ Ϊɾ������֮��
	PDToInt pDataToInt;
}HashTable;

typedef struct LinkList
{
	HTDataType data;//�������
	struct LinkList* next;//�����һ�����ݵĵ�ַ
}List, *pList;

typedef struct HashBucket//��̬��ϣͰ
{
	pList array[MAXSIZE];//һ������������ĵ�ַ
	int size;//��ʾ��ϣ��Ĵ�С
}HashBucket;

//��̬��ϣ��Ļ���ʵ��

void InitHashTable(HashTable* pHT);//��ϣ��ĳ�ʼ��
void InsertHashTable(HashTable* pHT, HTDataType data);//��ϣ��Ĳ���
void DeleteHashTable(HashTable* pHT, HTDataType data);//��ϣ���ɾ��
int FindHashTable(HashTable* pHT, HTDataType data);//�ڹ�ϣ�������ĳһ������
int IsEmptyHashTable(HashTable* pHT);//�жϹ�ϣ���Ƿ�Ϊ�� Ϊ�շ���1 ��Ϊ�շ���0
int SizeHashTable(HashTable* pHT);//���ϣ��Ĵ�С
int HashFun(HTDataType data);//��ϣ������ʵ��

//��̬��ϣ��Ļ���ʵ��

void InitHashTable_(HashTable* pHT, int capacity, PDToInt pDToInt);//��ϣ��ĳ�ʼ��
void InsertHashTable_(HashTable* pHT, HTDataType data);//��ϣ��Ĳ���
int HashFun_(HashTable* pHT, HTDataType data);//��ϣ������ʵ��
void CleakCapacity(HashTable* pHT);
void PrintHashTable(HashTable* pHT);
void DeleteHashTable_(HashTable* pHT, HTDataType data);
unsigned long GetNextPrime(unsigned long capacity);
unsigned long DataToInt(HTDataType data);

//��̬��ϣͰ�Ļ���ʵ��

void InitHashBucket(HashBucket* pHB);//��ʼ����ϣͰ
void DestoryHashBucket(HashBucket* pHB);
void InsertHashBucket(HashBucket* pHB, HTDataType data);
pList BuyNodeHashBucket(HTDataType data);
void PrintHashBucket(HashBucket* pHB);
void DeleteHashBucket(HashBucket* pHB, HTDataType data);
int FindHashBucket(HashBucket* pHB, HTDataType data);

#endif //__HASH_H__