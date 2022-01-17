#include <iostream>
#include <string>
#include <cstring>
#include <random>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

const int N = 1000000;
vector<string> bigint;

class compare0 {
public:
  // string转ul，数值大小比较 
  bool operator()(const string &a, const string &b) {
    if (a.size() < b.size()) {
      return true;
    } else if (a.size() > b.size()) {
      return false;
    } else {
      return a < b;
    }
  }

};

class compare1 {
public:
  bool operator()(const string &a, const string &b) {
    return stoul(a) < stoul(b) ? true : false;
  }

};

void generateData() {
  auto engine = default_random_engine(random_device()());
  cout << "min = " << engine.min() << "; max = " << engine.max() << endl;
  for (int i = 0; i != N; ++i) {
    auto tmp = to_string(engine());
    if (tmp.c_str() == nullptr) {
      cout << "null " << endl;
    } else {
      bigint.push_back(tmp); 
    }   
  }
}

int main()
{
  clock_t start,finish;
  generateData();

  start = clock();
  sort(bigint.begin(), bigint.end(), compare0());
  finish = clock();
  cout << "test0:" << (finish-start) / CLOCKS_PER_SEC << endl;

  start = clock();
  sort(bigint.begin(), bigint.end(), compare1());
  finish = clock();
  cout << "test1:" << (finish-start) / CLOCKS_PER_SEC << endl;

	return 0;
}
