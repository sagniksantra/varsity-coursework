#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *Prime(void *num) {
  int n = (int)num;
  int halfnum = (int)(n / 2);
  int i;
  for (i = 2; i <= halfnum; i++)
    if (n % i == 0)
      return NULL;
  printf("%d is a prime\n", n);
  return NULL;
}

int main() {
  int m, n, i, j;
  printf("Enter starting number(>1): ");
  scanf("%d", &n);
  printf("Enter ending number: ");
  scanf("%d", &m);
  pthread_t thread[m - n + 1];
  for (i = n, j = 0; i <= m; i++, j++) {
    pthread_create(&thread[j], NULL, Prime, (void *)i);
  }
  for (j = 0; j < m - n + 1; j++)
    pthread_join(thread[j], NULL);
  return 0;
}