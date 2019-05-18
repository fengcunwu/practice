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
//通过增加参数列表，让编译器来区分是const的迭代器还是普通类型的迭代器
template<class T, class Ref, class Ptr>
class ListIterator
{
public:
	typedef ListNode<T>* pNode;
	typedef ListIterator<T, Ref, Ptr> Self;
	ListIterator(pNode node)
		:_node(node)
	{}

	//对指针的普通操作进行重载实现
	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &(_node->_data);
	}

	Self& operator++()//前置++
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

//实现const类型的迭代器，但是如果重新封装类的话，两个类只有两个参数的返回值不同
//出现了代码冗余的问题，一次不可取

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
//	//对指针的普通操作进行重载实现
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
//	Self& operator++()//前置++
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

//list本质是带头节点的双向循环链表
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

	//尾插
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

	//尾删
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

	//头插
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
	//头删
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

	//普通的打印函数
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