#pragma once
#include <iostream>
using namespace std;

// version 1.0
//�����棨Lazy Singleton��������ʵ���ڵ�һ�α�ʹ��ʱ�Ž��г�ʼ����������ӳٳ�ʼ����
//���⣺���ɵ�instanceû���ͷţ���֧�ֶ��߳�
class Singleton
{
private:
	static Singleton* instance;
private:
	Singleton() {};
	~Singleton() {};
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
public:
	static Singleton* getInstance()
	{
		if (instance == NULL)
			instance = new Singleton();
		return instance;
	}
};

// init static member
Singleton* Singleton::instance = NULL;