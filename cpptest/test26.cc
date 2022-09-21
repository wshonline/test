#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

// int main() {
//   int fd1, fd2;

//   fd1 = open("foo.txt", O_RDONLY, 0);
//   close(fd1);

//   fd2 = open("baz.txt", O_RDONLY, 0);
//   printf("fd2 = %d\n", fd2);

//   return 0;
// }

// int main() {
//   int fd1, fd2;
//   char c;

//   fd1 = open("foobar.txt", O_RDONLY, 0);
//   // printf("fd1=%d\n", fd1);
//   fd2 = open("foobar.txt", O_RDONLY, 0);
//   // printf("fd2=%d\n", fd2);
//   read(fd1, &c, 1);
//   // printf("c = %c\n", c);
//   read(fd2, &c, 1);
//   // printf("c = %c\n", c);
//   return 0;
// }

int main() {
  int fd = open("Jerry1", O_RDWR);  // 读写打开
  char data[300];

  lseek(fd, 500, 0);

  int count = read(fd, data, 300);  // 若读至文件末尾，count是read实际读入的字节数，可能会少于300
  printf("read_count = %d\n", count);

  count = write(fd, data, 300);
  printf("write_count = %d\n", count);

  return 0;
}