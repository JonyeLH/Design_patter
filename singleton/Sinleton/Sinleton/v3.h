#pragma once
#include <iostream>
using namespace std;

// version 3 �����棨Eager Singleton����ָ����ʵ���ڳ�������ʱ������ִ�г�ʼ��
/*
������main����֮ǰ��ʼ��������û���̰߳�ȫ�����⡣
���⣺����no-local static���󣨺������static�����ڲ�ͬ���뵥Ԫ�еĳ�ʼ��˳����δ����ġ�
	static Singleton instance;��static Singleton& getInstance()���ߵĳ�ʼ��˳��ȷ����
	����ڳ�ʼ�����֮ǰ���� getInstance() �����᷵��һ��δ�����ʵ��
*/
class Singleton
{
private:
	static Singleton instance;
private:
	Singleton();
	~Singleton();
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
public:
	static Singleton& getInstance() {
		return instance;
	}
};

// initialize defaultly
Singleton Singleton::instance;
