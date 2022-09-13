// 腾讯音乐笔试第一题

#include <bits/stdc++.h>

using namespace std;

int func(string &str) {
  int result = 0;
  vector<int> cnt(26, 0);
  for (auto c : str) cnt[c-'a']++;
  set<pair<int, int>, greater<pair<int, int>>> set;  // cnt, char_idx
  for (int i = 0; i < 26; i++) set.insert({cnt[i], i});
  
  while (1) {
    auto iter = set.begin();
    auto kv = *iter;
    if (kv.first < 2) {
      break;
    }
    result++;

    set.erase(iter);
    set.insert({kv.first-2, kv.second});

    auto end_iter = --set.end();  // key point
    auto end_kv = *end_iter;
    set.erase(end_iter);
    set.insert({end_kv.first+1, end_kv.second});
  }

  return result;
}

int main() {
  string str = "abbbccccc";
  cout << func(str) << endl;
  return 0;
}