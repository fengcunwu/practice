#pragma once 

#include <iostream>
#include <stdlib.h>
#include <mutex>
using namespace std;
//template<class T>
//饿汉
class Singleton
{
private:
	Singleton()
	{}
	//构造函数私有化
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
			lock.lock();//为什么是双重判断呢？假如有多个线程同时运行到这一步，有一个线程获得了锁的资源
						//再次进行判断，然后实例化对象
						//如果没有再次判断，运行到上一步的多个线程就会实例化多个对象，与原意相悖
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