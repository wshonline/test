#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'findMinHealth' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY power
 *  2. INTEGER armor
 */

long findMinHealth(vector<int> power, int armor) {
    int sum = 0;
    for (int i = 0; i < power.size(); i++) {
        sum += power[i];
    }
    // 模拟
    while (1) {
        int ok = false;
        for (int i = 0; i < power.size(); i++) {
            int result = sum;  // key point
            int use_armor_idx = i;
            int j;
            for (j = 0; j < power.size(); j++) {
                result -= power[j];
                if (j == use_armor_idx) {
                    result += min(armor, power[j]);
                }
                if (result <= 0) {
                    break;
                }
            }
            if (j == power.size()) {
                ok = true;
                break;
            }
        }
        if (ok) {
            sum--;
        } else {
            return sum + 1;
        } 
    }
}

int main() {
  vector<int> power{1, 2, 3};
  cout << findMinHealth(power, 4) << endl;
  return 0;
}
