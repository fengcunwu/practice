#ifndef __LINKLISTINTERVIEW_H__
#define __LINKLISTINTERVIEW_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;
typedef struct Linklist
{
	DataType data;
	struct Linklist* next;
}List, *pList, Node, *pNode;

typedef struct ComplexLinkList
{
	DataType data;
	struct ComplexLinkList* next;
	struct ComplexLinkList* random;//���ָ����,����ָ������λ��
}ComplexLinkList, *pComplexLinkList;

void InitLinkList(pList* pplist);//��ʼ������
void PrintLinkList(pList plist);//��ӡ����
void Pushback(pList* pplist, DataType data);//β�巨
pList BuyNode(DataType data);//�����ڵ�
void PrintTailToHead(pList* pplist);//����
void PrintTailToHead_P(pList* pplist);//��������
void PrintTailToHead_R(pList plist);//��β��ͷ��ӡ������ݹ�
pList Find(pList plist, DataType data);//����ֵΪdata�Ľڵ�
void DevNode(pList pos);//ɾ��ĳλ�ýڵ�
void InsertNode(pList pos, DataType data);//����ڵ�
pList JosephCycle(pList plist, int k);//Լɪ��
void BubbleSort(pList plist);//ð������
pList FindLastKNode(pList plist, int K);//���ҵ�����k���ڵ�
pList FindMiddleNode(pList plist);//�����м�ڵ�
void DelTailKNode(pList *pplist, int K);//ɾ��������k���ڵ�
pList MergeLinkList(pList pHead1, pList pHead2);//�鲢������������
int IsListCross(pList pHead1, pList pHead2);//�ж��Ƿ��ཻ
pList GetCrossNode(pList pHead1, pList pHead2);//�ҽ���
pList LastNode(pList plist);//�����һ���ڵ�
pList IsLinkListRing(pList plist);//�ж��Ƿ����
pList GetRingEnter(pList plist, pNode pMeetNode);//�һ������
int GetRingLength(pList plist, pNode pMeetNode);//�󻷵ĳ���

#endif //__LINKLISTINTERVIEW_H__

