#pragma once
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

//v1.4
//饿汉版，使用atomic保持线程上下文切换顺序
//问题：
class Singleton
{
private:
	static Singleton* instance;
	static mutex my_mutex;
	static std::atomic<Singleton*> sin;	// Singleton::sin
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
	static Singleton* getInstance()
	{
		Singleton* tmp = sin.load(std::memory_order_relaxed);
		std::atomic_thread_fence(std::memory_order_acquire);
		if (tmp == nullptr)
		{
			std::lock_guard<std::mutex> lock(my_mutex);
			tmp = sin.load(std::memory_order_relaxed);
			if (tmp == nullptr)
			{
				tmp = new Singleton();
				std::atomic_thread_fence(std::memory_order_release);
				sin.store(tmp, std::memory_order_relaxed);
			}
		}
		return tmp;
	}

};

// init static member
Singleton* Singleton::instance = NULL;
Singleton::Deletor Singleton::deletor;