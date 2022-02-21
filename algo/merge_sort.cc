#include <iostream>
#include <vector>

void merge_sort(std::vector<int> &nums, int l, int r) {
  if (l >= r) return;

  int mid = l + r >> 1;
  merge_sort(nums, l, mid);
  merge_sort(nums, mid + 1, r);

  int i = l, j = mid + 1;
  std::vector<int> tmp;
  while (i <= mid && j <= r) {
    if (nums[i] <= nums[j]) tmp.push_back(nums[i++]);
    else tmp.push_back(nums[j++]);
  }

  while (i <= mid) tmp.push_back(nums[i++]);
  while (j <= r) tmp.push_back(nums[j++]);

  for (i = l, j = 0; i <= r; i++, j++) nums[i] = tmp[j];
}

int main() {
  int arr_size = 5;
  int arr[] = {7, 3, 1, 8, 9};
  std::vector<int> nums;
  for (int i = 0; i < arr_size; i++) {
    nums.push_back(arr[i]);
  }
  merge_sort(nums, 0, arr_size - 1);
  
  for (int i = 0; i < nums.size(); i++) {
    std::cout << nums[i] << " ";
  }
  std::cout << std::endl;
  
  // 测试模板代码里的+和>>优先级
  std::cout << "测试模板代码里的+和>>优先级 : " << (1 + 7 >> 1) << std::endl;
  
  return 0;
}