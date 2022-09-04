#include <bits/stdc++.h>

// Scott Meyers，C++11，局部静态变量
// template<typename T>
// class singleton {
// public:
//   static T& get_instance() {
//     static T value;
//     return value;
//   }

//   singleton(const singleton &) = delete;
//   singleton& operator=(const singleton &) = delete;
// private:
//   singleton();
//   ~singleton();
// };

// 双重检查锁定
template<typename T>
class singleton {
public:
  static T& get_instance() {
    if (value == nullptr) {
      std::lock_guard<std::mutex> lg(mtx);
      if (value == nullptr) {
        value = new T();
      }
    }
    return *value;
  }

private:
  singleton();
  ~singleton();

  static T *value;
  static std::mutex mtx;
};

template<typename T> T* singleton<T>::value = nullptr;

template<typename T> std::mutex singleton<T>::mtx;

int main() {
  return 0;
}