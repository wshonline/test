// 字节跳动正式批笔试第一题

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> nums;

// int result = 0;

// void func(vector<vector<int>> &nums, int i, int j, int score) {
//     if (j < 0 || j >= nums[0].size()) {
//         return;
//     }  
//     if (nums[i][j] != -1) {
//         score += nums[i][j];
//         result = max(score, result);
//     }
//     if (i == nums.size() - 1) {
//         return;
//     }
//     if (nums[i][j] == -1) {
//         func(nums, i+1, j-1, score);
//         func(nums, i+1, j+1, score);
//     } else {
//         func(nums, i+1, j, score);
//     }
// }

int main() {
    int N, M;
    cin >> N >> M;
    nums.resize(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> nums[i][j];
        }
    }
    // 方法2：
    for (int j = 0; j < M; j++) {
        if (nums[N-1][j] == -1) nums[N-1][j] = 0;
    }
    for (int i = N - 2; i >= 0; i--) {
        for (int j = 0; j < M; j++) {
            if (nums[i][j] != -1) {
                nums[i][j] += nums[i+1][j];
            } else {
                if (i > 0) {
                  int should_add_num;
                  if (j == 0) should_add_num = nums[i+1][j+1];
                  else if (j == M-1) should_add_num = nums[i+1][j-1];
                  else should_add_num = max(nums[i+1][j-1], nums[i+1][j+1]);
                  nums[i][j] = should_add_num;  
                } else {
                  // 第一行的-1不进行更新
                }
            }
        }
    }
    int max_s = 0;
    for (int j = 0; j < M; j++) {
        if (max_s < nums[0][j]) max_s =  nums[0][j];
    }
    // debug
    for (auto vec : nums) {
      for (auto num : vec) {
        cout << num << " ";
      }
      cout << endl;
    }
    cout << max_s << endl;
    // 方法1：
    // for (int j = 0; j < M; j++) {
    //     func(nums, 0, j, 0);
    // }
    // cout << result << endl;
    return 0;
}