// 腾讯TEG一面
// 大数相加

#include <bits/stdc++.h>

using namespace std;

string func(const string &num1, const string &num2) {
  string str;
  vector<int> vec;
  for (int i = num1.size() - 1; i >= 0; i--) {
    vec.push_back(num1[i] - '0');
  }
  for (int i = num2.size() - 1, j = 0; i >= 0; i--, j++) {
    if (j < num1.size()) {
      vec[j] += num2[i] - '0';
    } else {
      vec.push_back(num2[i] - '0');
    }
  }
  // ret
  for (int i = 0; i < vec.size() - 1; i++) {
    if (vec[i] < 10) {
      str = to_string(vec[i]) + str;
    } else {
      vec[i + 1] += 1;
      vec[i] -= 10;
      str = to_string(vec[i]) + str;
    }
  }
  if (vec.back() < 10) {
    str = to_string(vec.back()) + str;
  } else {
    str = "1" + to_string(vec.back() - 10) + str;
  }
  return str;
}

int main() {
  string num1 = "32627";
  string num2 = "3728";
  cout << func(num1, num2) << endl;
}