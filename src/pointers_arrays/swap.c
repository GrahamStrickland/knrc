#include <stdio.h>

void swap(int *px, int *py);

int main() {
  int a = 2, b = 5;

  printf("Before swap, a = %d, b = %d\n", a, b);

  swap(&a, &b);

  printf("After swap, a = %d, b = %d\n", a, b);

  return 0;
}

void swap(int *px, int *py) /* interchange *px and *py */
{
  int temp;

  temp = *px;
  *px = *py;
  *py = temp;
}
