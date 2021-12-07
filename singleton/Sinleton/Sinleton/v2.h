#pragma once
#include <iostream>
using namespace std;

// version 2 Meyers' Singleton �ֲ���̬�����汾
/*
C++11�涨��local static�ڶ��߳������µĳ�ʼ����Ϊ��Ҫ���������֤���ڲ���̬�������̰߳�ȫ��
ʹ�ú����ڵ� local static ����������ֻ�е���һ�η���getInstance()����ʱ�Ŵ���ʵ��
C++0x֮���ʵ�����̰߳�ȫ�ģ�C++0x֮ǰ���������
*/
class Singleton
{
private:
	Singleton() { };
	~Singleton() { };
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
public:
	static Singleton& getInstance()
	{
		static Singleton instance;	//�ֲ���̬�����汾
		return instance;
	}
};