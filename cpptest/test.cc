#include <iostream>
class A {
public:
  virtual void reset() { std::cout << "123"; }
  void reuse() { reset(); }
};

class B : public A {
public:
  virtual void reset() override { std::cout << "456"; }
};

int main() {
  B b;
  b.reuse();
}
