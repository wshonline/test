#include <unistd.h>
#include <sys/mman.h>
#include <iostream>
#include <bitset>
#include <chrono>
#include <string.h>

class bitmap {
public:
    bitmap(uint64_t bits_lens) {
        byte_lens = bits_lens / 8 + 1;
        bm = (char *)mmap(NULL, sizeof(char) * byte_lens, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        // memset(bm, 0, byte_lens);
    }

    bool operator[](uint64_t offset) {
        uint64_t offset_in_bitmap = offset >> 3;
        uint32_t offset_in_char = offset & 0b111;
        char charmap = bm[offset_in_bitmap];
        if((charmap >> (7 - offset_in_char)) & 1) {
            return true;
        } else {
            return false;
        }
    }

    void set(uint64_t offset) {
        uint64_t offset_in_bitmap = offset >> 3;
        uint32_t offset_in_char = offset & 0b111;
        char& charmap = bm[offset_in_bitmap];
        charmap |= (1 << (7 - offset_in_char));
    }

    void reset(uint64_t offset) {
        uint64_t offset_in_bitmap = offset >> 3;
        uint32_t offset_in_char = offset & 0b111;
        char& charmap = bm[offset_in_bitmap];
        charmap &= ~(1 << (7 - offset_in_char));
    }

    ~bitmap() {
        if(bm) {
            munmap(bm, sizeof(char) * byte_lens);
        }
    }
private:
    char* bm;
    uint64_t byte_lens;
};

int main() {
  std::chrono::system_clock::time_point start, end;

  start = std::chrono::system_clock::now();
  bitmap *b0 = new bitmap(0xffffffff);  // 256M
  end = std::chrono::system_clock::now();
  std::cout << "time: " << (double)std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() *
            std::chrono::microseconds::period::num / std::chrono::microseconds::period::den << std::endl;

  start = std::chrono::system_clock::now();    
  std::bitset<0xffffffff> *b1 = new std::bitset<0xffffffff>;
  end = std::chrono::system_clock::now();
  std::cout << "time: " << (double)std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() *
            std::chrono::microseconds::period::num / std::chrono::microseconds::period::den << std::endl;
  return 0;
}