#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>

int main() {
  int listen_fd, conn_fd;
  struct sockaddr_in servaddr, cliaddr;
  socklen_t cli_len;

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(10456);

  listen_fd = socket(AF_INET, SOCK_STREAM, 0);
  bind(listen_fd, (sockaddr *)&servaddr, sizeof(servaddr));
  listen(listen_fd, 1000);
  cli_len = sizeof(cliaddr);
  conn_fd = accept(listen_fd, (sockaddr *)&cliaddr, &cli_len);

  int count = 0;
  while (1) {
    char buf[1024];
    ssize_t n;
    if ((n = read(conn_fd, buf, 1024)) > 0) {
      write(conn_fd, buf, n);
      std::cout << "count = " << count++ << std::endl;
    } else {
      std::cout << "error" << std::endl;
      return 1;
    }
  }

  return 0;
}