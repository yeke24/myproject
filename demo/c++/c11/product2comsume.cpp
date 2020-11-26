#include <condition_variable>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>
 
std::vector<int> g_storeHouse;   // 仓库
const int g_storeHouseSize = 5;  // 仓库容量
 
int g_nCount = 0;
const int g_maxCount = 100;
 
std::mutex g_mut;
std::condition_variable g_cond;
 
class Productor {
 public:
  void Product() {
    while (g_nCount < 100) {
      std::unique_lock<std::mutex> lock(g_mut);
      g_cond.wait(lock, [&] { return g_storeHouse.size() < g_storeHouseSize; });
      g_storeHouse.push_back(++g_nCount);
      std::cout << "product  " << g_nCount << std::endl;
      lock.unlock();
      g_cond.notify_one();
    }
  }
};
 
class Consumer {
 public:
  void Consume(int id) {
    while (g_nCount < 100) {
      std::unique_lock<std::mutex> lock(g_mut);
      g_cond.wait(lock, [&] { return !g_storeHouse.empty() || g_nCount >= 100; });
 
      // 消费者的g_nCount计数需要到105，才能完全消费完
      if (g_nCount > g_maxCount + g_storeHouseSize) {
        break;
      } else if (g_nCount > g_maxCount) {
        ++g_nCount;
      }
 
      std::cout << "Consume" << id << " " << g_storeHouse.back() << std::endl;
      g_storeHouse.pop_back();
 
      lock.unlock();
      g_cond.notify_one();
    }
  }
};
 
int main() {
  Productor pd;
  Consumer cm;
 
  std::thread thd1(&Productor::Product, pd);
  std::thread thd2(&Consumer::Consume, cm, 1);
  std::thread thd3(&Consumer::Consume, cm, 2);
  thd1.join();
  thd2.join();
  thd3.join();
 
  return 0;
}

#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
 
int counter=0;
int maxSize = 30;
std::mutex mtx;
std::queue<int> dataQuene; // 被生产者和消费者共享
 
std::condition_variable producer, consumer;  // 条件变量是一种同步机制，要和mutex以及lock一起使用
 
void func_consumer()
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));// 消费者比生产者慢
 
        std::unique_lock<std::mutex> lck(mtx);
        consumer.wait(lck, [] {return dataQuene.size() != 0; });     // 消费者阻塞等待， 直到队列中元素个数大于0
        int num=dataQuene.front();
        dataQuene.pop();
        std::cout << "consumer " << std::this_thread::get_id() << ": "<< num <<std::endl;
 
        producer.notify_all();                                       // 通知生产者当队列中元素个数小于maxSize
    }
}
 
void func_producer()
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(900));  // 生产者稍微比消费者快
        std::unique_lock<std::mutex> lck(mtx);
        producer.wait(lck, [] {return dataQuene.size() != maxSize; });// 生产者阻塞等待， 直到队列中元素个数小于maxSize
 
        ++counter;
        dataQuene.push(counter);
        std::cout << "producer " << std::this_thread::get_id() << ": "<< counter <<std::endl;
 
        consumer.notify_all();                                        //通知消费者当队列中的元素个数大于0
    }
}
 
int main()
{
    std::thread consumers[2], producers[2];
 
    // 两个生产者和消费者
    for (int i = 0; i < 2; ++i)
    {
        consumers[i] = std::thread(func_consumer);
        producers[i] = std::thread(func_producer);
    }
 
    for (int i = 0; i < 2; ++i)
    {
        producers[i].join();
        consumers[i].join();
    }
 
    return 0;
}