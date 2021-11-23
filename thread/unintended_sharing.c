#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *thread (void *vargp) {
  pthread_detach(pthread_self());
  int arg = *((int*) vargp);
  printf("hello from thread %d!\n", arg);
  // printf("vargp is %p\n", vargp); // vargp是不变的，一直都是主线程中栈变量i的地址
  return NULL;
}

int main (int argc, char *argv[]) {
  pthread_t tid;
  for(int i=0; i<10; i++) {
    pthread_create(&tid, NULL, thread, &i);
  }
  pthread_exit(NULL);
  return 0;
}
