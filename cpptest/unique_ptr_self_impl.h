#pragma once
#include <algorithm>

template <typename T>
class smart_ptr {
  public:
    explicit smart_ptr(T *ptr = nullptr)
      :  ptr_(ptr) {}
    ~smart_ptr() {
      delete ptr_;
    }

    T* get() const { return ptr_; }
    T& operator*() const { return *ptr_; }
    T* operator->() const { return ptr_; }
    operator bool() const { return ptr_; }  // 提供向bool值的隐式转换

    // 如果仅提供了移动构造函数，没有提供拷贝构造函数，那么后者被禁用
    smart_ptr(smart_ptr &&other) {
      ptr_ = other.ptr_;
    }

    // 编译器会根据实参的类型选择拷贝（这个例子中被禁用了）还是移动实参进rhs
    smart_ptr& operator=(smart_ptr rhs) {
      rhs.swap(*this);
      return *this;
    }

    T *release() {
        T *ptr = ptr_;
        ptr_ = nullptr;
        return ptr;
    }

    void swap(smart_ptr &rhs)
    {
        using std::swap;
        swap(ptr_, rhs.ptr_);
    }

    // 仅定义该函数，而不定义移动构造函数，不能阻止编译器为我们生成拷贝构造函数
    template <typename U>
    smart_ptr(smart_ptr<U> &&other) 
    {
        ptr_ = other.release();  // 要求U*可以被隐式转换为T*
    }

  private:
    T *ptr_;
};