#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node* next;
}Node, *pNode, List, *pList;

void Initlinklist(pList* pplist);
void DestroyLinkList(pList* pplist);
void Printflinklist(pList plist);
pList Buynode(DataType data);
void Pushback(pList* pplist, DataType data);
void Popback(pList* pplist);
void Pushfront(pList* pplist, DataType data);
void Popfront(pList* pplist);
pList Find(pList plist, DataType data);
void Insert(pList* pplist, pNode pos, DataType data);//��ָ��λ��֮ǰ����һ������
void Erase(pList* pplist, pNode pos);//ɾ��ָ��λ������
void Remove(pList* pplist, DataType data);
void RemoveAll(pList* pplist, DataType data);
void EraseNotTailNode(pNode pos);
int GetListLength(pList plist);


#endif //__LINKLIST_H__