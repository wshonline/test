#include <bits/stdc++.h>
using namespace std;

int result = 0;

void dfs(vector<vector<int>> &nums, int i, int j,
         int up, int down, int left, int right,
         int long_len, int short_len, bool has_turn, int flag = 0) {
    // 退出
    if (i >= nums.size() || j >= nums[0].size() || i < 0 || j < 0 || nums[i][j] == 0) return;
    // 计算结果
    if (has_turn == true) {
        if (long_len == 2 * short_len) {
            result++;
            return;        
        } else if (long_len < 2 * short_len) {
            return;
        } else {
          if (flag == 1) dfs(nums, i-1, j, up, down, left, right, long_len, short_len+1, true, 1);
          else if (flag == 2) dfs(nums, i+1, j, up, down, left, right, long_len, short_len+1, true, 2);
          else if (flag == 3) dfs(nums, i, j-1, up, down, left, right, long_len, short_len+1, true, 3);
          else if (flag == 4) dfs(nums, i, j+1, up, down, left, right, long_len, short_len+1, true, 4);
        }
    }
    if (has_turn == false) {
        // 达到转弯标准，就转弯
        if ((long_len >= 4) && (long_len % 2 == 0)) {
            if (down == 0 && up == 0) dfs(nums, i-1, j, 1, down, left, right, long_len, short_len+1, true, 1);
            if (down == 0 && up == 0) dfs(nums, i+1, j, up, 1, left, right, long_len, short_len+1, true, 2);
            if (left == 0 && right == 0) dfs(nums, i, j-1, up, down, 1, right, long_len, short_len+1, true, 3);
            if (left == 0 && right == 0) dfs(nums, i, j+1, up, down, left, 1, long_len, short_len+1, true, 4);
        }
        // 继续增长较长段
        if (up == 1) dfs(nums, i-1, j, 1, down, left, right, long_len+1, short_len, false);
        else if (down == 1) dfs(nums, i+1, j, up, down, left, right, long_len+1, short_len, false);
        else if (left == 1) dfs(nums, i, j-1, up, down, 1, right, long_len+1, short_len, false);
        else if (right == 1) dfs(nums, i, j+1, up, down, left, 1, long_len+1, short_len, false);
    }
}

int main() {
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        // 读取
        int row_size, col_size;
        cin >> row_size >> col_size;
        vector<vector<int>> nums(row_size, vector<int>(col_size));
        for (int row = 0; row < row_size; row++) {
            for (int col = 0; col < col_size; col++) {
                cin >> nums[row][col];
            }
        }
        // 计算
        for (int row = 0; row < row_size; row++) {
            for (int col = 0; col < col_size; col++) {
                dfs(nums, row, col, 1, 0, 0, 0,
                    1, 1, false);
                dfs(nums, row, col, 0, 1, 0, 0,
                    1, 1, false);
                dfs(nums, row, col, 0, 0, 1, 0,
                    1, 1, false);
                dfs(nums, row, col, 0, 0, 0, 1,
                    1, 1, false);
            }
        }
        cout << "Case #" << i+1 << ": " << result << endl;
    }
    return 0;
}