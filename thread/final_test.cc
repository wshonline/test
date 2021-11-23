#include <pthread.h>
#include <stdio.h>

struct foo {
  int a;
  int b;
};

static struct foo f[2];
int s =0;

/* The two following functions are running concurrently : */
void* sum_b (void *arg)
{
  for (int i = 0; i < 10000000; ++i)
      s += f[0].b;
  // printf("%d\n", s);
  return NULL;
}

void* inc_a(void *arg)
{
  for (int i = 0; i < 10000000; ++i)
    ++f[1].a;
  // printf("%d\n", f[1].a);
  return NULL;
}

int main() {
  pthread_t tid1, tid2;
  pthread_create(&tid1, NULL, inc_a, NULL);
  pthread_create(&tid2, NULL, sum_b, NULL);
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  return 0;
}