// 华为二面

#include <bits/stdc++.h>

std::vector<std::vector<int>> vec;

int main() {
  int N, M, Q;
  std::cin >> N >> M >> Q;
  vec.resize(Q, std::vector<int>(3));
  for (int i = 0; i < Q; i++) {
    std::cin >> vec[i][1] >> vec[i][0] >> vec[i][2];
  }
  std::sort(vec.begin(), vec.end(), [](std::vector<int> &a, std::vector<int> &b){ 
    if ((a[0] < b[0]) || ((a[0] == b[0]) && (a[1] < b[1]))) {
      return true;
    } else {
      return false;
    }
  });
  for (auto &nums : vec) {
    for (auto num : nums) {
      std::cout << num << " ";
    }
    std::cout << std::endl;
  }
}