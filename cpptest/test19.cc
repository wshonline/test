#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;  // 输入：带权重的邻接矩阵，如果边存在权重均>0
vector<int> dp(graph.size(), 0);  // 以i为起点的最长路径长度
unordered_map<int, int> mp;  // 图中最长的路径
int maxlen_startnode = -1;

int func(int i) {
  if (dp[i] > 0) {
    return dp[i];
  }
  // 遍历所有出边
  for (int j = 0; j < graph.size(); j++) {
    if (graph[i][j] > 0) {
      int tmp = func(j) + graph[i][j];
      if (tmp > dp[i]) {
        dp[i] = tmp;
        mp[i] = j;  // 记录<src, dst>
      }
    }
  }
}

int main() {
  int maxlen = 0;
  // 以所有的点为起点，寻找最长路径
  for (int i = 0; i < graph.size(); i++) {
    func(i);
    if (dp[i] > maxlen) {
      maxlen = dp[i];
      maxlen_startnode = i;
    }
  }
  // 通过maxlen_startnode走mp，便得到最长的路径
  return 0;
}