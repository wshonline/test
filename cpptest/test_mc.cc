#include <bits/stdc++.h>

using namespace std;

map<char, int> char_mp;
map<char, int> num_mp;

int main() {
  int N; cin >> N;
  vector<int> vec_len(N);
  vector<string> vec(N);
  for (int i = 0; i < N; i++) {
    cin >> vec_len[i];
    cin >> vec[i];
  }
  for (int i = 0; i < N; i++) {
    int str_len = vec_len[i];
    string str = vec[i];
    // save
    for (int i = 0; i < str_len; i++) {
      char c = str[i];
      if (c <= '9' && c >= '0') {
        num_mp[c]++;
      } else {
        char_mp[c]++;
      }
    }
    // consume;
    string new_str(str);
    for (int i = 0; i < str_len; i++) {
      char c = str[i];
      if (c <= '9' && c >= '0') {
        new_str[i] = (*num_mp.begin()).first;
        (*num_mp.begin()).second--;
        if ((*num_mp.begin()).second == 0) {
          num_mp.erase(num_mp.begin());
        }
      } else {
        new_str[i] = (*char_mp.begin()).first;
        (*char_mp.begin()).second--;
        if ((*char_mp.begin()).second == 0) {
          char_mp.erase(char_mp.begin());
        }        
      }
    }
    cout << new_str << endl;
  }
  return 0;
}