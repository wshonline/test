
// 死循环
// 传入形参m，拷贝了新的m，而it指向的是原m的地址

#include <map>
#include <iostream>

void test(std::map<int, int> mp, std::map<int, int>::iterator it) {
  while (it != mp.end()) {
    std::cout << it->first << std::endl;
    it++;
  }
}

int main() {
  std::map<int, int> mp;
  mp[0] = 1;
  mp[1] = 2;
  auto it = mp.begin();
  test(mp, it);
  return 0;
}
