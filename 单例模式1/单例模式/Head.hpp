#pragma once 

#include <iostream>
#include <stdlib.h>
#include <mutex>
using namespace std;
//template<class T>
//����
class Singleton
{
private:
	Singleton()
	{}
	//���캯��˽�л�
public:
	static Singleton* GetInstance()
	{
		return Instance;
	}
	void p()
	{
		std::cout << "ffff" << std::endl;
	}
private:
	static Singleton* Instance;
};
Singleton* Singleton::Instance = new Singleton();
//����
class CSingleton
{
private:
	CSingleton()
	{}
private:
	static CSingleton* Instance;
	static mutex lock;
public:
	static CSingleton* GetInstance()
	{
		if (Instance == nullptr)
		{
			lock.lock();//Ϊʲô��˫���ж��أ������ж���߳�ͬʱ���е���һ������һ���̻߳����������Դ
						//�ٴν����жϣ�Ȼ��ʵ��������
						//���û���ٴ��жϣ����е���һ���Ķ���߳̾ͻ�ʵ�������������ԭ�����
			if (Instance == nullptr)
			{
				Instance = new CSingleton();
			}
			lock.unlock();
		}
		return Instance;
	}
	void p()
	{
		std::cout << "ffff" << std::endl;
	}
};

CSingleton* CSingleton::Instance;
mutex CSingleton::lock;