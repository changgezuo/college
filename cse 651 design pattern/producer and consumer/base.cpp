//producer and consumer                                                                                                                  
#include<iostream>
#include<queue>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

const int  NUM = 8;

class BlockQueue
{
private:
    std::queue<int> q;
    int cap;
    pthread_mutex_t mutex;
    pthread_cond_t full;
    pthread_cond_t empty;

private:
    void LockQueue()  //lock queue
    {
        pthread_mutex_lock(&mutex);
    }
    void UnlockQueue()  //unlock queue
    {
        pthread_mutex_unlock(&mutex);
    }
    void ProductWait()  //queue is full, producer wait 
    {
        pthread_cond_wait(&full, &mutex);
    }
    void ConsumeWait()  //queue is empty, consumer wait
    {
        pthread_cond_wait(&empty, &mutex);
    }
    void NotifyProduct()  //queue is not full, notify profducer
    {
        pthread_cond_signal(&full);
    }
    void NotifyConsume()  //queue is not empty, notify consumer
    {
        pthread_cond_signal(&empty);
    }
    bool IsEmpty()
    {
        return (q.size() == 0 ? true : false);
    }
    bool IsFull()
    {
        return (q.size() == cap ? true : false);
    }
public:
    BlockQueue(int _cap = NUM) :cap(_cap) //constructor
    {
        pthread_mutex_init(&mutex, NULL);
        pthread_cond_init(&full, NULL);
        pthread_cond_init(&empty, NULL);
    }
    void PushData(const int& data)
    {
        LockQueue();
        while (IsFull()) 
        {
            NotifyConsume();
            std::cout << "queue full,notify consume data,product stop!!" << std::endl;
            ProductWait();
        }
        
        q.push(data);
        NotifyConsume();
        UnlockQueue();
    }
    void PopData(int& data)
    {
        LockQueue();
        while (IsEmpty())  
        {
            NotifyProduct();
            std::cout << "queue empty,notify product data,consume stop!!" << std::endl;
            ConsumeWait();
        }
        
        data = q.front();
        q.pop();
        NotifyProduct();
        UnlockQueue();
    }
    ~BlockQueue()
    {
        pthread_mutex_destroy(&mutex);
        pthread_cond_destroy(&full);
        pthread_cond_destroy(&empty);
    }
};


void* consumer(void* arg)
{
    BlockQueue* bqp = (BlockQueue*)arg;
    int data;
    for (;;)
    {
        bqp->PopData(data);
        std::cout << "Consume data done: " << data << std::endl;
    }
}


void* producter(void* arg)
{
    BlockQueue* bqp = (BlockQueue*)arg;
    srand((unsigned long)time(NULL));
    for (;;)
    {
        int data = rand() % 1024;
        bqp->PushData(data);
        std::cout << "Product data done: " << data << std::endl;
        // sleep(1);
    }
}

int main()
{
    BlockQueue bq;
    pthread_t c, p;
	
	pthread_create(&c, NULL, consumer, (void*)&bq);
    pthread_create(&p, NULL, producter, (void*)&bq);

    pthread_join(c, NULL);
    pthread_join(p, NULL);

    return 0;
}
