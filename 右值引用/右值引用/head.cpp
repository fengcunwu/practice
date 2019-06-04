//#pragma once

#include <iostream>
#include <vector>

using namespace std;

int a_conststructcount = 0;
int a_copyconststructcount = 0;
int a_destroycount = 0;

//测试右值引用的第一个特性，延长将亡值的生命周期，
//需要设置编译器优化
struct A
{
	A()
	{
		cout << "A(): " << ++a_conststructcount << endl;
	}

	A(const A&)
	{
		cout << "copy: " << ++a_copyconststructcount << endl;
	}

	~A()
	{
		cout << "destroy: " << ++a_destroycount << endl;
	}
};

A GetA()
{
	return A();
}

//测试右值引用实现的移动语义
class Test
{
public:
	Test(int* _ptr = nullptr)
		: ptr(_ptr)
	{
		cout << "Test()" << endl;
	}

	Test(const Test& ts)
		: ptr(new int(*(ts.ptr)))
	{
		cout << "copy Test" << endl;
	}

	Test(Test&& a) :ptr(a.ptr)
	{
		a.ptr = nullptr;
		cout << "move Test" << endl;
	}
private:
	int* ptr;
};

Test GetTest()
{
	return Test();
}

int main()
{
	Test t = GetTest();
	//如果没有提供移动构造函数，会发生不必要的深拷贝，但是如果提供了移动构造函数，只会发生两次移动构造
	//不会发生不必要的拷贝构造，
	char p = '2';
	cout << (int)&p << endl;
	p = move(p);
	cout << (int)&p << endl;
	p = '3';
	//cout << (int)&p1 << endl;

	system("pause");
	return 0;
}

