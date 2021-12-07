#pragma once
#include <iostream>
using namespace std;

// version 1.2
//�����棬����Ƕ����Deletor��ʵ���ͷ�instance
//���⣺��֧�ֶ��߳�
class Singleton
{
private:
	static Singleton* instance;
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
		if (instance == NULL) {
			instance = new Singleton();
		}
		return instance;
	}
};

// init static member
Singleton* Singleton::instance = NULL;
Singleton::Deletor Singleton::deletor;