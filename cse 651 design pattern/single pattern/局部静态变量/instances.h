class Singleton{
public:
    // 注意返回的是引用。
    static Singleton& getInstance(){
        static Singleton m_instance;  //局部静态变量
        return m_instance;
    }
private:
    Singleton(); //私有构造函数，不允许使用者自己生成对象
    Singleton(const Singleton& other);
};
class Singleton{
public:
    static Singleton& getInstance(){
	    static Singleton m_instance;
	    return m_instance;	
    }	
private:
    Singleton();
    Singleton(const Singleton& other);		
}