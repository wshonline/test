#include <vector>
using namespace std;

int totalFruit(vector<int>& fruits) {
    // 滑动窗口
    int max_len = 0;
    int cur_len = 0;
    vector<int> per_type_cnt(fruits.size(), 0);
    int type_cnt = 0;

    int i = 0;
    for (int j = 0; j < fruits.size(); j++) {
        if (per_type_cnt[fruits[j]] > 0) {
            per_type_cnt[fruits[j]]++;
            cur_len = j-i+1;
            max_len  = max_len > cur_len ? max_len : cur_len;
        } else if (per_type_cnt[fruits[j]]==0 && type_cnt < 2) {
            per_type_cnt[fruits[j]]++;
            cur_len = j-i+1;
            max_len  = max_len > cur_len ? max_len : cur_len;
            type_cnt++;                
        } else if (per_type_cnt[fruits[j]]==0 && type_cnt == 2) {
            type_cnt++;
            per_type_cnt[fruits[j]]++;
            while (type_cnt == 3) {
                per_type_cnt[fruits[i]]--;
                if (per_type_cnt[fruits[i]] == 0) {
                    type_cnt--;
                }
                i++;
            }
        }
    }
    return max_len;
}

int main() {
  std::vector<int> v = {0,1,1,4,3};
  int num = totalFruit(v);
  return 0;
}