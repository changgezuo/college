#include<iostream>
#include<memory>
#include<mutex>
using namespace std;
class Singleton{
public:
    typedef shared_ptr<Singleton>Ptr;
	~Singleton(){
		cout<<"destructor called!"<<endl;
	}
	Singleton(Singleton&) = delete;
	Singleton& operator = (const Singleton &) = delete;
	static Ptr get_instance(){
		if(m_instance == nullptr){
			lock_guard<mutex>lock(m_mutex);
			if(m_instance == nullptr){
				m_instance = shared_ptr<Singleton>(new Singleton);
			}
		}
		return m_instance;
	}
	
private:
     Singleton(){
		 cout<<"constructor called"<<endl;
	 }
    static Ptr m_instance;
    static mutex m_mutex;
};
Singleton::Ptr Singleton::m_instance = nullptr;
mutex Singleton::m_mutex;
int main(){
    Singleton::Ptr instance = Singleton::get_instance();
    Singleton::Ptr instance2 = Singleton::get_instance();
    return 0;
}
