#include <bits/stdc++.h>
// using namespace std;

// int main() {
//     using func_t = std::function<void()>;
//     func_t func;
//     {
//         int t = 2;
//         func = [&t]() {
//             std::cout << t << std::endl;
//             t=3;
//         };
//     }
//     func();
//     func();
// }

class T
{
  public:
    T() {}
    ~T() { std::cout << "析构" << std::endl; }
  private:
};

int main() {
    using func_t = std::function<void()>;
    func_t func;
    int t = 2;
    
    // func = [&t]() {
    //     std::cout << t << std::endl;
    //     t=3;
    // };
    struct myFunc {
      public:
        void operator() () {
          std::cout << t << std::endl;
          t = 3;
        }
        myFunc(int &tt) : t(tt) {}
      private:
        int &t;
    };
    
    myFunc temp(t);
    func = temp;

    func();
    func();
}