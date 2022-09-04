#include <bits/stdc++.h>

template<typename T>
class smart_point {
public:
  explicit smart_point(T *obj = nullptr) {
    if (obj != nullptr) {
      obj_ = obj;
      ref_cnt_ = new std::atomic<size_t>(0);
      increase();
    }
  }

  ~smart_point() {
    if (obj_ != nullptr) {
      decrease();
      if (*ref_cnt_ == 0) {
        delete obj_;
        obj_ = nullptr;
        delete ref_cnt_;
        ref_cnt_ = nullptr;
      }
    }
  }

  smart_point(const smart_point &other) {
    obj_ = other.obj_;
    ref_cnt_ = other.ref_cnt_;
    increase();
  }

  smart_point& operator=(const smart_point &other) {
    if (this == &other) {
      return *this;
    }
    if (obj_ != other.obj_) {
      decrease();
      if (*ref_cnt_ == 0) {
        delete obj_;
        obj_ = nullptr;
        delete ref_cnt_;
        ref_cnt_ = nullptr;
      }
    }
    obj_ = other.obj_;
    ref_cnt_ = other.ref_cnt_;
    increase();  
    return *this;
  }

  T& operator*() { return *obj_; }
  T* operator->() { return obj_; }

  size_t use_count() { return *ref_cnt_; }

private:
  void increase() { (*ref_cnt_)++; }
  void decrease() { (*ref_cnt_)--; }

  T *obj_;
  std::atomic<size_t> *ref_cnt_;
};

class A {
public:
  int a;
};

int main() {
  smart_point<A> sp1(new A);
  smart_point<A> sp2(new A);
  sp1 = sp2;
  return 0;
}