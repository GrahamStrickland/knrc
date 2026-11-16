#include <stdio.h>
#include <stdlib.h>

void f(int *arr /*arr[]*/);

int main() {
  int a[10];
  int *pa;
  int i;

  for (i = 0; i < 10; i++)
    a[i] = i;

  printf("pa = &a[0]\n");
  pa = &a[0];

  printf("x = *pa\n");
  int x = *pa;

  printf("x = %d\n", x);

  for (i = 0; i < 10; i++)
    printf("*(pa+%d) = %d\n", i, *(pa + i));

  pa = a;
  printf("pa = a\n");
  for (i = 0; i < 10; i++)
    printf("*(pa+%d) = %d\n", i, *(pa + i));

  for (i = 0; i < 10; i++)
    printf("*(a+%d) = %d\n", i, *(a + i));

  f(&a[2]);
  f(a + 2);

  return EXIT_SUCCESS;
}

void f(int *arr /*arr[]*/) { printf("%d\n", arr[0]); }
