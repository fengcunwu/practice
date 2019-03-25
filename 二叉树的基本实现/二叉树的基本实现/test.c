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
	printf("前序遍历\n");
	PreOrder(BTnode);
	printf("\n");

	printf("中序遍历\n");
	InOrder(BTnode);
	printf("\n");

	printf("后序遍历\n");
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
	printf("该二叉树的节点数为: %d\n", GetSizeBinTreeCount(BTnode));
	printf("该二叉树的叶子节点数为: %d\n", GetLeafBinTreeCount(BTnode));
	printf("该二叉树第三层的节点数为: %d\n", GetKSizeBinTreeCount(BTnode, 3));
	printf("该二叉树的高度为: %d\n", HeightBinTree(BTnode));
	printf("层序遍历\n");
	LevelOrder(BTnode);
	printf("\n");
	MirrorBinTree(BTnode);
	MirrorBinTreeNor(BTnode);
	printf("镜像后的前序遍历\n");
	PreOrder(BTnode);
	printf("\n");
	printf("/////////////////////////////////////\n");
	if (IsCompleteBinTree(BTnode))
		printf("该二叉树是完全二叉树\n");
	else
		printf("该二叉树不是完全二叉树\n");
	printf("//////////////////////////////////\n");
	printf("前序遍历的非递归实现\n");
	PreOrderNor(BTnode);
	printf("\n");

	printf("中序遍历的非递归实现\n");
	InOrderNor(BTnode);
	printf("\n");

	printf("后序遍历的非递归实现\n");
	PostOrderNor(BTnode);
	printf("\n");

	system("pause");
	return 0;
}