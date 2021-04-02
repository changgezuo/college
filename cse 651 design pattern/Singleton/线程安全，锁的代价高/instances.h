#include<iostream>
using namespace std;


class csingleton
{
   public:
   static:
   static csingleton *getinstance(){
	   if( m_pinstance == nullptr) m_pinstance = new csingleton();
	   return m_pinstance;
   }
   private:
   csingleton(){};
   static csingleton *m_pinstance;
};
//如果同时有两个线程请求生成实例，导致会出现生成两个实例，内存泄漏，多线程不安全
