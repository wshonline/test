#include <bits/stdc++.h>
using namespace std;

int a;

int * const fun() { return &a; }

int main() {
  // 如果函数是 int const * fun() 或 const int * fun()
  // 那么下方必须是 int const *a = fun() 或 const int *a = fun() 才编译通过

  int *a = fun();  // 该句编译通过，不应该是 int * const a = fun(); 才OK的吗
  a = (int*)(0x123);

  return 0;
}