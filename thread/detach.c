#include <stdio.h>
#include <pthread.h>

void *thread (void *vargp) {
  pthread_detach(pthread_self());
  printf("hello from thread world!\n");
}

int main (int argc, char *argv[]) {
  // This is used to record the thread id:
  pthread_t tid;

  printf("Main thread creating peer thread.\n");
  pthread_create(&tid, NULL, thread, NULL);
  
  pthread_exit(NULL);
  return 0;
}
