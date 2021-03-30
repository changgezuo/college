//双检查锁，但由于内存读写reorder不安全
Singleton* Singleton::getInstance() {
    //先判断是不是初始化了，如果初始化过，就再也不会使用锁了
    if(m_instance==nullptr){
        Lock lock; //伪代码
        if (m_instance == nullptr) {
            m_instance = new Singleton();
        }
    }
    return m_instance;
}