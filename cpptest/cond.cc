#include <mutex>
#include <condition_variable>
#include <thread>

// global shared data
std::mutex m;                   // #include <mutex>
std::condition_variable cv;     // #include <condition_variable>
bool flag = false;

int thread2(int* value) {
    std::lock_guard<std::mutex> lk(m);
    // do some evaluations
    *value = 1;  // 生产
    flag = true;
    cv.notify_one();
    return 0;
}

int thread1() {
    flag = false;
    int* value = new int(/* parameters */);
    std::thread t2(thread2, value);
    std::unique_lock<std::mutex> lk(m);
    cv.wait(lk, [](){ return flag; });
    int use_data = *value;  // 消费
    lk.unlock();
    t2.join();
    if (nullptr != value) { delete value; }
    return 0;
}



int main() {
  thread1();
  return 0;
}