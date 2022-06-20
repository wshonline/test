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

class A {
 public:
  // 默认构造函数
  A() {
    std::cout << "constructor" << std::endl;
  }
  
  // 拷贝构造、拷贝赋值
  A(const A& a) {
    std::cout << "copy constructor" << std::endl;
  }
  A& operator=(const A& a) {
    std::cout << "copy assignment" << std::endl;
    return *this;
  }

  // 移动构造、移动赋值
  A(const A&& a) {
    std::cout << "move constructor" << std::endl;
  }
  A& operator=(const A&& a) {
    std::cout << "move assignment" << std::endl;
    return *this;
  }

  A func() {
    A a;
    return a;
  }

  A func1(A a) {
    return a;
  }

  A func2(A& a) {
    return a;
  }

};

int main() {
  // Slice s;
  // Slice *s1 = new Slice;
  // Slice *s2 = new Slice();

  A a1;
  A a2 = a1.func();
  std::cout << std::endl;

  A a3;
  A a4 = a3.func1(a3);
  std::cout << std::endl;

  A a5;
  A a6 = a5.func2(a5);
  return 0;
}