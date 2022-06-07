#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> record(26, 0);
        vector<int> ret;
        for (auto c : p) {
            record[c-'a']++;
        }
        vector<int> copy = record;
        int cur_idx = 0, begin_idx = 0;
        for (auto c : s) {
            cur_idx++;
            if (copy[c-'a'] == 0) {
                copy = record;
                begin_idx = cur_idx;
                continue;
            }
            copy[c-'a']--;
            if (check(copy)) {
                ret.push_back(begin_idx);
                copy = record;
                begin_idx = cur_idx;
            }
        }
        return ret;
    }
    bool check(vector<int> &vec) {
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] != 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
  Solution s;
  string str = "cbaebabacd";
  string p = "abc";
  std::vector<int> ret = s.findAnagrams(str, p);
  return 0;
}