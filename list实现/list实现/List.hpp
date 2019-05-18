#pragma once
#include <iostream>

template<class T>
struct ListNode
{
public:
	ListNode(const T& data = T())
		: _data(data)
		, _pNext(nullptr)
		, _pPre(nullptr)
	{}
	T _data;
	ListNode<T>* _pNext;
	ListNode<T>* _pPre;
};
//ͨ�����Ӳ����б��ñ�������������const�ĵ�����������ͨ���͵ĵ�����
template<class T, class Ref, class Ptr>
class ListIterator
{
public:
	typedef ListNode<T>* pNode;
	typedef ListIterator<T, Ref, Ptr> Self;
	ListIterator(pNode node)
		:_node(node)
	{}

	//��ָ�����ͨ������������ʵ��
	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &(_node->_data);
	}

	Self& operator++()//ǰ��++
	{
		_node = _node->_pNext;
		return *this;
	}
	Self operator++(int)
	{
		Self temp(*this);
		_node = _node->_pNext;
		return temp;
	}

	bool operator==(const Self& lst)
	{
		return _node == lst._node;
	}

	bool operator!=(const Self& lst)
	{
		return lst._node != _node;
	}
private:
	pNode _node;
};

//ʵ��const���͵ĵ�����������������·�װ��Ļ���������ֻ�����������ķ���ֵ��ͬ
//�����˴�����������⣬һ�β���ȡ

//template<class T>
//class ConstListIterator
//{
//public:
//	typedef ListNode<T>* pNode;
//	typedef ConstListIterator<T> Self;
//	ConstListIterator(pNode node)
//		:_node(node)
//	{}
//
//	//��ָ�����ͨ������������ʵ��
//	const T& operator*()
//	{
//		return _node->_data;
//	}
//
//	const T* operator->()
//	{
//		return &(_node->_data);
//	}
//
//	Self& operator++()//ǰ��++
//	{
//		_node = _node->_pNext;
//		return *this;
//	}
//	Self operator++(int)
//	{
//		Self temp(*this);
//		_node = _node->_pNext;
//		return temp;
//	}
//
//	bool operator==(const Self& lst)
//	{
//		return _node == lst._node;
//	}
//
//	bool operator!=(const Self& lst)
//	{
//		return lst._node != _node;
//	}
//private:
//	pNode _node;
//};

//list�����Ǵ�ͷ�ڵ��˫��ѭ������
template<class T>
class List
{
public:
	typedef ListNode<T> Node;
	typedef Node* pNode;
	typedef ListIterator<T, T&, T*> iterator;
	typedef ListIterator<T, const T&, const T*> const_iterator;
public:
	List()
	{
		_pHead = new Node();
		_pHead->_pNext = _pHead;
		_pHead->_pPre = _pHead;
		_size = 0;
	}

	~List()
	{
		if (_pHead)
		{
			pNode pCur = _pHead->_pNext;
			pNode next = nullptr;
			while (pCur != _pHead)
			{
				next = pCur->_pNext;
				delete pCur;
				pCur = next;
			}
			delete _pHead;
			_pHead = nullptr;
		}
	}

	//β��
	void PushBack(const T& val)
	{
		pNode pNewNode = new Node(val);
		pNode pCur = _pHead->_pPre;
		pNewNode->_pPre = pCur;
		pNewNode->_pNext = _pHead;
		pCur->_pNext = pNewNode;
		_pHead->_pPre = pNewNode;
		_size++;
	}

	//βɾ
	void PopBack()
	{
		if (_pHead->_pNext != _pHead)
		{
			pNode pCur = _pHead->_pPre;
			pCur->_pPre->_pNext = _pHead;
			_pHead->_pPre = pCur->_pNext;
			delete pCur;
			pCur = nullptr;
			--_size;
		}
	}

	//ͷ��
	void PushFront(const T& val)
	{
		pNode pNewNode = new Node(val);
		pNode pCur = _pHead->_pNext;
		_pHead->_pNext = pNewNode;
		pCur->_pPre = pNewNode;
		pNewNode->_pNext = pCur;
		pNewNode->_pPre = _pHead;
		++_size;
	}
	//ͷɾ
	void PopFront()
	{
		pNode pCur = _pHead->_pNext;
		if (pCur != _pHead)
		{
			_pHead->_pNext = pCur->_pNext;
			pCur->_pNext->_pPre = _pHead;
			--_size;
		}
	}

	//��ͨ�Ĵ�ӡ����
	void PrintList()
	{
		pNode pCur = _pHead->_pNext;
		while (pCur != _pHead)
		{
			cout << pCur->_data << " ";
			pCur = pCur->_pNext;
		}
		cout << endl;
	}

	//begin
	iterator Begin()
	{
		return iterator(_pHead->_pNext);
	}
	//end
	iterator End()
	{
		return iterator(_pHead);
	}

	//cbegin
	const_iterator Begin() const
	{
		return const_iterator(_pHead->_pNext);
	}
	//cend
	const_iterator End() const
	{
		return const_iterator(_pHead);
	}

private:
	pNode _pHead;
	size_t _size;
};