#include "BinTree.h"


BTreeNode* BuyBTNode(DataType data)
{
	BTreeNode* pNewNode = (BTreeNode*)malloc(sizeof(BTreeNode));
	if (pNewNode == NULL)
	{
		assert(0);
		return NULL;
	}

	pNewNode->data = data;
	pNewNode->left = NULL;
	pNewNode->right = NULL;

	return pNewNode;
}

void PreOrder(BTreeNode* BTnode)//传进来根节点，从根开始遍历，
{
	if (NULL == BTnode)
		return;
	else
	{
		printf("%c ", BTnode->data);
		PreOrder(BTnode->left);
		PreOrder(BTnode->right);
	}
}

void InOrder(BTreeNode* BTnode)//中序遍历  左 根 右
{
	if (NULL == BTnode)
		return;
	else
	{
		InOrder(BTnode->left);
		printf("%c ", BTnode->data);
		InOrder(BTnode->right);
	}
}

void PostOrder(BTreeNode* BTnode)//后序遍历 左 右 根
{
	if (NULL == BTnode)
		return;
	else
	{
		PostOrder(BTnode->left);
		PostOrder(BTnode->right);
		printf("%c ", BTnode->data);
	}
}

void CreateBinTree(BTreeNode** BTnode, char* str, int size,
	int* index, DataType invalid)//BTnode中存放的是根节点的地址
{
	assert(BTnode);
	assert(str);
	assert(index);

	if ((*index) < size && str[*index] != invalid)
	{
		//创建根节点
		*BTnode = BuyBTNode(str[*index]);
		//创建左孩子节点
		++(*index);
		CreateBinTree(&((*BTnode)->left), str, size, index, invalid);
		//创建右孩子节点
		++(*index);
		CreateBinTree(&((*BTnode)->right), str, size, index, invalid);
	}
}

BTreeNode* CopyBinTree(BTreeNode* BTnode)//二叉树的复制
{
	BTreeNode* pNewNode;
	if (NULL == BTnode)
		return NULL;
	
	//复制根节点
	pNewNode = BuyBTNode(BTnode->data);

	//复制左节点
	pNewNode->left = CopyBinTree(BTnode->left);
	
	//复制右节点
	pNewNode->right = CopyBinTree(BTnode->right);

	return pNewNode;
}

void DestroyBinTree(BTreeNode** BTnode)//销毁二叉树 销毁顺序 左 右 根
{
	assert(BTnode);

	if (*BTnode == NULL)
		return;

	DestroyBinTree(&((*BTnode)->left));
	DestroyBinTree(&((*BTnode)->right));
	free(*BTnode);
	*BTnode = NULL;
}

int GetSizeBinTreeCount(BTreeNode* BTnode)//返回二叉树所有节点数
{
	if (NULL == BTnode)
		return 0;

	return GetSizeBinTreeCount(BTnode->left)
		   + GetSizeBinTreeCount(BTnode->right) + 1;
}

int GetLeafBinTreeCount(BTreeNode* BTnode)//返回二叉树叶子节点数
{
	if (BTnode == NULL)
		return 0;

	if (BTnode->left == NULL && BTnode->right == NULL)
		return 1;
	
	return GetLeafBinTreeCount(BTnode->left) + GetLeafBinTreeCount(BTnode->right);
}

int GetKSizeBinTreeCount(BTreeNode* BTnode, int K)//返回二叉树第k层的节点数
{
	if (BTnode == NULL || K <= 0)
		return 0;
	if (K == 1)
		return 1;
	return GetKSizeBinTreeCount(BTnode->left, K - 1)
		+ GetKSizeBinTreeCount(BTnode->right, K - 1);
}

int HeightBinTree(BTreeNode* BTnode)//得到二叉树的高度
{
	if (NULL == BTnode)
		return 0;
	return HeightBinTree(BTnode->left) > HeightBinTree(BTnode->right) ?
		HeightBinTree(BTnode->left) + 1 : HeightBinTree(BTnode->right) + 1;
}

BTreeNode* LeftBinTree(BTreeNode* BTnode)//得到二叉树的左孩子节点
{
	if (NULL == BTnode)
		return NULL;
	return BTnode->left;
}

BTreeNode* RightBinTree(BTreeNode* BTnode)//得到二叉树的右孩子节点
{
	if (NULL == BTnode)
		return NULL;
	return BTnode->right;
}

int IsExistInBinTree(BTreeNode* BTnode, BTreeNode* pNode)//判断节点是否在二叉树内
{
	if (NULL == BTnode || NULL == pNode)
		return 0;

	if (BTnode == pNode)
		return 1;

	if (IsExistInBinTree(BTnode->left, pNode))
		return 1;

	return IsExistInBinTree(BTnode->right, pNode);
}

BTreeNode* ParentBinTree(BTreeNode* BTnode, BTreeNode* pNode)//返回节点的双亲节点
{
	BTreeNode* Parent = NULL;
	if (NULL == BTnode || NULL == pNode || pNode == BTnode)
		return NULL;

	if (pNode == BTnode->left || pNode == BTnode->right)
		return BTnode;

	Parent = ParentBinTree(BTnode->left, pNode);
	if (Parent)
		return Parent;
	else
		return ParentBinTree(BTnode->right, pNode);
}

/////////////////////////////////////////////////////////////
////////////////栈和队列的辅助操作///////////////////////////

void InitQueue(Queue* q)
{
	assert(q);
	q->back = 0;
	q->count = 0;
	q->front = 0;
}

void PushQueue(Queue* q, BDataType data)
{
	assert(q);

	if (q->count == MAXSIZE)
	{
		printf("队列已满,无法入队！！！\n");
		return;
	}
	if (q->back == MAXSIZE)
		q->back = 0;
	q->array[q->back] = data;
	q->count++;
	q->back++;
}

void PopQueue(Queue* q)
{
	assert(q);

	if (q->count == 0)
	{
		printf("队列中没有数据，无法出队！！！\n");
		return;
	}
	
	q->count--;
	q->front++;

}

BDataType FrontQueue(Queue* q)
{
	assert(q);
	if (q->back == q->front && q->count == 0)
	{
		printf("队列为空,没有队头元素！！！\n");
		return NULL;
	}
	return q->array[q->front];
}

int IsEmptyQueue(Queue* q)//返回1,说明为空
{
	assert(q);
	return 0 == q->count;
}


void LevelOrder(BTreeNode* BTnode)//层序遍历二叉树
{
	Queue q;
	BTreeNode* pCur = NULL;
	if (BTnode == NULL)
		return;
	else
	{
		InitQueue(&q);
		PushQueue(&q, BTnode);
		while (!IsEmptyQueue(&q))
		{
			pCur = FrontQueue(&q);
			printf(" %c ", pCur->data);
			if (pCur->left)
				PushQueue(&q, pCur->left);
			if (pCur->right)
				PushQueue(&q, pCur->right);
			PopQueue(&q);
		}
	}
}

void Swap(BTreeNode** left, BTreeNode** right)//交换函数，左孩子和右孩子交换
{
	BTreeNode* tmp = NULL;
	assert(left && right);
	tmp = *left;
	*left = *right;
	*right = tmp;
}

void MirrorBinTree(BTreeNode* BTnode)
{
	if (NULL == BTnode)
		return;
	else
	{
		Swap(&(BTnode->left), &(BTnode->right));
	}
	MirrorBinTree(BTnode->left);
	MirrorBinTree(BTnode->right);
}

void MirrorBinTreeNor(BTreeNode* BTnode)//镜像二叉树非递归
{
	Queue q;
	BTreeNode* pCur = NULL;
	if (BTnode == NULL)
		return;
	else
	{
		InitQueue(&q);
		PushQueue(&q, BTnode);
		while (!IsEmptyQueue(&q))
		{
			pCur = FrontQueue(&q);
			Swap(&(pCur->left), &(pCur->right));
			if (pCur->left)
				PushQueue(&q, pCur->left);
			if (pCur->right)
				PushQueue(&q, pCur->right);
			PopQueue(&q);
		}
	}
}

int IsCompleteBinTree(BTreeNode* BTnode)//判断二叉树是否为完全二叉树
{
	Queue q;
	int flag = 0;
	BTreeNode* pCur = NULL;
	if (BTnode == NULL)
		return 1;//空树也是完全二叉树

	InitQueue(&q);
	PushQueue(&q, BTnode);
	while (!IsEmptyQueue(&q))
	{
		pCur = FrontQueue(&q);
		if (flag == 1 && (pCur->left || pCur->right))
			return 0;

		if (pCur->left && pCur->right)
		{
			PushQueue(&q, pCur->left);
			PushQueue(&q, pCur->right);
		}
		else
		{
			if (pCur->right)
				return 0;

			if (pCur->left)
			{
				flag = 1;
				PushQueue(&q, pCur->left);
			}

			if (NULL == pCur->left && NULL == pCur->right)
				flag = 1;

		}
		PopQueue(&q);
	}
	return 1;
}

void InitStack(Stack* ps)
{
	assert(ps);

	ps->top = 0;
}

void PushStack(Stack* ps, SDataType data)
{
	assert(ps);

	if (ps->top == MAXSIZE)
	{
		printf("该栈已满,无法压入!!\n");
		return;
	}
	else
	{
		ps->array[ps->top] = data;
		ps->top++;
	}
}

void PopStack(Stack* ps)
{
	assert(ps);

	if (ps->top == 0)
	{
		printf("该栈为空，无法出栈！！！\n");
		return;
	}
	ps->top--;
}

int IsEmptyStack(Stack* ps)//返回1表示为空
{
	assert(ps);
	return 0 == ps->top;
}

SDataType TopStack(Stack* ps)
{
	assert(ps);
	if (ps->top == 0)
	{
		printf("栈为空,没有栈顶元素！！\n");
		return 0;
	}
	return ps->array[ps->top - 1];
}

void PreOrderNor(BTreeNode* BTnode)//前序遍历 根 左 右 非递归
{
	Stack ps;
	BTreeNode* pCur = NULL;
	if (NULL == BTnode)//参数检查，为空就返回，二叉树为空无法打印
		return;

	InitStack(&ps);//初始化栈
	PushStack(&ps, BTnode);//根节点不为空就压入栈
	
	while (!IsEmptyStack(&ps))//循环条件栈是否为空 栈为空就遍历结束
	{
		pCur = TopStack(&ps);//取栈顶元素
		printf("%c ", pCur->data);//遍历栈顶元素
		PopStack(&ps);//出栈
		if (pCur->right)//如果这个节点的右孩子存在就压栈
			PushStack(&ps, pCur->right);//先压入右孩子的原因是，前序遍历是 根 左 右
		//然后栈的特点是先入后出，所以先压入右孩子，后访问右孩子
		if (pCur->left)//如果这个节点的左孩子存在就压栈
			PushStack(&ps, pCur->left);
	}
}

void InOrderNor(BTreeNode* BTnode)//中序遍历  左 根 右 非递归
{
	Stack ps;
	BTreeNode* pCur = NULL;
	if (BTnode == NULL)//参数检测
		return;

	pCur = BTnode;//根节点赋给新节点
	InitStack(&ps);//初始化栈

	while (!IsEmptyStack(&ps) || pCur)//循环条件是栈不为空，或者当前节点不为空
	{
		//中序遍历，先找的根节点的最左侧节点
		//并且保存路径中每个节点
		while (pCur)//
		{
			PushStack(&ps, pCur);
			pCur = pCur->left;
		}
		//出循环表示最左侧节点已经入栈且在栈顶位置
		//也表示当前栈顶元素的左孩子为空,
		pCur = TopStack(&ps);//取栈顶元素
		printf("%c ", pCur->data);//遍历
		PopStack(&ps);//出栈
		//最左侧孩子的左孩子和根节点都已经遍历结束
		pCur = pCur->right;//遍历当前节点的右孩子--->继续循环
	}
}

void PostOrderNor(BTreeNode* BTnode)//后序遍历  左 右 根 非递归
{
	Stack ps;
	BTreeNode* pCur = NULL;
	BTreeNode* pTop = NULL;
	BTreeNode* pPer = NULL;


	if (NULL == BTnode)//参数检查
	{
		printf("该二叉树为空树，无法遍历！！！\n");
		return;
	}
	
	InitStack(&ps);//初始化栈
	pCur = BTnode;

	while (!IsEmptyStack(&ps) || pCur)
	{
		//后序遍历，先找的根节点的最左侧节点
		//并且保存路径中每个节点
		while (pCur)
		{
			PushStack(&ps, pCur);
			pCur = pCur->left;
		}
		//出循环表示最左侧节点已经入栈且在栈顶位置
		//也表示当前栈顶元素也就是最左侧节点的左孩子为空,
		pTop = TopStack(&ps);//取栈顶元素
		//有两种可能，
		//第一种当前节点没有右孩子
		//第二种当前节点有右孩子
		if (!pTop->right || pPer == pTop->right)
		{//当前节点没有右孩子可直接遍历当前节点 || 当前节点有右孩子节点但右孩子已经遍历过了
			printf("%c ", pTop->data);
			PopStack(&ps);
			pPer = pTop;//标记当前遍历的节点以防出现死循环
		}
		else//当前节点存在右孩子节点，先遍历右子树
			pCur = pTop->right;
	}

}