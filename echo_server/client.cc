#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>

int main() {
  int fd;
  struct sockaddr_in servaddr;

  fd = socket(AF_INET, SOCK_STREAM, 0);

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
  servaddr.sin_port = htons(10456);
  
  connect(fd, (sockaddr *)&servaddr, sizeof(servaddr));

  char str[50] = "hello";
  write(fd, str, sizeof(str));

  int count = 0;
  while (1) {
    char buf[1024];
    ssize_t n;
    if ((n = read(fd, buf, 1024)) > 0) {
      write(fd, buf, n);
      std::cout << "count = " << count++ << std::endl;
    } else {
      std::cout << "error" << std::endl;
      return 1;
    }
  }

  return 0;
}