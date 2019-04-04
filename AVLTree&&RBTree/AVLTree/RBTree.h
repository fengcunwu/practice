#pragma once

//����һ��ʵ�ֺ������demo
//����������ʣ�
//1�����ڵ�����Ǻ�ɫ��
//2����ɫ�ڵ���������ӽڵ�����Ǻ�ɫ��-----û������һ��ĺ�ɫ�ڵ�
//3������ÿ���ڵ㣬�Ӹýڵ㵽������Ҷ�ӽڵ�ļ�·���ϣ�
//                       ������ͬ��Ŀ�ĺ�ɫ�ڵ�----ÿ��·���Ϻ�ɫ�ڵ�ĸ�������ͬ��
//4��ÿ��Ҷ�ӽڵ㶼�Ǻ�ɫ��
//�������������������������㣬���·���нڵ�ĸ������ᳬ�����·���нڵ����������

#include <iostream>
#include <stdlib.h>

using namespace std;

enum Color{RED, BLACK};

template<class V>
struct RBTreeNode
{
	RBTreeNode(const V& data = V(), const Color color = RED)
		: pLeft(nullptr)
		, pRight(nullptr)
		, pParent(nullptr)
		, _data(data)
		, _color(color)
	{}

	RBTreeNode<V>* pLeft;
	RBTreeNode<V>* pRight;
	RBTreeNode<V>* pParent;
	V _data;
	Color _color;//�ڵ���ɫ
};

template<class V>
class RBTree
{
	typedef RBTreeNode<V> RBTreeNode;
	typedef RBTreeNode* pRBTreeNode;
public:
	RBTree()
		: _size(0)
	{
		_pHead = new RBTreeNode;
		_pHead->pLeft = _pHead;
		_pHead->pRight = _pHead;
		_pHead->pParent = nullptr;
	}

	//����ڵ���������
	//�Ƿ��ǵ�һ���ڵ�
	//���һ:�游�ڵ��Ǻ�ɫ�ģ����ڵ������ڵ��Ǻ�ɫ�ģ�����ڵ��Ǻ�ɫ��
	//�����:
	bool Insert(const V& data)
	{
		pRBTreeNode& pRoot = GetRoot();
		if (nullptr == pRoot)
		{
			//����ĵ�һ���ڵ�
			pRoot = new RBTreeNode(data, BLACK);
			pRoot->pParent = _pHead;
		}
		else
		{
			pRBTreeNode pCur = pRoot;
			pRBTreeNode pParent = nullptr;
			while (pCur)
			{
				pParent = pCur;
				if (data < pCur->_data)
					pCur = pCur->pLeft;
				else if (data > pCur->_data)
					pCur = pCur->pRight;
				else
					return false;
			}
			pCur = new RBTreeNode(data);
			if (data < pParent->_data)
				pParent->pLeft = pCur;
			else
				pParent->pRight = pCur;
			pCur->pParent = pParent;
			//�����������������ʹ����������������
			//���½ڵ����ɫ��˫�׽ڵ����ɫ�Ǻ�ɫ��ʱ����Ҫ�������������ڵ����ɫ
			while (pParent != _pHead && pParent->_color == RED)
			{
				pRBTreeNode grandFather = pParent->pParent;
				if (pParent == grandFather->pLeft)
				{
					pRBTreeNode uncle = grandFather->pRight;
					//���һ:����ڵ���ڣ���Ϊ��ɫ
					if (uncle && uncle->_color == RED)
					{
						pParent->_color = BLACK;
						uncle->_color = BLACK;
						grandFather->_color = RED;

						pCur = grandFather;
						pParent = pCur->pParent;
					}
					else
					{
						//�����:pcur��˫�׵��Ҳ�
						if (pCur == pParent->pRight)
						{
							RotateLeft(pParent);
							swap(pCur, pParent);
						}
						//�����
						grandFather->_color = RED;
						pParent->_color = BLACK;
						RotateRight(grandFather);
					}
				}
				else
				{
					pRBTreeNode uncle = grandFather->pLeft;
					//���һ:����ڵ���ڣ���Ϊ��ɫ
					if (uncle && uncle->_color == RED)
					{
						pParent->_color = BLACK;
						uncle->_color = BLACK;
						grandFather->_color = RED;

						pCur = grandFather;
						pParent = pCur->pParent;
					}
					else
					{
						//�����:pcur��˫�׵����
						if (pCur == pParent->pLeft)
						{
							RotateRight(pParent);
							swap(pCur, pParent);
						}
						//�����
						grandFather->_color = RED;
						pParent->_color = BLACK;
						RotateLeft(grandFather);
					}
				}
			}
		}
		_size++;
		pRoot->_color = BLACK;
		_pHead->pLeft = LeftMost();
		_pHead->pRight = RightMost();
		return true;
	}

	void InOrder()
	{
		pRBTreeNode& pRoot = GetRoot();
		_InOrder(pRoot);
		cout << endl;
	}

	~RBTree()
	{
		_Destory(GetRoot());
	}

	//��ȡ���Ľڵ����
	int Size()
	{
		return _size;
	}

	bool IsRBTree()
	{
		pRBTreeNode pRoot = GetRoot();
		if (nullptr == pRoot)
			return true;

		if (pRoot->_color == RED)
		{
			cout << "Υ������2�����ڵ��Ǻ�ɫ" << endl;
		}
		pRBTreeNode pCur = pRoot;
		size_t black_Count = 0;
		while (pCur)
		{
			if (pCur->_color == BLACK)
				black_Count++;
			pCur = pCur->pLeft;
		}

		size_t path_black_count = 0;
		return _IsRBTree(pRoot, black_Count, path_black_count);
	}

private:
	//��ȡ���ڵ�
	pRBTreeNode& GetRoot()
	{
		return _pHead->pParent;
	}

	//�ҵ���
	void RotateRight(pRBTreeNode pParent)
	{
		pRBTreeNode pSubL = pParent->pLeft;//pSubLһ������Ϊ��
		pRBTreeNode pSubLR = pSubL->pRight;

		//����pSubLR
		pParent->pLeft = pSubLR;
		if (pSubLR)
			pSubLR->pParent = pParent;

		pSubL->pRight = pParent;
		//����pParent
		pRBTreeNode ppParent = pParent->pParent;
		pRBTreeNode& pRoot = GetRoot();
		pSubL->pParent = ppParent;
		pParent->pParent = pSubL;
		if (pRoot == pParent)
			pRoot = pSubL;
		else
		{
			if (ppParent->pLeft == pParent)
				ppParent->pLeft = pSubL;
			else
				ppParent->pRight = pSubL;
		}
	}

	//����
	void RotateLeft(pRBTreeNode pParent)
	{
		pRBTreeNode pSubR = pParent->pRight;
		pRBTreeNode pSubRL = pSubR->pLeft;

		//����pSubRL
		pParent->pRight = pSubRL;
		if (pSubRL)
			pSubRL->pParent = pParent;

		pSubR->pLeft = pParent;
		pRBTreeNode ppParent = pParent->pParent;
		pRBTreeNode& pRoot = GetRoot();
		pParent->pParent = pSubR;
		pSubR->pParent = ppParent;
		if (pParent == pRoot)
			pRoot = pSubR;
		else
		{
			if (pParent == ppParent->pLeft)
				ppParent->pLeft = pSubR;
			else
				ppParent->pRight = pSubR;
		}
	}

	//�����ڵ�
	pRBTreeNode LeftMost()
	{
		pRBTreeNode pRoot = GetRoot();
		if (pRoot == nullptr)
			return pRoot;
		pRBTreeNode pCur = pRoot;
		while (pCur->pLeft)
			pCur = pCur->pLeft;

		return pCur;
	}

	//���Ҳ�ڵ�
	pRBTreeNode RightMost()
	{
		pRBTreeNode pRoot = GetRoot();
		if (pRoot == nullptr)
			return pRoot;
		pRBTreeNode pCur = pRoot;
		while (pCur->pRight)
			pCur = pCur->pRight;

		return pCur;
	}

	//�������
	void _InOrder(pRBTreeNode& pRoot)
	{
		if (pRoot)
		{
			_InOrder(pRoot->pLeft);
			cout << pRoot->_data << " ";
			_InOrder(pRoot->pRight);
		}
	}

	//����
	void _Destory(pRBTreeNode& pRoot)
	{
		if (pRoot)
		{
			_Destory(pRoot->pLeft);
			_Destory(pRoot->pRight);
			delete pRoot;
			pRoot = nullptr;
		}
	}

	//�ж��Ƿ��Ǻ����
	bool _IsRBTree(pRBTreeNode pRoot, size_t black_Count, size_t path_black_count)
	{
		if (pRoot == nullptr)
			return true;

		if (BLACK == pRoot->_color)
			path_black_count++;

		pRBTreeNode pParent = pRoot->pParent;
		if (pParent && RED == pParent->_color && RED == pRoot->_color)
		{
			cout << "Υ����������������һ��ĺ�ɫ�ڵ�" << endl;
			return false;
		}

		if (nullptr == pRoot->pLeft && nullptr == pRoot->pRight)
		{
			if (black_Count != path_black_count)
			{
				cout << "Υ�������ģ�ÿ��·���к�ɫ�ڵ���ͬ" << endl;
				return false;
			}
		}

		return _IsRBTree(pRoot->pLeft, black_Count, path_black_count) && _IsRBTree(pRoot->pRight, black_Count, path_black_count);
	}
private:
	pRBTreeNode _pHead;//ͷ��㣬˫��ָ����ָ�������ָ����ָ����С�ģ���ָ������������һ��λ��
	int _size;//�ڵ�ĸ���
};