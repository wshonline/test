#include <iostream>

class A {
  public:
    A() { std::cout << "父类 构造" << std::endl; }
    virtual ~A() { std::cout << "父类 析构" << std::endl; }
    void print() { std::cout << "***" << std::endl; }
};

class B : public A{
  public:
    B() { std::cout << "子类 构造" << std::endl; }
    ~B() { std::cout << "子类 析构" << std::endl; }
    virtual void print() { std::cout << "$$$" << std::endl; }
};

class C : public B{
  public:
    C() { std::cout << "子类2 构造" << std::endl; }
    ~C() { std::cout << "子类2 析构" << std::endl; }
    void print() { std::cout << "!!!" << std::endl; }
};

int main() {
  C c;
  B &b = c;
  b.print();
  return 0;
}