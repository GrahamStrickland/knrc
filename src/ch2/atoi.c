#include <stdio.h>

int atoi(char s[]);

main() {
  char str[] = "891472981";
  int i;

  i = atoi(str);

  printf("%d\n", i);

  return 0;
}

/* atoi: convert s to integer */
int atoi(char s[]) {
  int i, n;

  n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    n = 10 * n + (s[i] - '0');
  return n;
}
