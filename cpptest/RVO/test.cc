#include <iostream>

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

  ~A() { std::cout << "析构函数" << std::endl; }

};

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

int main() {
  A a2 = func();
  // std::cout << std::endl;

  // A a3;
  // A a4 = func1(a3);
  // std::cout << std::endl;

  // A a5;
  // A a6 = func2(a5);
  return 0;
}