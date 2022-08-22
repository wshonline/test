// 美团笔试

#include <bits/stdc++.h>

using namespace std;

vector<int> path;
int result;

void backtracking (vector<int>& nums, int start_idx) {
    if (path.size() == 3) {
        if ((path[0] - path[1]) == (2 * path[1] - path[2])) {
            result++;
        }
        return;
    }
    for (int i = start_idx; i < nums.size(); i++) {
        path.push_back(nums[i]);
        backtracking(nums, i+1);
        path.pop_back();
    }
}

int main() {
  int n;
  cin >> n;
  
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  backtracking(nums, 0);
  cout << result << endl;
  return 0;
}