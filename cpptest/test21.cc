#include <bits/stdc++.h>

using namespace std;

void dfs(int num, vector<int> &nums) {
  int i = 0;
  for (i = nums.size() - 1; i >= 0; i--) {
    if (nums[i] <= num) break;
  }
  if (i == 0) cout << "2(0)";
  else if (i == 1) cout << "2";
  else if (i == 2) cout << "2(2)";
  else {
    cout << "2(";
    dfs(i, nums);
    cout << ")";
  }
  if (nums[i] < num) {
    cout << "+";
    dfs(num - nums[i], nums);
  }
}

int main() {
  vector<int> nums(15);
  nums[0] = 1;
  for (int i = 1; i < 15; ++i) {
      nums[i] = 2 * nums[i - 1];
  }
  int n;
  cin >> n;
  dfs(n, nums);
  cout << endl;
  return 0;
}