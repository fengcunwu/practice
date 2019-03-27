
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
	//���캯��
	BSTree()
		:_pRoot(nullptr)
	{}

	//��������
	~BSTree()
	{
		Destroy(_pRoot);
	}

	//����ڵ�
	bool Insert(const T& data)
	{
		//����
		if (_pRoot == nullptr)
		{
			_pRoot = new BSTNode(data);
			return true;
		}

		//���ǿ�
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

	//�������
	void InOrder()
	{
		_InOrder(_pRoot);
		cout << endl;
	}

	//����
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

	//ɾ���ڵ�
	bool Erase(const T& data)
	{
		//�ҵ���ɾ���ڵ��λ��
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
		//�Ѿ��ҵ���ɾ���ڵ㣬�����ɾ���ڵ�
		//��������֣�Ҷ�ӽڵ㣬ֻ������ ֻ���Һ��Ӷ�����ֱ��ɾ��
		//���Һ��Ӷ����ڲ���ֱ��ɾ����

		//Ҷ�ӽڵ㣬���Ժ�ֻ���Һ��Ӻϲ�����
		//ֻ���Һ���
		if (pCur->pLeft == nullptr)
		{
			//��ǰ�ڵ�Ϊ���ڵ�
			if (pCur == _pRoot)
				_pRoot = pCur->pRight;
			else//���Ǹ��ڵ�
			{
				if (pParent->pLeft == pCur)
					pParent->pLeft = pCur->pRight;
				else
					pParent->pRight = pCur->pRight;
			}

			delete pCur;
			return true;
		}
		else if (pCur->pRight == nullptr)//ֻ������
		{
			//��ǰ�ڵ�Ϊ���ڵ�
			if (pCur == _pRoot)
				_pRoot = pCur->pLeft;
			else//���Ǹ��ڵ�
			{
				if (pParent->pLeft == pCur)
					pParent->pLeft = pCur->pLeft;
				else
					pParent->pRight = pCur->pLeft;
			}
			//����
			delete pCur;
			return true;
		}
		else//���Һ��Ӷ�����
		{
			//Ҫ��һ������ڵ㣬���������������Ļ���������������С��

			//ѡ��������������С��
			pBSTNode pFristOfIn = pCur->pRight;
			pParent = pCur;
			while (pFristOfIn->pLeft)
			{
				pParent = pFristOfIn;
				pFristOfIn = pFristOfIn->pLeft;
			}
			pCur->_data = pFristOfIn->_data;

			//����������ɾ��pFristOfIn�ڵ㣬����ڵ�һ��û�����������϶����Ǹ��ڵ�
			if (pParent->pLeft == pFristOfIn)
				pParent->pLeft = pFristOfIn->pRight;
			else
				pParent->pRight = pFristOfIn->pRight;

			//����
			delete pFristOfIn;
			return true;
		}
	}
private:
	//�������
	void _InOrder(pBSTNode &pRoot)
	{
		if (pRoot)
		{
			_InOrder(pRoot->pLeft);
			cout << pRoot->_data << " ";
			_InOrder(pRoot->pRight);
		}
	}

	//����
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