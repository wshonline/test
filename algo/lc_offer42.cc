#include <vector>
#include <iostream>
#include <cstdint>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int ret = INT32_MIN;
    int tmp = 0;
    for (int i = 0; i < nums.size(); i++) {
        tmp += nums[i];
        ret = max(ret, tmp);
        if (tmp < 0) {  // 相当于重置最大子序起始位置，因为遇到负数一定是拉低总和
            tmp = 0;
        }
    }
    return ret;
}

int main() {
  vector<int> vec = {-2,1,-3,4,-1,2,1,-5,4};
  int ret = maxSubArray(vec);
  cout << "ret: " << ret << endl;
  return 0;
}