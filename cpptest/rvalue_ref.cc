#include <utility>
#include <iostream>

int main() {
  int temp = 5;
  int &&ref_a = std::move(temp);
  ref_a = 6;

  std::cout << temp << std::endl;
  std::cout << ref_a << std::endl;
  return 0;
}