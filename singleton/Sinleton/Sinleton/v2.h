#pragma once
#include <iostream>
using namespace std;

// version 2 Meyers' Singleton 局部静态变量版本
/*
C++11规定了local static在多线程条件下的初始化行为，要求编译器保证了内部静态变量的线程安全性
使用函数内的 local static 对象。这样，只有当第一次访问getInstance()方法时才创建实例
C++0x之后该实现是线程安全的，C++0x之前仍需加锁。
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
		static Singleton instance;	//局部静态变量版本
		return instance;
	}
};