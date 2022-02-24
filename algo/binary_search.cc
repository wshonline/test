// 整数二分算法

#include <vector>

bool check(int mid) {
  return true;
}

// mid属于左半边, 区间划分成[l, mid]和[mid + 1, r]
int search_1(int l, int r) {
  while (l < r) {
    int mid = l + r >> 1;
    if (check(mid)) { r = mid; }
    else { l = mid + 1; }  
  }
  return l;
}

// mid属于右半边, 区间划分成[l, mid - 1]和[mid, r]
int search_2(int l, int r) {
  while (l < r) {
    int mid = l + r + 1 >> 1;
    if (check(mid)) { l = mid; }
    else { r = mid - 1; }
  }
  return l;
}

int main() {

  return 0;
}