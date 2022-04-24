#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int find(int x) {  // 返回(x,y)的祖宗节点 + 路径优化
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row_len = grid.size();
        int col_len = grid[0].size();

        for (int i = 0; i < row_len; i++) {
            for (int j = 0; j < col_len; j++) {
                if (grid[i][j]) {
                    int num = i * col_len + j;
                    p[num] = num;
                    size[num] = 1;
                    max = 1;
                }
            }
        }

        for (int i = 0; i < row_len; i++) {
            for (int j = 0; j < col_len; j++) {
                if (j < col_len - 1 && (grid[i][j] & grid[i][j+1]) == 1) {
                    int num1 = i * col_len + j;
                    int num2 = i * col_len + j + 1;
                    if (find(num1) != find(num2)) {  // 不是同一个集合
                        size[find(num2)] += size[find(num1)];
                        max = std::max(max, size[find(num2)]);
                        p[find(num1)] = find(num2);
                    }
                }
                if (i < row_len - 1 && (grid[i][j] & grid[i+1][j]) == 1) {
                    int num1 = i * col_len + j;
                    int num2 = (i+1) * col_len + j;
                    if (find(num1) != find(num2)) {  // 不是同一个集合
                        size[find(num2)] += size[find(num1)];
                        max = std::max(max, size[find(num2)]);
                        p[find(num1)] = find(num2);
                    }
                }
            }
        }
        return max;
    }

    int p[100010] = {0};
    int size[100010] = {0};
    int max = 0;
};

int main() {
  Solution s;
  vector<vector<int>> grid = {{0,1,1},{1,1,1}};
  int max = s.maxAreaOfIsland(grid);
  return 0;
}