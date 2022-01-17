#include <string>
#include <iostream>
#include <regex>

std::string prefix_sql = "* from t1 A, t2 B where";
std::string postfix_sql = "and A.c2 = B.c2 and A.c3 = B.c3";

// bool sql_matches_pattern(std::string &sql, size_t &low, size_t &high) {
//   std::regex pattern("select /\\*\\+ordered use_nl\\(A,B\\)\\*/ \\* from t1 A, t2 B where A\\.c1 >= ([0-9]+) and A\\.c1 < ([0-9]+) and A\\.c2 = B\\.c2 and A\\.c3 = B\\.c3");
//   std::match_results<std::string::const_iterator> results;
//   if (std::regex_match(sql, results, pattern)) {
//     low = std::stol(results[1].str());
//     high = std::stol(results[2].str());
//     return true;
//   } else {
//     return false;
//   }
// }

void extract_numbers(const std::string &str, const int fst_num_pos, int &low, int &high) {
  int str_len = str.length();
  const char *s = str.c_str();
  bool low_is_seted = false, other_num = false, high_is_seted = false;
  int i = fst_num_pos;
  while (i < str_len) {
    if (s[i] >= '0'&& s[i] <= '9') {
      int j = i;
      int len = 0;
      while (s[i] >= '0'&& s[i] <= '9') {
        i++;
        len++;
      }
      std::string num_str = str.substr(j, len);
      if (!low_is_seted) {
        low = std::stoi(num_str);
        low_is_seted = true;
      } else if(!other_num) {
        other_num = true;
        continue;
      } else if (!high_is_seted) {
        high = std::stoi(num_str);
        high_is_seted = true;
      } else {
        break;
      }
    } else {
      i++;
    }
  }
  if (s[fst_num_pos] == '-') {
    low = 0;
  }
}

bool sql_matches_pattern(std::string &sql, int &low, int &high) {
  // const char *c = sql.c_str();
  // std::cout << "* from的*：" << c[32] << "    prefix_sql的长度" << prefix_sql.length() << std::endl;
  // std::cout << "and A.c2 = B.c2 and A.c3 = B.c3的a：" << c[sql.length()-postfix_sql.length()] << "    postfix_sql的长度" << postfix_sql.length() << std::endl;
  if (sql.length() < 110) {
    return false;
  }
  if(prefix_sql.compare(0, prefix_sql.length(), sql, 32, prefix_sql.length()) == 0 &&
     postfix_sql.compare(0, postfix_sql.length(), sql, sql.length()-postfix_sql.length(), postfix_sql.length()) == 0) {
    extract_numbers(sql, 64, low, high);
    if (low < high && high <= 100000) {
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}

int main() {
  std::string sql = "select /*+ordered use_nl(A,B)*/ * from t1 A, t2 B where A.c1 >= 44135 and A.c1 < 44335 and A.c2 = B.c2 and A.c3 = B.c3";
  std::cout << "sql_len = " << sql.length() << std::endl;

  int low, high;
  if (sql_matches_pattern(sql, low, high)) {
    std::cout << "匹配 low:" << low << " high:" << high << std::endl;
  } else {
    std::cout << "不匹配" << std::endl;
  }

  // size_t low, high;
  // if(sql_matches_pattern(sql, low, high)) {
  //   
  // } else {
  //   std::cout << "不匹配" << std::endl;
  // }
  return 0;
}
