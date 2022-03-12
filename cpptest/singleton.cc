#include <mutex>

class Nocopyable {
public:
    Nocopyable(const Nocopyable&) = delete;
    Nocopyable& operator=(const Nocopyable&) = delete;
};

template<typename T>
class Singleton : Nocopyable {
public:
    static T& getInstance() {
        // std::call_once(flag, [](){ value_ = new T(); });
        std::call_once(flag, init);
        return *value_ ;
    } 
private:
    static void init() {
        value_ = new T();
    }
    
    Singleton();
    ~Singleton();
    
    static std::once_flag flag;
    static T *value_ ;
};

template<typename T>
std::once_flag Singleton<T>::flag;
 
template<typename T>
T* Singleton<T>::value_ = NULL;

int main() {
    return 0;
}