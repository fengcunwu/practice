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

void PreOrder(BTreeNode* BTnode)//���������ڵ㣬�Ӹ���ʼ������
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

void InOrder(BTreeNode* BTnode)//�������  �� �� ��
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

void PostOrder(BTreeNode* BTnode)//������� �� �� ��
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
	int* index, DataType invalid)//BTnode�д�ŵ��Ǹ��ڵ�ĵ�ַ
{
	assert(BTnode);
	assert(str);
	assert(index);

	if ((*index) < size && str[*index] != invalid)
	{
		//�������ڵ�
		*BTnode = BuyBTNode(str[*index]);
		//�������ӽڵ�
		++(*index);
		CreateBinTree(&((*BTnode)->left), str, size, index, invalid);
		//�����Һ��ӽڵ�
		++(*index);
		CreateBinTree(&((*BTnode)->right), str, size, index, invalid);
	}
}

BTreeNode* CopyBinTree(BTreeNode* BTnode)//�������ĸ���
{
	BTreeNode* pNewNode;
	if (NULL == BTnode)
		return NULL;
	
	//���Ƹ��ڵ�
	pNewNode = BuyBTNode(BTnode->data);

	//������ڵ�
	pNewNode->left = CopyBinTree(BTnode->left);
	
	//�����ҽڵ�
	pNewNode->right = CopyBinTree(BTnode->right);

	return pNewNode;
}

void DestroyBinTree(BTreeNode** BTnode)//���ٶ����� ����˳�� �� �� ��
{
	assert(BTnode);

	if (*BTnode == NULL)
		return;

	DestroyBinTree(&((*BTnode)->left));
	DestroyBinTree(&((*BTnode)->right));
	free(*BTnode);
	*BTnode = NULL;
}

int GetSizeBinTreeCount(BTreeNode* BTnode)//���ض��������нڵ���
{
	if (NULL == BTnode)
		return 0;

	return GetSizeBinTreeCount(BTnode->left)
		   + GetSizeBinTreeCount(BTnode->right) + 1;
}

int GetLeafBinTreeCount(BTreeNode* BTnode)//���ض�����Ҷ�ӽڵ���
{
	if (BTnode == NULL)
		return 0;

	if (BTnode->left == NULL && BTnode->right == NULL)
		return 1;
	
	return GetLeafBinTreeCount(BTnode->left) + GetLeafBinTreeCount(BTnode->right);
}

int GetKSizeBinTreeCount(BTreeNode* BTnode, int K)//���ض�������k��Ľڵ���
{
	if (BTnode == NULL || K <= 0)
		return 0;
	if (K == 1)
		return 1;
	return GetKSizeBinTreeCount(BTnode->left, K - 1)
		+ GetKSizeBinTreeCount(BTnode->right, K - 1);
}

int HeightBinTree(BTreeNode* BTnode)//�õ��������ĸ߶�
{
	if (NULL == BTnode)
		return 0;
	return HeightBinTree(BTnode->left) > HeightBinTree(BTnode->right) ?
		HeightBinTree(BTnode->left) + 1 : HeightBinTree(BTnode->right) + 1;
}

BTreeNode* LeftBinTree(BTreeNode* BTnode)//�õ������������ӽڵ�
{
	if (NULL == BTnode)
		return NULL;
	return BTnode->left;
}

BTreeNode* RightBinTree(BTreeNode* BTnode)//�õ����������Һ��ӽڵ�
{
	if (NULL == BTnode)
		return NULL;
	return BTnode->right;
}

int IsExistInBinTree(BTreeNode* BTnode, BTreeNode* pNode)//�жϽڵ��Ƿ��ڶ�������
{
	if (NULL == BTnode || NULL == pNode)
		return 0;

	if (BTnode == pNode)
		return 1;

	if (IsExistInBinTree(BTnode->left, pNode))
		return 1;

	return IsExistInBinTree(BTnode->right, pNode);
}

BTreeNode* ParentBinTree(BTreeNode* BTnode, BTreeNode* pNode)//���ؽڵ��˫�׽ڵ�
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
////////////////ջ�Ͷ��еĸ�������///////////////////////////

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
		printf("��������,�޷���ӣ�����\n");
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
		printf("������û�����ݣ��޷����ӣ�����\n");
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
		printf("����Ϊ��,û�ж�ͷԪ�أ�����\n");
		return NULL;
	}
	return q->array[q->front];
}

int IsEmptyQueue(Queue* q)//����1,˵��Ϊ��
{
	assert(q);
	return 0 == q->count;
}


void LevelOrder(BTreeNode* BTnode)//�������������
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

void Swap(BTreeNode** left, BTreeNode** right)//�������������Ӻ��Һ��ӽ���
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

void MirrorBinTreeNor(BTreeNode* BTnode)//����������ǵݹ�
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

int IsCompleteBinTree(BTreeNode* BTnode)//�ж϶������Ƿ�Ϊ��ȫ������
{
	Queue q;
	int flag = 0;
	BTreeNode* pCur = NULL;
	if (BTnode == NULL)
		return 1;//����Ҳ����ȫ������

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
		printf("��ջ����,�޷�ѹ��!!\n");
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
		printf("��ջΪ�գ��޷���ջ������\n");
		return;
	}
	ps->top--;
}

int IsEmptyStack(Stack* ps)//����1��ʾΪ��
{
	assert(ps);
	return 0 == ps->top;
}

SDataType TopStack(Stack* ps)
{
	assert(ps);
	if (ps->top == 0)
	{
		printf("ջΪ��,û��ջ��Ԫ�أ���\n");
		return 0;
	}
	return ps->array[ps->top - 1];
}

void PreOrderNor(BTreeNode* BTnode)//ǰ����� �� �� �� �ǵݹ�
{
	Stack ps;
	BTreeNode* pCur = NULL;
	if (NULL == BTnode)//������飬Ϊ�վͷ��أ�������Ϊ���޷���ӡ
		return;

	InitStack(&ps);//��ʼ��ջ
	PushStack(&ps, BTnode);//���ڵ㲻Ϊ�վ�ѹ��ջ
	
	while (!IsEmptyStack(&ps))//ѭ������ջ�Ƿ�Ϊ�� ջΪ�վͱ�������
	{
		pCur = TopStack(&ps);//ȡջ��Ԫ��
		printf("%c ", pCur->data);//����ջ��Ԫ��
		PopStack(&ps);//��ջ
		if (pCur->right)//�������ڵ���Һ��Ӵ��ھ�ѹջ
			PushStack(&ps, pCur->right);//��ѹ���Һ��ӵ�ԭ���ǣ�ǰ������� �� �� ��
		//Ȼ��ջ���ص�����������������ѹ���Һ��ӣ�������Һ���
		if (pCur->left)//�������ڵ�����Ӵ��ھ�ѹջ
			PushStack(&ps, pCur->left);
	}
}

void InOrderNor(BTreeNode* BTnode)//�������  �� �� �� �ǵݹ�
{
	Stack ps;
	BTreeNode* pCur = NULL;
	if (BTnode == NULL)//�������
		return;

	pCur = BTnode;//���ڵ㸳���½ڵ�
	InitStack(&ps);//��ʼ��ջ

	while (!IsEmptyStack(&ps) || pCur)//ѭ��������ջ��Ϊ�գ����ߵ�ǰ�ڵ㲻Ϊ��
	{
		//������������ҵĸ��ڵ�������ڵ�
		//���ұ���·����ÿ���ڵ�
		while (pCur)//
		{
			PushStack(&ps, pCur);
			pCur = pCur->left;
		}
		//��ѭ����ʾ�����ڵ��Ѿ���ջ����ջ��λ��
		//Ҳ��ʾ��ǰջ��Ԫ�ص�����Ϊ��,
		pCur = TopStack(&ps);//ȡջ��Ԫ��
		printf("%c ", pCur->data);//����
		PopStack(&ps);//��ջ
		//����ຢ�ӵ����Ӻ͸��ڵ㶼�Ѿ���������
		pCur = pCur->right;//������ǰ�ڵ���Һ���--->����ѭ��
	}
}

void PostOrderNor(BTreeNode* BTnode)//�������  �� �� �� �ǵݹ�
{
	Stack ps;
	BTreeNode* pCur = NULL;
	BTreeNode* pTop = NULL;
	BTreeNode* pPer = NULL;


	if (NULL == BTnode)//�������
	{
		printf("�ö�����Ϊ�������޷�����������\n");
		return;
	}
	
	InitStack(&ps);//��ʼ��ջ
	pCur = BTnode;

	while (!IsEmptyStack(&ps) || pCur)
	{
		//������������ҵĸ��ڵ�������ڵ�
		//���ұ���·����ÿ���ڵ�
		while (pCur)
		{
			PushStack(&ps, pCur);
			pCur = pCur->left;
		}
		//��ѭ����ʾ�����ڵ��Ѿ���ջ����ջ��λ��
		//Ҳ��ʾ��ǰջ��Ԫ��Ҳ���������ڵ������Ϊ��,
		pTop = TopStack(&ps);//ȡջ��Ԫ��
		//�����ֿ��ܣ�
		//��һ�ֵ�ǰ�ڵ�û���Һ���
		//�ڶ��ֵ�ǰ�ڵ����Һ���
		if (!pTop->right || pPer == pTop->right)
		{//��ǰ�ڵ�û���Һ��ӿ�ֱ�ӱ�����ǰ�ڵ� || ��ǰ�ڵ����Һ��ӽڵ㵫�Һ����Ѿ���������
			printf("%c ", pTop->data);
			PopStack(&ps);
			pPer = pTop;//��ǵ�ǰ�����Ľڵ��Է�������ѭ��
		}
		else//��ǰ�ڵ�����Һ��ӽڵ㣬�ȱ���������
			pCur = pTop->right;
	}

}