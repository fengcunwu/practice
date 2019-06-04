//#pragma once

#include <iostream>
#include <vector>

using namespace std;

int a_conststructcount = 0;
int a_copyconststructcount = 0;
int a_destroycount = 0;

//������ֵ���õĵ�һ�����ԣ��ӳ�����ֵ���������ڣ�
//��Ҫ���ñ������Ż�
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

//������ֵ����ʵ�ֵ��ƶ�����
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
	//���û���ṩ�ƶ����캯�����ᷢ������Ҫ���������������ṩ���ƶ����캯����ֻ�ᷢ�������ƶ�����
	//���ᷢ������Ҫ�Ŀ������죬
	char p = '2';
	cout << (int)&p << endl;
	p = move(p);
	cout << (int)&p << endl;
	p = '3';
	//cout << (int)&p1 << endl;

	system("pause");
	return 0;
}

