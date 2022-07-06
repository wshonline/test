#include <vector>
#include <iostream>

std::vector<int> func(std::vector<std::vector<int>> &input) {
  if (input.empty()) return {};
  std::vector<int> ret;
  int up = 0;
  int down = input.size() -1;
  int left = 0;
  int right = input[0].size() -1;

  for (;;) {
    int i = left;
    while (i <= right) {
      ret.push_back(input[up][i]);
      i++;
    }
    
    i = ++up;
    if (up > down) break;
    while (i <= down) {
      ret.push_back(input[i][right]);
      i++;
    }

    i = --right;
    if (left > right) break;
    while (i >= left) {
      ret.push_back(input[down][i]);
      i--;
    }

    i = --down;
    if (up > down) break;
    while (i >= up) {
      ret.push_back(input[i][left]);
      i--;
    }

    ++left;
    if (left > right) break;
  }
  return ret;
}

int main() {
  std::vector<std::vector<int>> input = {{1,2,3,4},{5,6,7,8,},{9,10,11,12}};
    std::vector<int> ret = func(input);
    for (auto n : ret) {
      std::cout << n << " ";
    }
    std::cout << std::endl;
    return 0;
}