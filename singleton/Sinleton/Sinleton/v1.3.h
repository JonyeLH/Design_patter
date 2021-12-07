#pragma once
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

//v1.3
//�����棬��ӵ�������֧�ֶ��߳�
//���⣺��֧�ָ߲�������
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
		my_mutex.lock();		//������
		//std::lock_guard<mutex> myguard(my_mutex, std::adopt_lock);
		if (instance == NULL) {
			instance = new Singleton();
		
		}
		my_mutex.unlock();
		return instance;
	}
};

// init static member
Singleton* Singleton::instance = NULL;
Singleton::Deletor Singleton::deletor;