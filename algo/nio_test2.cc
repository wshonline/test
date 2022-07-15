#include <vector>
#include <algorithm>

// 2 0 1 2 1 0
// 0 0 1 1 2 2

void func(std::vector<int> &nums) {
  int l = 0, r = nums.size() - 1;
  int cur = 0;
  while (l < r && cur < r) {
    if (nums[cur] == 0) {
      if(cur == l) {
        cur++;
        l++;
        continue;
      }
      std::swap(nums[cur], nums[l++]);
    }
    else if (nums[cur] == 2) {
        // if(cur == r) break;
        std::swap(nums[cur], nums[r--]);
    }
    else cur++;
  }
}

int main() {
  std::vector<int> nums{2, 2, 1, 2, 1, 0, 2};
  func(nums);
  return 0;
}