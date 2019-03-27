
#include <iostream>
#include <stdlib.h>

using namespace std;

template<class T>
struct BSTreeNode
{
	BSTreeNode(const T& data)
	: pLeft(nullptr)
	, pRight(nullptr)
	, _data(data)
	{}
	BSTreeNode<T>* pLeft;
	BSTreeNode<T>* pRight;
	T _data;
};

template<class T>
class BSTree
{
public:
	typedef BSTreeNode<T> BSTNode;
	typedef BSTreeNode<T>* pBSTNode;

public:
	//构造函数
	BSTree()
		:_pRoot(nullptr)
	{}

	//析构函数
	~BSTree()
	{
		Destroy(_pRoot);
	}

	//插入节点
	bool Insert(const T& data)
	{
		//树空
		if (_pRoot == nullptr)
		{
			_pRoot = new BSTNode(data);
			return true;
		}

		//树非空
		pBSTNode pCur = _pRoot;
		pBSTNode pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;
			if (data < pCur->_data)
				pCur = pCur->pLeft;
			else if (data > pCur->_data)
				pCur = pCur->pRight;
			else
				return true;
		}
		pCur = new BSTNode(data);
		if (data < pParent->_data)
			pParent->pLeft = pCur;
		else
			pParent->pRight = pCur;

		return true;
	}

	//中序遍历
	void InOrder()
	{
		_InOrder(_pRoot);
		cout << endl;
	}

	//查找
	pBSTNode Find(const T& data)
	{
		if (_pRoot)
		{
			pBSTNode pCur = _pRoot;
			while (pCur)
			{
				if (data < pCur->_data)
					pCur = pCur->pLeft;
				else if (data > pCur->_data)
					pCur = pCur->pRight;
				else
					return pCur;
			}
			return nullptr;
		}
		return nullptr;
	}

	//删除节点
	bool Erase(const T& data)
	{
		//找到带删除节点的位置
		pBSTNode pCur = _pRoot;
		pBSTNode pParent = nullptr;
		while (pCur)
		{
			if (data == pCur->_data)
				break;
			else if (data < pCur->_data)
			{
				pParent = pCur;
				pCur = pCur->pLeft;
			}
			else
			{
				pParent = pCur;
				pCur = pCur->pRight;
			}			
		}

		if (pCur == nullptr)
			return false;
		//已经找到待删除节点，分情况删除节点
		//大概有两种，叶子节点，只有左孩子 只有右孩子都可以直接删除
		//左右孩子都存在不能直接删除，

		//叶子节点，可以和只有右孩子合并起来
		//只有右孩子
		if (pCur->pLeft == nullptr)
		{
			//当前节点为根节点
			if (pCur == _pRoot)
				_pRoot = pCur->pRight;
			else//不是根节点
			{
				if (pParent->pLeft == pCur)
					pParent->pLeft = pCur->pRight;
				else
					pParent->pRight = pCur->pRight;
			}

			delete pCur;
			return true;
		}
		else if (pCur->pRight == nullptr)//只有左孩子
		{
			//当前节点为根节点
			if (pCur == _pRoot)
				_pRoot = pCur->pLeft;
			else//不是根节点
			{
				if (pParent->pLeft == pCur)
					pParent->pLeft = pCur->pLeft;
				else
					pParent->pRight = pCur->pLeft;
			}
			//销毁
			delete pCur;
			return true;
		}
		else//左右孩子都存在
		{
			//要找一个替代节点，在左子树中找最大的或者在右子树中最小的

			//选择在右子树找最小的
			pBSTNode pFristOfIn = pCur->pRight;
			pParent = pCur;
			while (pFristOfIn->pLeft)
			{
				pParent = pFristOfIn;
				pFristOfIn = pFristOfIn->pLeft;
			}
			pCur->_data = pFristOfIn->_data;

			//现在任务是删除pFristOfIn节点，这个节点一定没有左子树，肯定不是根节点
			if (pParent->pLeft == pFristOfIn)
				pParent->pLeft = pFristOfIn->pRight;
			else
				pParent->pRight = pFristOfIn->pRight;

			//销毁
			delete pFristOfIn;
			return true;
		}
	}
private:
	//中序遍历
	void _InOrder(pBSTNode &pRoot)
	{
		if (pRoot)
		{
			_InOrder(pRoot->pLeft);
			cout << pRoot->_data << " ";
			_InOrder(pRoot->pRight);
		}
	}

	//销毁
	void Destroy(pBSTNode &pRoot)
	{
		if (pRoot)
		{
			Destroy(pRoot->pLeft);
			Destroy(pRoot->pRight);
			delete pRoot;
			pRoot = nullptr;
		}
	}
private:
	pBSTNode _pRoot;
};

int main()
{
	int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	BSTree<int> s1;
	for (auto & a : array)
	{
		s1.Insert(a);
	}
	s1.InOrder();
	cout << endl;
	BSTreeNode<int>* pNode = s1.Find(9);
	if (pNode)
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	s1.Erase(8);
	s1.InOrder();

	s1.Erase(3);
	s1.InOrder();

	s1.Erase(5);
	s1.InOrder();

	system("pause");
	return 0;
}