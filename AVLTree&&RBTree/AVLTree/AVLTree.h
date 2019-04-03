#pragma once

//这是一个实现AVL的demo

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
	AVLTreeNode<T>* pParent;//孩子双亲表示法
	T _data;//数据
	int _df;//平衡因子
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

	//插入操作
	bool Insert(const T& data)
	{
		//空树
		if (_pRoot == nullptr)
		{
			_pRoot = new AVLTNode(data);
			return true;
		}
		//不是空树，寻找插入位置，和二叉搜索树一样
		pAVLTNode pParent = nullptr;
		pAVLTNode pCur = _pRoot;
		while (pCur)
		{
			pParent = pCur;
			if (pCur->_data < data)
				pCur = pCur->pRight;
			else if (pCur->_data > data)
				pCur = pCur->pLeft;
			else//要插入的数据和当前数据相同，不用插入
				return false;
		}

		//判断往哪插，
		pCur = new AVLTNode(data);
		if (data < pParent->_data)
			pParent->pLeft = pCur;
		else
			pParent->pRight = pCur;

		pCur->pParent = pParent;

		while (pParent)
		{
			//更新平衡因子
			if (pParent->pLeft == pCur)
				pParent->_df--;
			else
				pParent->_df++;

			//当前双亲的平衡因子有多种情况，0, 1, 2, -1, -2,
			if (pParent->_df == 0)
				break;
			else if (pParent->_df == 1 || pParent->_df == -1)
			{
				pCur = pParent;
				pParent = pCur->pParent;
			}
			else//平衡因子为2或者-2
			{
				//到这一步AVL树的平衡性遭到了破坏，要进行旋转处理
				//左单旋 右单旋 左右双旋 右左双旋
				//左单旋----新插入节点在较高右子树的外侧(右侧)
				//右单旋----新节点插入到较高左子树的外侧(左侧)
				//左右双旋----新节点插入到较高左子树的内侧(右侧)
				//右左双旋----新节点插入到较高右子树的内侧(左侧)
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
	//中序遍历
	void InOrder()
	{
		_InOrder(_pRoot);
	}
	//析构函数
	~AVLTree()
	{
		_Destroy(_pRoot);
	}

	//判断是否是AVL树
	bool IsAVLTree()
	{
		return _IsAVLTree(_pRoot);
	}

	//求avl树的高度
	size_t Height()
	{
		return _Height(_pRoot);
	}
	
	//AVL树的删除操作
	//先根据AVL树的性质找到该删除的节点
	//删除该节点，然后更新平衡因子，如果该节点的双亲节点的平衡因子是1或者是-1，说明以双亲节点为根的子树的高度未改变
	//如果双亲的平衡因子是0，就要向上更新平衡因子，直到平衡因子是-1或者1为止，最差情况是更新到根节点
	//如果双亲节点的平衡因子是-2或者是2的话要进行旋转处理，然后在判断平衡因子
	//删除性能太差

private :
	//右单旋
	void RotateRight(pAVLTNode pParent)
	{
		pAVLTNode pSubL = pParent->pLeft;//pSubL一定不会为空
		pAVLTNode pSubLR = pSubL->pRight;

		//处理pSubLR
		pParent->pLeft = pSubLR;
		if (pSubLR)
			pSubLR->pParent = pParent;

		pSubL->pRight = pParent;
		//处理pParent
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
	
		//更新平衡因子
		pParent->_df = 0;
		pSubL->_df = 0;
	}

	void RotateLeft(pAVLTNode pParent)
	{
		pAVLTNode pSubR = pParent->pRight;
		pAVLTNode pSubRL = pSubR->pLeft;

		//处理pSubRL
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
		//更新平衡因子
		pParent->_df = pSubR->_df = 0;
	}
	//右左双旋
	void RotateRL(pAVLTNode pParent)
	{
		pAVLTNode pSubR = pParent->pRight;
		pAVLTNode pSubRL = pSubR->pLeft;
		int bf = pSubRL->_df;
		RotateRight(pParent->pRight);
		RotateLeft(pParent);

		//调整平衡因子
		if (bf == 1)
		{
			pParent->_df = -1;
		}
		else if (bf == -1)
		{
			pSubR->_df = 1;
		}
	}
	//左右双旋
	void RotateLR(pAVLTNode pParent)
	{
		pAVLTNode pSubL = pParent->pLeft;
		pAVLTNode pSubLR = pSubL->pRight;
		int bf = pSubLR->_df;
		RotateLeft(pParent->pLeft);
		RotateRight(pParent);

		//调整平衡因子
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