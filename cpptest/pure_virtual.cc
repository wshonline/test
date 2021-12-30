#include <iostream>

class Base {
 public:
  // virtual ~Base() = 0;
  virtual void Print() = 0;

};
// Base::~Base() { std::cout << 0 << std::endl; };
void Base::Print() { std::cout << 1 << std::endl;};

class Derived : public Base {
 public:
  virtual void Print() override { Base::Print(); };
};


int main() {
  Derived d;
  d.Print();
  return 0;
}