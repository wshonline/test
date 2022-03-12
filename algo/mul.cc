#include <vector>
#include <string>
#include <iostream>

// 高精度乘法
std::string multiply(std::string num1, std::string num2) {
    std::vector<int> v1, v2;
    for (int i = num1.size() - 1; i >= 0; i--) { v1.push_back(num1[i] - '0'); }
    for (int i = num2.size() - 1; i >= 0; i--) { v2.push_back(num2[i] - '0'); }
    
    int t = 0;
    std::vector<int> ret(v1.size() + v2.size(), 0);
    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v2.size(); j++) {
            t = ret[i + j] + v1[i] * v2[j];
            ret[i + j] = t % 10;
            ret[i + j + 1] += t / 10;
        }
    }

    while (ret.size() > 1 && ret.back() == 0) { ret.pop_back(); }

    std::string str;
    for (int i = ret.size() - 1; i >= 0; i--) {
        str += std::to_string(ret[i]);
    }

    return str;
}

int main() {
  std::string a = "2", b = "3";
  auto ret = multiply(a, b);
  std::cout << ret << std::endl;
  return 0;
}