#include "LinkListInterview.h"

void test()
{
	pList plist;
	pList pDev = NULL;
	int i = 0;
	InitLinkList(&plist);
	for (i = 10; i > 0; i--)
	{
		Pushback(&plist, i);
	}
/////////////// 从尾到头打印单链表 //////////////////
	//PrintLinkList(plist);
	////PrintTailToHead(&plist);//普通遍历法
	///*PrintTailToHead_P(&plist);//头插法*/
	//PrintTailToHead_R(plist);//递归
	//printf("NULL \n");
//////////////删除无头链表的非尾节点///////////////
	/*PrintLinkList(plist);
	pDev = Find(plist, 7);
	DevNode(pDev);
	PrintLinkList(plist);*/
/////////////在无头单链表的一个节点前插入一个节点(不能遍历链表)///////////
	/*PrintLinkList(plist);
	pDev = Find(plist, 5);
	InsertNode(pDev, 29);
	PrintLinkList(plist);*/
/////////////////实现单链表的约瑟夫环/////////////////////////////// 
	/*PrintLinkList(plist);
	pDev = JosephCycle(plist, 2);
	printf("幸存者是%d号\n", pDev->data);*/
/////////////////单链表的排序(冒泡和快速)///////////////////////////
	/*PrintLinkList(plist);
	BubbleSort(plist);
	PrintLinkList(plist);*/
/*////////////////合并两个有序链表，合并结束后仍然有序///////////////
	pList pL1;
	pList pL2;
	InitLinkList(&pL1);
	InitLinkList(&pL2);
	Pushback(&pL1, 1);
	Pushback(&pL1, 3);
	Pushback(&pL1, 5);
	Pushback(&pL1, 7);
	Pushback(&pL1, 9);
	Pushback(&pL2, 2);
	Pushback(&pL2, 3);
	Pushback(&pL2, 4);
	Pushback(&pL2, 6);
	Pushback(&pL2, 8);
	Pushback(&pL2, 10);
	PrintLinkList(pL1);
	PrintLinkList(pL2);
	pDev = MergeLinkList(pL1, pL2);
	PrintLinkList(pDev);*/
/////////////////找单链表的倒数第k个节点//////////////////////////////
	/*PrintLinkList(plist);
	pDev = FindLastKNode(plist, 3);
	if (pDev)
		printf("链表中第%d个节点是%d\n", 3，pDev->data);
	else
		printf("查找有误！！！");*/
/////////////////////找单链表的中间节点////////////////////////////////
	/*PrintLinkList(plist);
	pDev = FindMiddleNode(plist);
	if (pDev)
		printf("中间节点为%d\n", pDev->data);
	else
		printf("查找有误!!!\n");*/
//////////////////// 删除链表中倒数第K个节点////////////////////////
	/*PrintLinkList(plist);
	DelTailKNode(&plist, 3);
	PrintLinkList(plist);*/

/*///////////////////判断两个链表是否相交，若相交，求交点////////////////
	pList pL1;
	pList pL2;
	InitLinkList(&pL1);
	InitLinkList(&pL2);
	Pushback(&pL1, 1);
	Pushback(&pL1, 3);
	Pushback(&pL1, 5);
	Pushback(&pL1, 7);
	Pushback(&pL1, 9);
	Pushback(&pL2, 2);
	Pushback(&pL2, 3);
	Pushback(&pL2, 4);
	Pushback(&pL2, 6);
	Pushback(&pL2, 8);
	Pushback(&pL2, 10);
	PrintLinkList(pL1);
	PrintLinkList(pL2);
	Find(pL1, 9)->next = Find(pL2, 3);
	PrintLinkList(pL1);
	if (IsListCross(pL1, pL2))
	{
		printf("两个链表相交,交点为: %d\n", GetCrossNode(pL1, pL2)->data);
	}
	else
		printf("没有相交");*/
/////////////判断链表是否带环，求环的长度，求环的入口/////////////////////////
	/*pList pL1;
	pNode pMeetNode = NULL;
	InitLinkList(&pL1);
	Pushback(&pL1, 1);
	Pushback(&pL1, 3);
	Pushback(&pL1, 5);
	Pushback(&pL1, 7);
	Pushback(&pL1, 9);
	Pushback(&pL1, 2);
	Pushback(&pL1, 3);
	Pushback(&pL1, 4);
	Pushback(&pL1, 6);
	Pushback(&pL1, 8);
	Pushback(&pL1, 10);
	PrintLinkList(pL1);
	LastNode(pL1)->next = Find(pL1, 9);
	pMeetNode = IsLinkListRing(pL1);
	pDev = GetRingEnter(pL1, pMeetNode);
	int ret = GetRingLength(pL1, pMeetNode);
	if (pMeetNode)
	{
		printf("链表带环, 入口点为：%d, 环的长度为: %d \n", pDev->data, ret);
	}
	else
		printf("链表不带环\n");*/
//////////////////////复杂单链表的复制//////////////////////////////
	pComplexLinkList pNode1 = NULL;
	pComplexLinkList pNode2 = NULL; 
	pComplexLinkList pNode3 = NULL;
	pComplexLinkList pNode4 = NULL;
	pComplexLinkList pNode5 = NULL;

	pNode1->data = 1;
	pNode1->next = pNode2;
	pNode1->random = pNode3;

	pNode2->data = 2;
	pNode2->next = pNode3;
	pNode2->random = pNode4;

	pNode3->data = 3;
	pNode3->next = pNode4;
	pNode3->random = pNode3;

	pNode4->data = 4;
	pNode4->next = pNode5;
	pNode4->random = NULL;

	pNode5->data = 5;
	pNode5->next = NULL;
	pNode5->random = pNode4;

	pComplexLinkList pCur = NULL;
	pComplexLinkList pNext = NULL;
	pCur = pNode1;

	while (pCur)
	{
		pComplexLinkList pNewNode = NULL;
		pNewNode->data = pCur->data;
		pNewNode->next = pCur->next;
		pCur->next = pNewNode;
		pCur = pNewNode->next;
	}
	
}

int main()
{
	test();
	system("pause");
	return 0;
}
