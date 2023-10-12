#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *fibonacci(void *num) {
  int n = (int)num;
  if (n < 2)
    return (void *)n;
  int val;
  int i, first = 0, second = 1;
  for (i = 2; i <= n; i++) {
    val = first + second;
    first = second;
    second = val;
  }
  return (void *)val;
}
int main() {
  int i, exit;
  printf("How many numbers: ");
  scanf("%d", &exit);
  pthread_t thread[exit];
  for (i = 0; i < exit; i++)
    pthread_create(&thread[i], NULL, fibonacci, (void *)i);
  int out[exit];
  for(i=0;i<exit;i++)
	  pthread_join(thread[i], (void **)&out[i]);
  for(i=0;i<exit;i++)
	  printf("%d ",out[i]);
    return 0;
}