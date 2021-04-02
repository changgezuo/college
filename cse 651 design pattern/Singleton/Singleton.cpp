class Singleton{
private:
    Singleton();
public:
    static Singleton* getInstance();
    static Singleton* m_instance;
};

Singleton* Singleton::m_instance=nullptr;

//thread unsafe
Singleton* Singleton::getInstance() {
    if (m_instance == nullptr) {
        m_instance = new Singleton();
    }
    return m_instance;
}






//thread safe while the cost of lock is high
Singleton* Singleton::getInstance() {
    Lock lock;
    if (m_instance == nullptr) {
        m_instance = new Singleton();
    }
    return m_instance;
}









//double check lock, while memory reorder leads to problems
Singleton* Singleton::getInstance() {
    
    if(m_instance==nullptr){
        Lock lock;
        if (m_instance == nullptr) {
            m_instance = new Singleton();//constructor
        }
    }
    return m_instance;
}

//the constructor step in the memory works like below
//allocate memory //step1
//init the object // step2
//put the object to the allocated memory //step3
//however, some compiler may exchange the step2 and step3, return uninitialized object

//therefore, we can use 'volatile' to fix it beacuse 'volatile' means the variance might be changed
//by other things, can't be loaded into register
//so , we can use 
volatile static Singleton* m_instance;




//a cross platform implement after C++11 version (volatile)
std::atomic<Singleton*> Singleton::m_instance;
std::mutex Singleton::m_mutex;

Singleton* Singleton::getInstance() {
    Singleton* tmp = m_instance.load(std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire);//acquire memory fence
    if (tmp == nullptr) {
        std::lock_guard<std::mutex> lock(m_mutex);
        tmp = m_instance.load(std::memory_order_relaxed);
        if (tmp == nullptr) {
            tmp = new Singleton;
            std::atomic_thread_fence(std::memory_order_release);//release memory fense
            m_instance.store(tmp, std::memory_order_relaxed);
        }
    }
    return tmp;
}