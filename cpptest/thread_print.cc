#include <thread>
#include <mutex>
#include <iostream>
#include <condition_variable>

std::condition_variable cond1;
std::condition_variable cond2;
std::condition_variable cond3;
std::mutex mtx;
bool flag1 = true;
bool flag2 = false;
bool flag3 = false;

void print1() {
  while(true) {
    std::unique_lock<std::mutex> lk(mtx);
    cond1.wait(lk, [](){ return flag1; });
    std::cout << 1 << std::endl;
    flag1 = false;  // 消费掉
    flag2 = true;  // 生产出
    cond2.notify_one();
  }
}

void print2() {
  while(true) {
    std::unique_lock<std::mutex> lk(mtx);
    cond2.wait(lk, [](){ return flag2; });
    std::cout << 2 << std::endl;
    flag2 = false;  // 消费掉
    flag3 = true;  // 生产出
    cond3.notify_one();
  }    
}

void print3() {
  while(true) {
    std::unique_lock<std::mutex> lk(mtx);
    cond3.wait(lk, [](){ return flag3; });
    std::cout << 3 << std::endl;
    flag3 = false;  // 消费掉
    flag1 = true;  // 生产出
    cond1.notify_one();
  }
}

int main() {
  std::thread thread1(print1);
  std::thread thread2(print2);
  std::thread thread3(print3);
  thread1.join();
  thread2.join();
  thread3.join();
  return 0;
}