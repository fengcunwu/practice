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
	struct ComplexLinkList* random;//随机指针域,可以指向任意位置
}ComplexLinkList, *pComplexLinkList;

void InitLinkList(pList* pplist);//初始化链表
void PrintLinkList(pList plist);//打印链表
void Pushback(pList* pplist, DataType data);//尾插法
pList BuyNode(DataType data);//创建节点
void PrintTailToHead(pList* pplist);//逆置
void PrintTailToHead_P(pList* pplist);//逆置链表
void PrintTailToHead_R(pList plist);//从尾到头打印单链表递归
pList Find(pList plist, DataType data);//查找值为data的节点
void DevNode(pList pos);//删除某位置节点
void InsertNode(pList pos, DataType data);//插入节点
pList JosephCycle(pList plist, int k);//约瑟夫环
void BubbleSort(pList plist);//冒泡排序法
pList FindLastKNode(pList plist, int K);//查找倒数第k个节点
pList FindMiddleNode(pList plist);//查找中间节点
void DelTailKNode(pList *pplist, int K);//删除倒数第k个节点
pList MergeLinkList(pList pHead1, pList pHead2);//归并两个有序链表
int IsListCross(pList pHead1, pList pHead2);//判断是否相交
pList GetCrossNode(pList pHead1, pList pHead2);//找交点
pList LastNode(pList plist);//找最后一个节点
pList IsLinkListRing(pList plist);//判断是否带环
pList GetRingEnter(pList plist, pNode pMeetNode);//找环的入口
int GetRingLength(pList plist, pNode pMeetNode);//求环的长度

#endif //__LINKLISTINTERVIEW_H__

