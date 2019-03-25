#include "BinTree.h"



int main()
{
	BTreeNode* BTnode;
	BTreeNode* pNew = NULL;
	char str[] = "ABD$$E$$CF$$$";
	int size = strlen(str);
	int index = 0;
	char ch = '$';
	CreateBinTree(&BTnode, str, size, &index, ch);
	printf("ǰ�����\n");
	PreOrder(BTnode);
	printf("\n");

	printf("�������\n");
	InOrder(BTnode);
	printf("\n");

	printf("�������\n");
	PostOrder(BTnode);
	printf("\n");
	printf("////////////////////////////////////////\n");
	/*pNew = CopyBinTree(BTnode);
	PreOrder(pNew);
	printf("\n");
	InOrder(pNew);
	printf("\n");
	PostOrder(pNew);
	printf("\n");
	DestroyBinTree(&pNew);*/
	printf("�ö������Ľڵ���Ϊ: %d\n", GetSizeBinTreeCount(BTnode));
	printf("�ö�������Ҷ�ӽڵ���Ϊ: %d\n", GetLeafBinTreeCount(BTnode));
	printf("�ö�����������Ľڵ���Ϊ: %d\n", GetKSizeBinTreeCount(BTnode, 3));
	printf("�ö������ĸ߶�Ϊ: %d\n", HeightBinTree(BTnode));
	printf("�������\n");
	LevelOrder(BTnode);
	printf("\n");
	MirrorBinTree(BTnode);
	MirrorBinTreeNor(BTnode);
	printf("������ǰ�����\n");
	PreOrder(BTnode);
	printf("\n");
	printf("/////////////////////////////////////\n");
	if (IsCompleteBinTree(BTnode))
		printf("�ö���������ȫ������\n");
	else
		printf("�ö�����������ȫ������\n");
	printf("//////////////////////////////////\n");
	printf("ǰ������ķǵݹ�ʵ��\n");
	PreOrderNor(BTnode);
	printf("\n");

	printf("��������ķǵݹ�ʵ��\n");
	InOrderNor(BTnode);
	printf("\n");

	printf("��������ķǵݹ�ʵ��\n");
	PostOrderNor(BTnode);
	printf("\n");

	system("pause");
	return 0;
}