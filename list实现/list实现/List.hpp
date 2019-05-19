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

	ListNode(const ListNode<T>& ln)
		:_data(ln->_data)
		, _pNext(ln->_pNext)
		, _pPre(ln->_pPre)
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

	Self& operator--()//ǰ��--
	{
		_node = _node->_pPre;
		return *this;
	}
	Self operator--(int)
	{
		Self temp(*this);
		_node = _node->_pPre;
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

//�����������ʵ��
template<class T, class Ref, class Ptr, class Iterator>
class ListReverseIterator
{
public:
	typedef ListReverseIterator<T, Ref, Ptr, Iterator> Self;
	ListReverseIterator(const Self& it)
		: _it(it._it)
	{}

	ListReverseIterator(const Iterator& it)
		: _it(it)
	{}

	Ref operator*()
	{
		Iterator temp = _it;
		return *(--temp);
	}

	Ptr operator->()
	{
		return &operator*();
	}

	Self& operator++()
	{
		--_it;
		return *this;
	}

	Self operator++(int)
	{
		Iterator temp(_it);
		--_it;
		return temp;
	}

	Self& operator--()
	{
		++_it;
		return *this;
	}

	Self operator--(int)
	{
		Iterator temp(_it);
		++_it;
		return temp;
	}

	bool operator==(const Self& it)
	{
		return _it == it._it;
	}

	bool operator!=(const Self& it)
	{
		return _it != it._it;
	}

private:
	Iterator _it;
};

//list�����Ǵ�ͷ�ڵ��˫��ѭ������
template<class T>
class List
{
public:
	typedef ListNode<T> Node;
	typedef Node* pNode;
	typedef ListIterator<T, T&, T*> iterator;
	typedef ListIterator<T, const T&, const T*> const_iterator;
	typedef ListReverseIterator<T, T&, T*, iterator> reverse_iterator;
	typedef ListReverseIterator<T, const T&, const T*, const_iterator> const_reverse_iterator;
public:
	List()
	{
		_pHead = new Node();
		_pHead->_pNext = _pHead;
		_pHead->_pPre = _pHead;
		_size = 0;
	}
	//��Ϊlist��������Դ�������Ҫʵ��������Լ�д�Ŀ���ʵ�ֹ���
	//������ȱ�ݣ�ʱ�临�Ӷ�̫��
	////��Ҫʵ�����
	//List(const List<T>& lt)
	//	: _pHead(new Node)
	//	, _size(lt._size)
	//{
	//	_pHead->_pNext = _pHead;
	//	_pHead->_pPre = _pHead;

	//	pNode pCur = (lt._pHead)->_pNext;
	//	while (pCur != lt._pHead)
	//	{
	//		PushBack(pCur->_data);
	//		pCur = pCur->_pNext;
	//	}
	//}
	//	
	//List<T>& operator=(const List<T>& lt)
	//{
	//	if (_pHead == nullptr)
	//		_pHead = new Node;
	//	Clear();

	//	pNode pCur = (lt._pHead)->_pNext;
	//	while (pCur != lt._pHead)
	//	{
	//		PushBack(pCur->_data);
	//		pCur = pCur->_pNext;
	//	}
	//	_size = lt._size;
	//}

	//�����ǸĽ����ʵ���������ʵ�ָ�ֵ��������غͿ�������

	List(const List<T>& l)
	{
		CreateHead();
		// ��l�е�Ԫ�ع�����ʱ��temp,Ȼ���뵱ǰ���󽻻�
		List<T> temp(l.CBegin(), l.CEnd());
		this->Swap(temp);//����֮����ʱ�����ں�������֮���Զ����٣��ÿռ任ʱ��
	}
	List<T>& operator=(const List<T>& l)
	{
		if (this != &l)
		{
			List<T> temp(l);
			this->Swap(temp);//����֮����ʱ�����ں�������֮���Զ����٣��ÿռ任ʱ��
		}
		return *this;
	}

	List(int n, const T& value = T())
	{
		CreateHead();
		for (int i = 0; i < n; ++i)
			PushBack(value);
	}

	template <class Iterator>
	List(Iterator first, Iterator last)
	{
		CreateHead();
		while (first != last)
		{
			PushBack(*first);
			++first;
		}
	}

	void Swap(List<T>& l)
	{
		swap(_pHead, l._pHead);
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
		++_size;
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

	void Insert(iterator pos, const T& val)
	{
		pNode pNewNode = new Node(val);
		pNode pNext = pos._node;
		pNode pCur = pNext->_pPre;
		pCur->_pNext = pNewNode;
		pNext->_pPre = pNewNode;
		pNewNode->_pNext = pNext;
		pNewNode->_pPre = pCur;
		++_size;
	}

	//sɾ�����µ�����ʧЧ
	iterator Erase(iterator pos)
	{
		//auto it = ++pos;
		if (pos != End())
		{
			pNode pCur = pos._node;
			pNode pNext = pCur->_pNext;
			pNode pPre = pCur->_pPre;

			delete pCur;
			pCur = nullptr;
			--_size();

			pNext->_pPre = pPre;
			pPre->_pNext = pNext;

			//���µ�����
			pos = iterator(pNext);
		}
		return pos;
	}

	void Clear()
	{
		if (_pHead)
		{
			pNode pCur = _pHead->_pNext;
			pNode pNext = nullptr;
			while (pCur != _pHead)
			{
				pNext = pCur->_pNext;
				delete pCur;
				pCur = pNext;
			}

			_pHead->_pNext = _pHead;
			_pHead->_pPre = _pHead;

			_size = 0;
		}
	}

	size_t Size() const
	{
		return _size;
	}
	bool Empty() const
	{
		return _size == 0;
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

	////////////////////////����������//////////////////////////
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
	const_iterator CBegin() const
	{
		return const_iterator(_pHead->_pNext);
	}
	//cend
	const_iterator CEnd() const
	{
		return const_iterator(_pHead);
	}

	//rbegin
	reverse_iterator RBegin()
	{
		return reverse_iterator(End());
	}
	//rend
	reverse_iterator REnd()
	{
		return reverse_iterator(Begin());
	}

	//c_r_begin
	const_reverse_iterator CRBegin() const
	{
		return const_reverse_iterator(CEnd());
	}
	//c_r_end
	const_reverse_iterator CREnd() const
	{
		return const_reverse_iterator(CBegin());
	}

private:
	void CreateHead()
	{
		_pHead = new Node;
		_pHead->_pPre = _pHead;
		_pHead->_pNext = _pHead;
	}

private:
	pNode _pHead;
	size_t _size;
};