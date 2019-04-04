#pragma once

//这是一个实现红黑树的demo
//红黑树的性质：
//1，根节点必须是黑色的
//2，红色节点的两个孩子节点必须是黑色的-----没有连在一起的红色节点
//3，对于每个节点，从该节点到其后代的叶子节点的简单路径上，
//                       具有相同数目的黑色节点----每条路径上黑色节点的个数是相同的
//4，每个叶子节点都是黑色的
//满足以上情况，红黑树就能满足，其最长路径中节点的个数不会超过最短路径中节点个数的两倍

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
	Color _color;//节点颜色
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

	//插入节点的情况分类
	//是否是第一个节点
	//情况一:祖父节点是黑色的，父节点和叔叔节点是红色的，插入节点是红色的
	//情况二:
	bool Insert(const V& data)
	{
		pRBTreeNode& pRoot = GetRoot();
		if (nullptr == pRoot)
		{
			//插入的第一个节点
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
			//插入结束，调整树，使其满足红黑树的性质
			//更新节点的颜色，双亲节点的颜色是红色的时候，需要更新树中其他节点的颜色
			while (pParent != _pHead && pParent->_color == RED)
			{
				pRBTreeNode grandFather = pParent->pParent;
				if (pParent == grandFather->pLeft)
				{
					pRBTreeNode uncle = grandFather->pRight;
					//情况一:叔叔节点存在，且为红色
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
						//情况三:pcur在双亲的右侧
						if (pCur == pParent->pRight)
						{
							RotateLeft(pParent);
							swap(pCur, pParent);
						}
						//情况二
						grandFather->_color = RED;
						pParent->_color = BLACK;
						RotateRight(grandFather);
					}
				}
				else
				{
					pRBTreeNode uncle = grandFather->pLeft;
					//情况一:叔叔节点存在，且为红色
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
						//情况三:pcur在双亲的左侧
						if (pCur == pParent->pLeft)
						{
							RotateRight(pParent);
							swap(pCur, pParent);
						}
						//情况二
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

	//获取树的节点个数
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
			cout << "违反性质2：根节点是红色" << endl;
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
	//获取根节点
	pRBTreeNode& GetRoot()
	{
		return _pHead->pParent;
	}

	//右单旋
	void RotateRight(pRBTreeNode pParent)
	{
		pRBTreeNode pSubL = pParent->pLeft;//pSubL一定不会为空
		pRBTreeNode pSubLR = pSubL->pRight;

		//处理pSubLR
		pParent->pLeft = pSubLR;
		if (pSubLR)
			pSubLR->pParent = pParent;

		pSubL->pRight = pParent;
		//处理pParent
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

	//左单旋
	void RotateLeft(pRBTreeNode pParent)
	{
		pRBTreeNode pSubR = pParent->pRight;
		pRBTreeNode pSubRL = pSubR->pLeft;

		//处理pSubRL
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

	//最左侧节点
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

	//最右侧节点
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

	//中序遍历
	void _InOrder(pRBTreeNode& pRoot)
	{
		if (pRoot)
		{
			_InOrder(pRoot->pLeft);
			cout << pRoot->_data << " ";
			_InOrder(pRoot->pRight);
		}
	}

	//销毁
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

	//判断是否是红黑树
	bool _IsRBTree(pRBTreeNode pRoot, size_t black_Count, size_t path_black_count)
	{
		if (pRoot == nullptr)
			return true;

		if (BLACK == pRoot->_color)
			path_black_count++;

		pRBTreeNode pParent = pRoot->pParent;
		if (pParent && RED == pParent->_color && RED == pRoot->_color)
		{
			cout << "违反性质三：有连在一起的红色节点" << endl;
			return false;
		}

		if (nullptr == pRoot->pLeft && nullptr == pRoot->pRight)
		{
			if (black_Count != path_black_count)
			{
				cout << "违反性质四：每条路径中黑色节点相同" << endl;
				return false;
			}
		}

		return _IsRBTree(pRoot->pLeft, black_Count, path_black_count) && _IsRBTree(pRoot->pRight, black_Count, path_black_count);
	}
private:
	pRBTreeNode _pHead;//头结点，双亲指针域指向根，左指针域指向最小的，右指针域是最大的下一个位置
	int _size;//节点的个数
};