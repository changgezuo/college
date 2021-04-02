class Singleton{
public:
    static Singleton* getInstance(){
        // init函数只会执行一次
        pthread_once(&ponce_, &Singleton::init);
        return m_instance;
    }
private:
    Singleton(); //私有构造函数，不允许使用者自己生成对象
    Singleton(const Singleton& other);
    //要写成静态方法的原因：类成员函数隐含传递this指针（第一个参数）
    static void init() {
        m_instance = new Singleton();
      }
    static pthread_once_t ponce_;
    static Singleton* m_instance; //静态成员变量 
};
pthread_once_t Singleton::ponce_ = PTHREAD_ONCE_INIT;
Singleton* Singleton::m_instance=nullptr; //静态成员需要先初始化