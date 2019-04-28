#pragma once 

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
using namespace std;

//版本一: //资源管理权的管理---哪一个指针拥有资源
template<class T>
class Auto_ptr
{
public:
	//实现RAII
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
	//实现重载
	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	//实现拷贝构造函数
	Auto_ptr(Auto_ptr<T>& ap)
		: _ptr(ap._ptr)
	{
		ap._ptr = nullptr;
	}

	//实现赋值运算符的重载 sp1 = sp2 = sp3
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

//版本二: 转移的是释放该资源的权利----在类中加了一个owner表示谁拥有释放该资源的权利
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

	//实现重载
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
			Release();//对自己对象原有的数据进行正确的释放
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

	//保证对一份资源的独占式访问，应该把拷贝构造函数和赋值运算符重载函数私有化，不能通过赋值和拷贝两个方式来
	//创建对象
private:
	////c++98:
	//UniquePtr(const UniquePtr<T>&);//注意声明的时候参数只放类型
	//UniquePtr<T>& operator=(const UniquePtr<T>&);
	//c++11
	UniquePtr(const UniquePtr<T>&) = delete;
	UniquePtr<T>& operator=(const UniquePtr<T>&) = delete;
protected:
	T* _ptr;
};

#include <mutex>

//针对不同的资源，应该用不同的方式进行释放
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

	//拷贝构造函数
	Shared_Ptr(const Shared_Ptr<T>& sp)
		: _ptr(sp._ptr)
		, pCount(sp.pCount)
		, pm(sp.pm)
	{
		if (_ptr)//sp这个对象不能保证一定管理资源了
			AddCount();
	}

	//赋值运算符重载
	Shared_Ptr<T>& operator=(const Shared_Ptr<T>& sp)
	{
		//涉及两个问题，当前对象所管理的资源少了一个对象管理----有可能要释放该资源
		//传入的对象锁管理的资源多了一个对象管理----有可能初始为0
		if (this != sp._ptr)
		{
			Release();//当前对象可能没有管理资源，
			_ptr = sp->_ptr;
			pCount = sp->pCount;
			if (_ptr)//传入的对象可能没有管理资源，
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
		//对应的类型资源应该用对应的释放方式来释放，
		if (_ptr && SubCount() == 0)//当前对象可能没有管理资源，
		{
			DF()(_ptr);
			delete pCount;
			delete pm;
		}
	}

	//加加计数的原子操作
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

//用库中的shared_ptr来演示shared_ptr存在的循环引用的问题
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
	//运行结果是 : 说明没调用析构函数，那么就存在内存
	//ListNode() : 00F25530
	//ListNode() : 00F2BDB0
	//	1
	//	1
	//	2
	//	2

	//将节点中的shared_ptr换为weak_ptr就可以解决该问题
	//运行结果：
	//ListNode() : 00B8A288
    //ListNode() : 00B8BDB0
	//	1
	//	1
	//	1
	//	1
	//	~ListNode() : 00B8BDB0
	//	~ListNode() : 00B8A288
}