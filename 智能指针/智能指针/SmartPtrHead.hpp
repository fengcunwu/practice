#pragma once 

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
using namespace std;

//�汾һ: //��Դ����Ȩ�Ĺ���---��һ��ָ��ӵ����Դ
template<class T>
class Auto_ptr
{
public:
	//ʵ��RAII
	Auto_ptr(T* ptr = nullptr)
		: _ptr(ptr)
	{}

	~Auto_ptr()
	{
		if (_ptr)
		{
			delete _ptr;
		}
	}
	//ʵ������
	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	//ʵ�ֿ������캯��
	Auto_ptr(Auto_ptr<T>& ap)
		: _ptr(ap._ptr)
	{
		ap._ptr = nullptr;
	}

	//ʵ�ָ�ֵ����������� sp1 = sp2 = sp3
	Auto_ptr<T> operator=(Auto_ptr<T>& ap)
	{
		if (this != ap)
		{
			if (_ptr)
				delete _ptr;
			_ptr = ap->_ptr;

			ap->_ptr = nullptr;
		}
	}
private:
	T* _ptr;
};

//�汾��: ת�Ƶ����ͷŸ���Դ��Ȩ��----�����м���һ��owner��ʾ˭ӵ���ͷŸ���Դ��Ȩ��
template<class T>
class Auto_Ptr_2
{
public:
	Auto_Ptr_2(T* ptr = nullptr)
		: _ptr(ptr)
		, _owner(false)
	{
		if (_ptr)
			_owner = true;
	}

	~Auto_Ptr_2()
	{
		Release();
	}

	//ʵ������
	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	Auto_Ptr_2(const Auto_Ptr_2<T>& ap)
		: _ptr(ap._ptr)
		, _owner(ap._owner)
	{
		ap._owner = false;
	}

	Auto_Ptr_2<T>& operator=(const Auto_Ptr_2<T>& ap)
	{
		if (this != ap)
		{
			Release();//���Լ�����ԭ�е����ݽ�����ȷ���ͷ�
			_ptr = ap->_ptr;
			_owner = ap->_owner;
			ap->_owner = false;
		}
		return *this;
	}

private:
	void Release()
	{
		if (_ptr && _owner)
		{
			delete _ptr;
			_ptr = nullptr;
			_owner = false;
		}
	}
private:
	T* _ptr;
	mutable bool _owner;
};


template<class T>
class UniquePtr
{
public:
	UniquePtr(T* ptr = nullptr)
		: _ptr(ptr)
	{}

	~UniquePtr()
	{
		if (_ptr)
		{
			delete _ptr;
			_ptr = nullptr;
		}
	}

	T* operator->()
	{
		return _ptr;
	}

	T& operator*()
	{
		return *_ptr;
	}

	//��֤��һ����Դ�Ķ�ռʽ���ʣ�Ӧ�ðѿ������캯���͸�ֵ��������غ���˽�л�������ͨ����ֵ�Ϳ���������ʽ��
	//��������
private:
	////c++98:
	//UniquePtr(const UniquePtr<T>&);//ע��������ʱ�����ֻ������
	//UniquePtr<T>& operator=(const UniquePtr<T>&);
	//c++11
	UniquePtr(const UniquePtr<T>&) = delete;
	UniquePtr<T>& operator=(const UniquePtr<T>&) = delete;
protected:
	T* _ptr;
};

#include <mutex>

//��Բ�ͬ����Դ��Ӧ���ò�ͬ�ķ�ʽ�����ͷ�
template<class T>
class DFDef
{
public:
	void operator()(T* & p)
	{
		if (p)
		{
			delete p;
			p = nullptr;
		}	
	}
};

template<class T>
class Free
{
public:
	void operator()(T* & p)
	{
		if (p)
		{
			free(p);
			p = nullptr;
		}
	}
};

class FClose
{
public:
	void operator()(FILE* & p)
	{
		if (p)
		{
			fclose(p);
			p = nullptr;
		}
	}
};

template <class T, class DF = DFDef<T>>
class Shared_Ptr
{
public:
	Shared_Ptr(T* ptr = nullptr)
		: _ptr(ptr)
		, pCount(nullptr)
	{
		if (_ptr)
		{
			pCount = new int(1);
			pm = new mutex;
		}
	}

	~Shared_Ptr()
	{
		Release();
	}

	T* operator->()
	{
		return _ptr;
	}

	T& operator*()
	{
		return *_ptr;
	}

	//�������캯��
	Shared_Ptr(const Shared_Ptr<T>& sp)
		: _ptr(sp._ptr)
		, pCount(sp.pCount)
		, pm(sp.pm)
	{
		if (_ptr)//sp��������ܱ�֤һ��������Դ��
			AddCount();
	}

	//��ֵ���������
	Shared_Ptr<T>& operator=(const Shared_Ptr<T>& sp)
	{
		//�漰�������⣬��ǰ�������������Դ����һ���������----�п���Ҫ�ͷŸ���Դ
		//����Ķ������������Դ����һ���������----�п��ܳ�ʼΪ0
		if (this != sp._ptr)
		{
			Release();//��ǰ�������û�й�����Դ��
			_ptr = sp->_ptr;
			pCount = sp->pCount;
			if (_ptr)//����Ķ������û�й�����Դ��
				AddCount();
		}
		return *this;
	}

	int getUseCount()
	{
		assert(_ptr);
		return *pCount;
	}
private:
	void Release()
	{
		//��Ӧ��������ԴӦ���ö�Ӧ���ͷŷ�ʽ���ͷţ�
		if (_ptr && SubCount() == 0)//��ǰ�������û�й�����Դ��
		{
			DF()(_ptr);
			delete pCount;
			delete pm;
		}
	}

	//�ӼӼ�����ԭ�Ӳ���
	void AddCount()
	{
		pm->lock();
		++(*pCount);
		pm->unlock();
	}

	int SubCount()
	{
		pm->lock();
		--(*pCount);
		pm->unlock();

		return *pCount;
	}

private:
	T* _ptr;
	int *pCount;
	mutex* pm;
};

#include <memory>

//�ÿ��е�shared_ptr����ʾshared_ptr���ڵ�ѭ�����õ�����
struct ListNode
{
	ListNode(int data = 0)
		: _data(data)
	{
		cout << "ListNode(): " << this << endl;
	}

	~ListNode()
	{
		cout << "~ListNode(): " << this << endl;
	}

	weak_ptr<ListNode> _pPre;
	weak_ptr<ListNode> _pNext;

	/*shared_ptr<ListNode> _pPre;
	shared_ptr<ListNode> _pNext;*/
	int _data;
};

void test_shared_ptr()
{
	shared_ptr<ListNode> sp1(new ListNode(10));
	shared_ptr<ListNode> sp2(new ListNode(20));

	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl; 

	sp1->_pNext = sp2;
	sp2->_pPre = sp1;

	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;
	//���н���� : ˵��û����������������ô�ʹ����ڴ�
	//ListNode() : 00F25530
	//ListNode() : 00F2BDB0
	//	1
	//	1
	//	2
	//	2

	//���ڵ��е�shared_ptr��Ϊweak_ptr�Ϳ��Խ��������
	//���н����
	//ListNode() : 00B8A288
    //ListNode() : 00B8BDB0
	//	1
	//	1
	//	1
	//	1
	//	~ListNode() : 00B8BDB0
	//	~ListNode() : 00B8A288
}