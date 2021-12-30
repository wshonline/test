#include <iostream>

class Slice {
 public:
  Slice() : data_(""), size_(0) {
    std::cout << "构造" << std::endl;
  }
  // Slice(int num) : data_(""), size_(0) {
  //   std::cout << "其他构造" << std::endl;
  // }

 private:
  const char* data_;
  size_t size_;
};

int main() {
  Slice s;
  Slice *s1 = new Slice;
  Slice *s2 = new Slice();
  return 0;
}