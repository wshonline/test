#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int x = 10;

int main() {
  printf("Parent have yet to call fork\n");
  pid_t cur_pid = fork();

  if (cur_pid == 0) {
    x++;
    printf("%d\n", x);
    printf("The child pid is %d\n", getpid());
    printf("The parent pid is %d\n", getppid());
    execve("hello", 0, 0);
    exit(0);
  }

  wait(0);
  printf("%d\n", x);
  printf("After fork() the child's pid is %d\n", cur_pid);
  printf("After fork() the parent's pid is %d\n", getpid());
  printf("end\n");

  return 0;
}
