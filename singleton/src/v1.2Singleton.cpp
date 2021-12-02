//饿汉模式：只在第一次被使用时才进行初始化，这叫做延迟初始化。
//v1.2 使用嵌套类Deletor，解决生成的m_instance未释放，导致的内存泄漏
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

private:
	class Deletor {
	public:
		~Deletor() {
			if(Singleton::m_instance != NULL)
				delete Singleton::m_instance;
		}
	};
	static Deletor deletor;

public:
    static Singleton* getinstance(){
        if(m_instance == nullptr){
            m_instance = new Singleton();
        }
        return m_instance;
    }
};


Singleton::Deletor Singleton::deletor;
Singleton* Singleton::m_instance = nullptr;