#include <iostream>

class A {
public:
  void init() {
    std::cout << "base init" << std::endl;
  }

  virtual void init_vir() {
    std::cout << "base init on virtual" << std::endl;
  }
};

class B : public A {
public:
  void init() {
    std::cout << "derived init" << std::endl;
  }

  virtual void init_vir() {
    std::cout << "derived init on virtual" << std::endl;
  }
};

int main() {
  A *b = new B;
  b->init();
  b->init_vir();

  return 0;
}