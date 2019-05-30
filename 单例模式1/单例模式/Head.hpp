#pragma once 

#include <iostream>
#include <stdlib.h>
#include <mutex>
#include <windows.h>
using namespace std;
//template<class T>
//饿汉
class Singleton
{
private:
	Singleton(){}
	//构造函数私有化
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
//懒汉
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
	////方法一双重判断加异常处理
	//static CSingleton* GetInstance()
	//{
	//	if (Instance == nullptr)
	//	{
	//		lock.lock();//为什么是双重判断呢？假如有多个线程同时运行到这一步，有一个线程获得了锁的资源
	//					//再次进行判断，然后实例化对象
	//					//如果没有再次判断，运行到上一步的多个线程就会实例化多个对象，与原意相悖
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

	////方式二：范围锁，如果new出现异常不会导致死锁
	//static CSingleton* GetInstance()
	//{
	//	if (Instance == nullptr)
	//	{
	//		lock_guard<mutex> lc(lock);
	//		Instance = new CSingleton();//在范围锁这里不用异常处理，以为不会导致死锁
	//	}
	//	return Instance;
	//}

	//方法三：内存栅栏
	static CSingleton* GetInstance()
	{
		if (Instance == nullptr)
		{
			CSingleton* temp = new CSingleton();
			::MemoryBarrier();//内存栅栏，new分为三步，1，开辟空间，2，调用构造函数，3，赋值给instance
			//但是有些编译器会出现优化，先赋值，在调用构造函数，可能会出错误，然后就用MemoryBarrier();
			//如果失败了和instance也没有关系，
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