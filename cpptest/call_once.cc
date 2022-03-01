#include <stdio.h>
#include <stdlib.h>

#include <iostream> // std::cout
#include <thread>   // std::thread
#include <mutex>    // std::mutex

int a = 0;
std::once_flag g_flag;

void thread_task1()
{
    ++a;
}

void thread_task2()
{
    std::call_once(g_flag, thread_task1);
}

int main()
{
    std::thread t1(thread_task2);
    std::thread t2(thread_task2);
    t1.join();
    t2.join();
    std::cout << a << std::endl;
    return 0;
}