#include <stdio.h>
#include <stdlib.h>

int strlen(char *s);

int main() {
  int len;
  len = strlen("hello, world"); /* string constant */
  printf("len = %d\n", len);

  char array[101];
  int i;

  for (i = 32; i < 132; i++) {
    array[i - 32] = i;
    /* printf("array[%d] = %c\n", i - 32, array[i - 32]); */
  }
  array[100] = '\0';

  len = strlen(array); /* char array[100]; */
  printf("len = %d\n", len);

  char *ptr;
  ptr = &array[0];
  len = strlen(ptr); /* char *ptr; */
  printf("len = %d\n", len);

  return EXIT_SUCCESS;
}

/* strlen:  return length of string s */
int strlen(char *s) {
  int n;

  for (n = 0; *s != '\0'; s++)
    n++;
  return n;
}
