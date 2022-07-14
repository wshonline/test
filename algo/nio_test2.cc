#include <vector>
#include <algorithm>

// 2 0 1 2 1 0
// 0 0 1 1 2 2

void func(std::vector<int> &nums) {
  int l = 0, r = nums.size() - 1;
  // 第一趟把0都放前面
  while (l < r) {
    while (l < r && nums[l] == 0) l++;
    while (l < r && nums[r] != 0) r--;
    if (l < r) {
      std::swap(nums[l], nums[r]);
    }
  }
  // 跳过前面的0
  l = 0, r = nums.size() - 1;
  while (l < r && nums[l] == 0) l++;
  // 第二趟把2都放后面
  while (l < r) {
    while (l < r && nums[l] == 1) l++;
    while (l < r && nums[r] == 2) r--;
    if (l < r) {
      std::swap(nums[l], nums[r]);
    }
  }
}

int main() {
  std::vector<int> nums{2, 0, 1, 2, 1, 0};
  func(nums);
  return 0;
}