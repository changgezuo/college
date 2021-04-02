#include<iostream>
using namespace std;


class Singleton{
public:
    static Singleton* getInstance(){
        // 先检查对象是否存在
        if (m_instance == nullptr) {
            m_instance = new Singleton();
        }
        return m_instance;
    }
private:
    Singleton(); //私有构造函数，不允许使用者自己生成对象
    Singleton(const Singleton& other);
    static Singleton* m_instance; //静态成员变量 
};

Singleton* Singleton::m_instance=nullptr; //静态成员需要先初始化






//如果同时有两个线程请求生成实例，导致会出现生成两个实例，内存泄漏，多线程不安全
