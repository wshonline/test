// 华为一面

#include <bits/stdc++.h>

std::vector<std::vector<int>> result;
std::unordered_set<int> mp;
std::vector<int> path;

// 输出 1-n 的全排列
void func(int n, int cnt) {
  if (cnt == n) {
    result.push_back(path);
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (mp.find(i) != mp.end()) continue;
    path.push_back(i);
    mp.insert(i);
    func(n, cnt+1);
    path.pop_back();
    mp.erase(i);
  }
}

int main() {
  int n;
  std::cin >> n;
  func(n, 0);
  for (auto vec : result) {
    for (auto num : vec) {
      std::cout << num << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}