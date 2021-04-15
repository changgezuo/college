#include<iostream>
#include<memory>
#include<mutex>
using namespace std;
class Singleton{
public:
	~Singleton(){
		cout<<"destructor called!"<<endl;
	}
	Singleton(Singleton&) = delete;
	Singleton& operator = (const Singleton &) = delete;
	static Singleton& get_instance(){
		static Singleton m_instance;
		return m_instance;
	}
	
private:
     Singleton(){
		 cout<<"constructor called"<<endl;
	 }
	 
};


int main(){
    Singleton& instance = Singleton::get_instance();
    Singleton& instance2 = Singleton::get_instance();
    return 0;
}
