// 地平线二面

#include <bits/stdc++.h>  

using namespace std;

bool my_atoi(char *input, int &result) {
  long long ret = 0;
  
  // 判空
  if (input == nullptr) {
    return false;
  }

  // 判断空格
  while (*input != '\0' && *input == ' ') {
    input++;
  }
  if (*input == '\0') {
    return false;
  }

  // 判断正负
  bool neg = false;
  if (*input == '-') {
    neg = true;
    input++;
  }

  // 判断0x
  bool sixth = false;
  if (*input == '0' && *(input+1) == 'x') {
    sixth = true;
    input += 2;
  }

  // 计算
  if (!sixth) {
    while (*input != '\0') {
      if (*input <= '9' && *input >= '0') {
        ret = ret * 10 + (*input - '0');
      } else {
        return false;
      }
      input++;
    }
  } else {
    while (*input != '\0') {
      if (*input <= '9' && *input >= '0') {
        ret = ret * 16 + (*input - '0');
      } else if (*input <= 'F' && *input >= 'A') {
        ret = ret * 16 + (*input - 'A' + 10);
      } else {
        return false;
      }
      input++;
    }
  }

  result = ret;
  return true;
}