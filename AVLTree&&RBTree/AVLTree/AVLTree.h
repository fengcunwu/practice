#pragma once

//����һ��ʵ��AVL��demo

#include <iostream>
#include <stdlib.h>

using namespace std;

template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& data)
	: pLeft(nullptr)
	, pRight(nullptr)
	, pParent(nullptr)
	, _data(data)
	, _df(0)
	{}

	AVLTreeNode<T>* pLeft;
	AVLTreeNode<T>* pRight;
	AVLTreeNode<T>* pParent;//����˫�ױ�ʾ��
	T _data;//����
	int _df;//ƽ������
};

template<class T>
class AVLTree
{
public:
	typedef AVLTreeNode<T> AVLTNode;
	typedef AVLTreeNode<T>* pAVLTNode;
	AVLTree()
		:_pRoot(nullptr)
	{}

	//�������
	bool Insert(const T& data)
	{
		//����
		if (_pRoot == nullptr)
		{
			_pRoot = new AVLTNode(data);
			return true;
		}
		//���ǿ�����Ѱ�Ҳ���λ�ã��Ͷ���������һ��
		pAVLTNode pParent = nullptr;
		pAVLTNode pCur = _pRoot;
		while (pCur)
		{
			pParent = pCur;
			if (pCur->_data < data)
				pCur = pCur->pRight;
			else if (pCur->_data > data)
				pCur = pCur->pLeft;
			else//Ҫ��������ݺ͵�ǰ������ͬ�����ò���
				return false;
		}

		//�ж����Ĳ壬
		pCur = new AVLTNode(data);
		if (data < pParent->_data)
			pParent->pLeft = pCur;
		else
			pParent->pRight = pCur;

		pCur->pParent = pParent;

		while (pParent)
		{
			//����ƽ������
			if (pParent->pLeft == pCur)
				pParent->_df--;
			else
				pParent->_df++;

			//��ǰ˫�׵�ƽ�������ж��������0, 1, 2, -1, -2,
			if (pParent->_df == 0)
				break;
			else if (pParent->_df == 1 || pParent->_df == -1)
			{
				pCur = pParent;
				pParent = pCur->pParent;
			}
			else//ƽ������Ϊ2����-2
			{
				//����һ��AVL����ƽ�����⵽���ƻ���Ҫ������ת����
				//���� �ҵ��� ����˫�� ����˫��
				//����----�²���ڵ��ڽϸ������������(�Ҳ�)
				//�ҵ���----�½ڵ���뵽�ϸ������������(���)
				//����˫��----�½ڵ���뵽�ϸ����������ڲ�(�Ҳ�)
				//����˫��----�½ڵ���뵽�ϸ����������ڲ�(���)
				if (pParent->_df == 2)
				{
					if (pCur->_df == 1)
						RotateLeft(pParent);
					else
						RotateRL(pParent);
				}
				else
				{
					if (pCur->_df == -1)
						RotateRight(pParent);
					else
						RotateLR(pParent);
				}
				break;
			}
		}
		return true;
	}
	//�������
	void InOrder()
	{
		_InOrder(_pRoot);
	}
	//��������
	~AVLTree()
	{
		_Destroy(_pRoot);
	}

	//�ж��Ƿ���AVL��
	bool IsAVLTree()
	{
		return _IsAVLTree(_pRoot);
	}

	//��avl���ĸ߶�
	size_t Height()
	{
		return _Height(_pRoot);
	}
	
	//AVL����ɾ������
	//�ȸ���AVL���������ҵ���ɾ���Ľڵ�
	//ɾ���ýڵ㣬Ȼ�����ƽ�����ӣ�����ýڵ��˫�׽ڵ��ƽ��������1������-1��˵����˫�׽ڵ�Ϊ���������ĸ߶�δ�ı�
	//���˫�׵�ƽ��������0����Ҫ���ϸ���ƽ�����ӣ�ֱ��ƽ��������-1����1Ϊֹ���������Ǹ��µ����ڵ�
	//���˫�׽ڵ��ƽ��������-2������2�Ļ�Ҫ������ת����Ȼ�����ж�ƽ������
	//ɾ������̫��

private :
	//�ҵ���
	void RotateRight(pAVLTNode pParent)
	{
		pAVLTNode pSubL = pParent->pLeft;//pSubLһ������Ϊ��
		pAVLTNode pSubLR = pSubL->pRight;

		//����pSubLR
		pParent->pLeft = pSubLR;
		if (pSubLR)
			pSubLR->pParent = pParent;

		pSubL->pRight = pParent;
		//����pParent
		pAVLTNode ppParent = pParent->pParent;
		pSubL->pParent = ppParent;
		pParent->pParent = pSubL;
		if (nullptr == ppParent)
			_pRoot = pSubL;
		else
		{
			if (ppParent->pLeft == pParent)
				ppParent->pLeft = pSubL;
			else
				ppParent->pRight = pSubL;
		}
	
		//����ƽ������
		pParent->_df = 0;
		pSubL->_df = 0;
	}

	void RotateLeft(pAVLTNode pParent)
	{
		pAVLTNode pSubR = pParent->pRight;
		pAVLTNode pSubRL = pSubR->pLeft;

		//����pSubRL
		pParent->pRight = pSubRL;
		if (pSubRL)
			pSubRL->pParent = pParent;

		pSubR->pLeft = pParent;
		pAVLTNode ppParent = pParent->pParent;
		pParent->pParent = pSubR;
		pSubR->pParent = ppParent;
		if (ppParent == nullptr)
			_pRoot = pSubR;
		else
		{
			if (pParent == ppParent->pLeft)
				ppParent->pLeft = pSubR;
			else
				ppParent->pRight = pSubR;
		}
		//����ƽ������
		pParent->_df = pSubR->_df = 0;
	}
	//����˫��
	void RotateRL(pAVLTNode pParent)
	{
		pAVLTNode pSubR = pParent->pRight;
		pAVLTNode pSubRL = pSubR->pLeft;
		int bf = pSubRL->_df;
		RotateRight(pParent->pRight);
		RotateLeft(pParent);

		//����ƽ������
		if (bf == 1)
		{
			pParent->_df = -1;
		}
		else if (bf == -1)
		{
			pSubR->_df = 1;
		}
	}
	//����˫��
	void RotateLR(pAVLTNode pParent)
	{
		pAVLTNode pSubL = pParent->pLeft;
		pAVLTNode pSubLR = pSubL->pRight;
		int bf = pSubLR->_df;
		RotateLeft(pParent->pLeft);
		RotateRight(pParent);

		//����ƽ������
		if (bf == 1)
		{
			pSubL->_df = -1;
		}
		else if (bf == -1)
		{
			pParent->_df = 1;
		}
	}

	void _InOrder(pAVLTNode& pRoot)
	{
		if (pRoot)
		{
			_InOrder(pRoot->pLeft);
			cout << pRoot->_data << ' '  ;
			_InOrder(pRoot->pRight);
		}
	}
	void _Destory(pAVLTNode& pRoot)
	{
		if (pRoot)
		{
			_Destory(pRoot->pLeft);
			_Destroy(pRoot->pRight);
			delete pRoot;
			pRoot = nullptr;
		}
	}

	size_t _Height(pAVLTNode& pRoot)
	{
		if (pRoot == nullptr)
			return 0;
		else
			return _Height(pRoot->pLeft) > _Height(pRoot->pRight) ? _Height(pRoot->pLeft) + 1 : _Height(pRoot->pRight) + 1;
	}

	bool _IsAVLTree(pAVLTNode& pRoot)
	{
		if (pRoot == nullptr)
			return true;
		
		size_t leftHeight = _Height(pRoot->pLeft);
		size_t rightHeight = _Height(pRoot->pRight);

		if (abs(pRoot->_df > 1) || (rightHeight - leftHeight != pRoot->_df))
			return false;

		return _IsAVLTree(pRoot->pLeft) && _IsAVLTree(pRoot->pRight);
	}
private:
	pAVLTNode _pRoot;
};