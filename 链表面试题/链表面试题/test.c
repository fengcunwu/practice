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
/////////////// ��β��ͷ��ӡ������ //////////////////
	//PrintLinkList(plist);
	////PrintTailToHead(&plist);//��ͨ������
	///*PrintTailToHead_P(&plist);//ͷ�巨*/
	//PrintTailToHead_R(plist);//�ݹ�
	//printf("NULL \n");
//////////////ɾ����ͷ����ķ�β�ڵ�///////////////
	/*PrintLinkList(plist);
	pDev = Find(plist, 7);
	DevNode(pDev);
	PrintLinkList(plist);*/
/////////////����ͷ�������һ���ڵ�ǰ����һ���ڵ�(���ܱ�������)///////////
	/*PrintLinkList(plist);
	pDev = Find(plist, 5);
	InsertNode(pDev, 29);
	PrintLinkList(plist);*/
/////////////////ʵ�ֵ������Լɪ��/////////////////////////////// 
	/*PrintLinkList(plist);
	pDev = JosephCycle(plist, 2);
	printf("�Ҵ�����%d��\n", pDev->data);*/
/////////////////�����������(ð�ݺͿ���)///////////////////////////
	/*PrintLinkList(plist);
	BubbleSort(plist);
	PrintLinkList(plist);*/
/*////////////////�ϲ��������������ϲ���������Ȼ����///////////////
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
/////////////////�ҵ�����ĵ�����k���ڵ�//////////////////////////////
	/*PrintLinkList(plist);
	pDev = FindLastKNode(plist, 3);
	if (pDev)
		printf("�����е�%d���ڵ���%d\n", 3��pDev->data);
	else
		printf("�������󣡣���");*/
/////////////////////�ҵ�������м�ڵ�////////////////////////////////
	/*PrintLinkList(plist);
	pDev = FindMiddleNode(plist);
	if (pDev)
		printf("�м�ڵ�Ϊ%d\n", pDev->data);
	else
		printf("��������!!!\n");*/
//////////////////// ɾ�������е�����K���ڵ�////////////////////////
	/*PrintLinkList(plist);
	DelTailKNode(&plist, 3);
	PrintLinkList(plist);*/

/*///////////////////�ж����������Ƿ��ཻ�����ཻ���󽻵�////////////////
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
		printf("���������ཻ,����Ϊ: %d\n", GetCrossNode(pL1, pL2)->data);
	}
	else
		printf("û���ཻ");*/
/////////////�ж������Ƿ�������󻷵ĳ��ȣ��󻷵����/////////////////////////
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
		printf("�������, ��ڵ�Ϊ��%d, ���ĳ���Ϊ: %d \n", pDev->data, ret);
	}
	else
		printf("��������\n");*/
//////////////////////���ӵ�����ĸ���//////////////////////////////
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
