#include <bits/stdc++.h>
using namespace std;

class Task {
public:
  void process() {};
};

class ThreadPool
{
public:
	ThreadPool(int thread_num) : stop_state(false) {
    for (int i = 0; i < thread_num; i++) {
		  thread t(&ThreadPool::dotask, this);
		  threads.push_back(&t);
		  // t.detach();
	  }
  }
	~ThreadPool() {
    stop();
  }

  void stop() {
    //
    stop_state = true;
    cond.notify_all();
    //
    while (!threads.empty()) {
      thread *t = threads.back();
      threads.pop_back();
      if (t->joinable()) {
        t->join();
      }
    }
  }

	void PostTask(Task *task) {
		lock_guard<mutex> lk(mtx);
		task_queue.push(task);
	  cond.notify_one();
  }

private:
  void dotask() {
    while (1) {
      unique_lock<mutex> lk(mtx);
      cond.wait(lk, [&](){ return !task_queue.empty() || stop_state; });
      if (stop_state) break;  // 也不消费队列里的任务了
      // if (stop_state && task_queue.empty()) break;  // 消费队列完里的任务再退出
      Task *task = task_queue.front();
      task_queue.pop();
      lk.unlock();
      task->process();
    }
  }

	list<thread*> threads;
	queue<Task*> task_queue;
	mutex mtx;
	condition_variable cond;
  atomic<bool> stop_state;
};

int main() {
  return 0;
}
