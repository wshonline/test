// 百度第二次笔试

#include <bits/stdc++.h>

using namespace std;

// bool yuan(char c) {
//   if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
//   else return false;
// }

// vector<bool> flags(26);

// bool check(string &str) {
//   // 检查重复
//   for (int i = 0; i < 26; i++) flags[i] = false;
//   for (int i = 0; i < 5; i++) {
//     if (flags[str[i]-'a'] == false) flags[str[i]-'a'] = true;
//     else return false;
//   }
//   // 检查元音辅音
//   if (yuan(str[1]) && yuan(str[2]) && yuan(str[4]) &&
//       !yuan(str[0]) && !yuan(str[3])) return true;
//   else return false;
// }

// int main() {
//   string str; cin >> str;
//   int sum = 0;
//   for (int i = 0; i < str.size() - 4; i++) {
//     string substr = str.substr(i, 5);
//     if (check(substr)) {
//       sum++;
//     }
//   }
//   cout << sum << endl;
// }

int main() {
  int q; cin >> q;
  vector<string> strs(q);
  for (int i = 0; i < q; i++) cin >> strs[i];
  for (int i = 0; i < q; i++) {
    string str = strs[i];

    if (str.size() == 1) {
      cout << "Yes" << endl;
      continue;
    }
    // 模拟
    // 都变成0
    bool flag;
    for (int j = 0; j < str.size() - 1; j++) {
      // 后两位之前
      if (j < str.size() - 2) {
        if (str[j] == '0') continue;
        else {
          str[j] = '0';
          if (str[j+1] == '0') str[j+1] = '1';
          else str[j+1] = '0';
        }
      } else {
      // 比较最后两位
        if (str[j] == str[j+1]) flag = true;
        else flag = false;
      }
    }
    // 都变为1
    if (!flag) {
      str.clear();
      str = strs[i];
      for (int j = 0; j < str.size() - 1; j++) {
        // 后两位之前
        if (j < str.size() - 2) {
          if (str[j] == '1') continue;
          else {
            str[j] = '1';
            if (str[j+1] == '0') str[j+1] = '1';
            else str[j+1] = '0';
          }
        } else {
        // 比较最后两位
          if (str[j] == str[j+1]) flag = true;
          else flag = false;
        }
      }
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}