#include <list>
#include <unordered_map>

class LRUCache {
public:
    LRUCache(int capacity) {
        max = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if (it != m.end()) {
            l.splice(l.end(), l, it->second);
            return it->second->second;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        // 已经存在
        if (it != m.end()) {
            l.splice(l.end(), l, it->second);
            it->second->second = value;
            return;
        }
        
        // 不存在
        if (m.size() < max) {  // 未满
            l.push_back({key, value});
            m.erase(l.front().first);
            l.pop_front();
            m[key] = --l.end();
        } else {  // 满

        }
    }

    std::list<std::pair<int, int>> l;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m;
    int max;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
  LRUCache lru(2);
  lru.put(1,1);
  lru.put(2,2);
  lru.get(1);
  lru.put(3,3);
  lru.get(2);
  lru.put(4,4);
  lru.get(1);
  lru.get(3);
  lru.get(4);
  return 0;
}