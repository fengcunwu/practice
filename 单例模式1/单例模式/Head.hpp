#pragma once 

#include <iostream>
#include <stdlib.h>
#include <mutex>
#include <windows.h>
using namespace std;
//template<class T>
//����
class Singleton
{
private:
	Singleton(){}
	//���캯��˽�л�
	Singleton(const Singleton&);
	const Singleton& operator=(const Singleton&);
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
	CSingleton(){}
	CSingleton(const CSingleton&);
	const CSingleton& operator=(const CSingleton&);
private:
	static CSingleton* Instance;
	static mutex lock;
public:
	////����һ˫���жϼ��쳣����
	//static CSingleton* GetInstance()
	//{
	//	if (Instance == nullptr)
	//	{
	//		lock.lock();//Ϊʲô��˫���ж��أ������ж���߳�ͬʱ���е���һ������һ���̻߳����������Դ
	//					//�ٴν����жϣ�Ȼ��ʵ��������
	//					//���û���ٴ��жϣ����е���һ���Ķ���߳̾ͻ�ʵ�������������ԭ�����
	//		if (Instance == nullptr)
	//		{
	//			try{
	//				Instance = new CSingleton();
	//				if (Instance == nullptr)
	//					throw "intance fail";
	//			}
	//			catch (...)
	//			{
	//				lock.unlock();
	//				std::cout << "new fail" << std::endl;
	//				return nullptr;
	//			}
	//		}
	//		lock.unlock();
	//	}
	//	return Instance;
	//}

	////��ʽ������Χ�������new�����쳣���ᵼ������
	//static CSingleton* GetInstance()
	//{
	//	if (Instance == nullptr)
	//	{
	//		lock_guard<mutex> lc(lock);
	//		Instance = new CSingleton();//�ڷ�Χ�����ﲻ���쳣������Ϊ���ᵼ������
	//	}
	//	return Instance;
	//}

	//���������ڴ�դ��
	static CSingleton* GetInstance()
	{
		if (Instance == nullptr)
		{
			CSingleton* temp = new CSingleton();
			::MemoryBarrier();//�ڴ�դ����new��Ϊ������1�����ٿռ䣬2�����ù��캯����3����ֵ��instance
			//������Щ������������Ż����ȸ�ֵ���ڵ��ù��캯�������ܻ������Ȼ�����MemoryBarrier();
			//���ʧ���˺�instanceҲû�й�ϵ��
			Instance = temp;
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