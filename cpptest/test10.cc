// 虹软一面

#include <bits/stdc++.h>

using namespace std;

void strcpy(char* src, char* dst) {
  if (!dst || !src) return;
  while (*src != '/0') {
    *(dst++) = *(src++);
  }
  *dst = '/0';
}