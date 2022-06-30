#include <string>
using namespace std;

string reverseWords(string s) {
    string ret, tmp;
    int i = 0;
    while (i < s.size()) {
        tmp = "";
        while (i < s.size() && s[i] == ' ')
          i++;
        while (i < s.size() && s[i] != ' ')
          tmp += s[i++];
        if (tmp != "")
          ret = tmp + " " + ret;
    }
    return ret.substr(0, ret.size()-1);
}

int main() {
  string str = "  hello world  ";
  string ret = reverseWords(str);
  return 0;
}