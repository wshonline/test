// 能不能以顺子的形式打完手里的牌（3张及以上表示一个顺子）

#include <bits/stdc++.h>
using namespace std;

bool backTracking(vector<int> &nums, vector<int> &used, int used_num) {
  // printf("%d\n", used_num);
  // for (int i = 0; i < used.size(); i++) {
  //   printf("%d ", used[i]);
  // }
  // printf("\n");
  if (used_num == nums.size())
    return true;
  if (nums.size() - used_num < 3)
    return false;
  int start_pos = 0;
  while (start_pos < nums.size() - 2) {
    if (used[start_pos]) {
      start_pos++;
      continue;
    }
    auto tmp = used;
    int last_num = nums[start_pos];
    int len = 1;
    tmp[start_pos] = 1;
    for (int i = start_pos + 1; i < nums.size(); i++) {
      if (used[i])
        continue;
      if (nums[i] == last_num + 1) {
        last_num++;
        len++;
        tmp[i] = 1;
      } else if (nums[i] > last_num + 1) {
        break;
      }
      if (len >= 3) {
        if (backTracking(nums, tmp, used_num + len))
          return true;
      }
    }
    start_pos++;
  }
  return false;
}
int main() {
  vector<int> nums = {3, 4, 5, 6, 7};
  sort(nums.begin(), nums.end());
  vector<int> used(nums.size(), 0);
  cout << backTracking(nums, used, 0) << endl;
  return 0;
}