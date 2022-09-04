#include <bits/stdc++.h>

using namespace std;

class LRUCache {
public:
  LRUCache(int cap) : cap_(cap) {

  }

  void put(int key, int value) {
    if (mp.find(key) == mp.end()) {
      if (mp.size() == cap_) {
        mp.erase(cache.back().first);
        cache.pop_back();
      }
    } else {
      cache.erase(mp[key]);
    }
    cache.push_front({key, value});
    mp[key] = cache.begin();
  }

  bool get(int key, int &value) {
    if (mp.find(key) == mp.end()) {
      return false;
    }
    auto kv = *mp[key];
    cache.erase(mp[key]);
    cache.push_front(kv);
    mp[key] = cache.begin();
    value = kv.second;
    return true;
  }

  void del(int key) {
    if (mp.find(key) != mp.end()) {
      cache.erase(mp[key]);
      mp.erase(key);
    }
  }

private:
  list<pair<int, int>> cache;
  unordered_map<int, list<pair<int, int>>::iterator> mp;
  int cap_;
};

int main() {

  return 0;
}