#include <stdlib.h>
#include <iostream>

int main() {
  uint64_t file_number = 66;
  char buf[sizeof(file_number)];
  std::cout << sizeof(buf) << std::endl;  // sizeof的结果是buf的大小
  return 0;
}