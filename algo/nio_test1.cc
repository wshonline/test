// 蔚来笔试题：
// 给定一个集合，最初包含两个数，
// 两个人A B按顺序选取两个数取差并取绝对值，
// 如果是新值就加入集合，如果无论如何取不到新值了就输了
#include <iostream>
#include <unordered_set>

int main() {
  int n;
  int x, y;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d%d",&x, &y);
    std::unordered_set<int> pool;
    pool.insert(x);
    pool.insert(y);
    int cnt = 0;
    int data;
    while (1) {
      std::unordered_set<int>::iterator it, inner_it;
      bool has_inserted = false;
      for (it = pool.begin(); it != pool.end(); it++) {
        inner_it = it;
        inner_it++;
        for (; inner_it != pool.end(); inner_it++) {
          data = (*it - *inner_it);
          data = data < 0 ? -data : data;
          if (pool.find(data) == pool.end()) {
              pool.insert(data);
              cnt++;
              has_inserted = true;
              break;
          }
        }
        if (has_inserted) break;
      }
      if (it == pool.end() && inner_it == pool.end())
        break;
    }
    if (cnt % 2 == 1) std::cout << "A" << std::endl;
    else std::cout << "B" << std::endl;
  }
}