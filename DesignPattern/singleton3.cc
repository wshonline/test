// DCL

#include <mutex>
#include <atomic>
#include <iostream>

template<typename T>
class Singleton
{
public:
    static T& getInstance()
    {
        if(!value_)
        {
            std::lock_guard<std::mutex> guard(mutex_);
            if (!value_)
            {
                T* tmp = new T();
                value_ = tmp;  // 低效
            }
        }
        return *value_;
    }
 
private:
    Singleton();
    ~Singleton();
 
    static std::atomic<T*> value_;
    static std::mutex mutex_;
};
 
template<typename T>
std::atomic<T*> Singleton<T>::value_{nullptr};
 
template<typename T>
std::mutex Singleton<T>::mutex_;

class A {
public:
  void print() { std::cout << "hello" << std::endl; }
};

int main() {
  Singleton<A>::getInstance().print();
  return 0;
}