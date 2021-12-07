#pragma once
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

//v1.4
//饿汉版，添加双检锁，支持多线程
//问题：线程上下文切换可能出现instance多次判空，导致多次生成
class Singleton
{
private:
	static Singleton* instance;
	static mutex my_mutex;
private:
	Singleton() { };
	~Singleton() { };
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
private:
	class Deletor {
	public:
		~Deletor() {
			if (Singleton::instance != NULL)
				delete Singleton::instance;
		}
	};
	static Deletor deletor;

public:
	static Singleton* getInstance() {
		//lock_guard<mutex> myguard(my_mutex, std::adopt_lock);
		if (instance == NULL) {
			my_mutex.lock();		//双检锁
			if (instance == NULL) {
				instance = new Singleton();

			}
			my_mutex.unlock();
		}
		return instance;
	}
};

// init static member
Singleton* Singleton::instance = NULL;
Singleton::Deletor Singleton::deletor;