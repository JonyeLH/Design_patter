//饿汉模式：只在第一次被使用时才进行初始化，这叫做延迟初始化。
//v1.1 存在内存泄漏（生成的m_instance未释放）
//不适用于多线程

#include <iostream>
#include <pthread.h>
using namespace std;

class Singleton{
private:
    static Singleton* m_instance;
private:
    Singleton(){};
    ~Singleton(){};
    Singleton(const Singleton&);
    Singleton& operator = (const Singleton&);

public:
    static Singleton* getinstance(){
        if(m_instance == nullptr){
            m_instance = new Singleton();
        }
        return m_instance;
    }
};

Singleton* Singleton::m_instance = nullptr;