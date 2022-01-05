#include <iostream>

class Base {
 public:
  virtual void Print1() { std::cout << 1 << std::endl; };
  virtual void Print2() { std::cout << 2 << std::endl; };

};

class Derived : public Base {
 public:
  virtual void Print1() { std::cout << 1.1 << std::endl; };
  void Print2() { std::cout << 2.2 << std::endl; };  // 基类是vir, 子类都是vir的（不论是否有显式地加上vir）
};

class Derived2 : public Derived {
 public:
  void Print2() { std::cout << 2.22 << std::endl; };  // Derived的Print2虽不带vir, 但仍然是vir的，仍然保持多态
};

int main() {
  Base *obj = new Derived2;
  obj->Print1();
  obj->Print2();

  return 0;
}