#include <chrono>
#include <iostream>

// 测试乘法除法速度
// CPU 流水线导致实测差距不大

int main () {
  std::chrono::system_clock::time_point start, end;

  double A, B;

  start = std::chrono::system_clock::now();
  A = 1, B = 1000000000;
  for (int i = 0; i < 1000 * 1000; i++) {
    A = B * 0.01;
  }
  end = std::chrono::system_clock::now();
  std::cout << "time : " << (double)std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() *
          std::chrono::microseconds::period::num / std::chrono::microseconds::period::den << std::endl;

  start = std::chrono::system_clock::now();
  A = 1, B = 1000000000;
  for (int i = 0; i < 1000 * 1000; i++) {
    A = B / 100;
  }
  end = std::chrono::system_clock::now();
  std::cout << "time : " << (double)std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() *
          std::chrono::microseconds::period::num / std::chrono::microseconds::period::den << std::endl;

  return 0;
}