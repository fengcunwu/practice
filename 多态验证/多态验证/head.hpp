//#pragma once
#ifndef __HEAD_H__
#define __HEAD_H__

#include <iostream>
#include <stdlib.h>

using namespace std;

class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}
	void Func3()
	{
		cout << "Base::Func3()" << endl;
	}
private:
	int _b = 1;
};
class Derive : public Base
{
public:
	virtual void Func1()
	{
		cout << "Derive::Func1()" << endl;
	}
	
	virtual void Func4()
	{
		cout << "Derive::Func4()" << endl;
	}
private:
	int _d = 2;
};

#endif //__HEAD_H__