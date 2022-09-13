// 两数之和的最接近值

#include <bits/stdc++.h>

using namespace std;

vector<int> func(vector<int> &input, int target) {
  if (input.size() < 2) return {};
  int l = 0, r = input.size() - 1;
  int result_l = 0, result_r = 0;
  int gap = INT32_MAX;
  while (l < r) {
    int cur_sum = input[l] + input[r];
    int cur_gap = abs(cur_sum - target);
    if (cur_gap < gap) {
      result_l = l;
      result_r = r;
      gap = cur_gap;
    }
    if (cur_sum < target) {
      l++;
    } else if (cur_sum > target) {
      r--;
    } else {
      break;
    }
  }
  return {input[result_l], input[result_r]};
}

int main() {
  vector<int> input{1, 3, 6, 8, 10, 12, 15, 20};
  int target = 31;
  vector<int> result = func(input, target);
  if (result.size() == 2) {
    cout << result[0] << " " << result[1] << endl;
  }
  return 0;
}