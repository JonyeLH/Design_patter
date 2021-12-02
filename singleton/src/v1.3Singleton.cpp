#include <iostream>
#include <pthread.h>
#include <thread>
#include <mutex>

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
static Singleton* getInstance() {
	if(m_instance == NULL) {
		Lock lock;  // 基于作用域的加锁，超出作用域，自动调用析构函数解锁
        if(m_instance == NULL) {
        	m_instance = new Singleton();
        }
	}
	return m_instance;
}
};