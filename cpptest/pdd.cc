// PDD 笔试

#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> cnts;
unordered_map<int, vector<int>> mp;
int ret_streets = 0, ret_sum = INT32_MAX;

void backtacking(int cur_street, int remaining, int streets, int sum) {
  if (remaining < cnts[cur_street]) return;
  if (mp.find(cur_street) == mp.end()) {
    streets++;
    sum += cnts[cur_street];
    if (ret_streets <= streets && ret_sum >= sum) {
      ret_streets = streets;
      ret_sum = sum;
    }
  }
  if (remaining >= cnts[cur_street]) {  
    if (mp.find(cur_street) != mp.end()) {
      vector<int> dsts = mp[cur_street];
      for (auto dst : dsts) {
        streets++;
        sum += cnts[cur_street];
        backtacking(dst, remaining - cnts[cur_street], streets, sum);
        if (ret_streets <= streets && ret_sum >= sum) {
            ret_streets = streets;
            ret_sum = sum;
        }
        streets--;
        sum -= cnts[cur_street];
      }
    }
  }
}

int main() {
  cin >> N >> M;
  cnts.resize(N+1);
  for (int i = 1; i <= N; i++) {
    cin >> cnts[i];
  }
  for (int i = 0; i < N - 1; i++) {
    int src, dst;
    cin >> src >> dst;
    if (mp.find(src) != mp.end()) mp[src].push_back(dst);
    else if (mp.find(dst) != mp.end()) mp[dst].push_back(src);
    else mp[src].push_back(dst);
  }
  backtacking(1, M, 0, 0);
  if (ret_streets == 0) ret_sum = 0;
  cout << ret_streets << " " << ret_sum << endl;
  return 0;
}