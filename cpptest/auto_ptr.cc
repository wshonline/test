#include <memory>
#include <string>
#include <iostream>
#include <vector>

int main() {
  std::auto_ptr<std::string> aptr1;
  {
    std::auto_ptr<std::string> aptr(new std::string("hello"));
    aptr1 = aptr;
    if (!aptr.get()) { std::cout << "aptr is null" << std::endl; }
    if (aptr1.get()) { std::cout << "aptr1 is not null" << std::endl; }
  }
  // auto_ptr的复制操作，aptr自身置为null，但并没有释放所管理的对象
  if (aptr1.get()) { std::cout << "aptr1 is not null，the obj's content: " << *aptr1 << std::endl; }
  
  return 0;
}