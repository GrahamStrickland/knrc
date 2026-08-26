#include <stdio.h>

#include "itoa.h"

main(int argc, char *argv[]) {
  int n = 1031234, i = 7;
  char s[i];
  itoa(n, s, i);
  printf("%d = %s\n", n, s);

  n = -1031234, i = 8;
  itoa(n, s, i);
  printf("%d = %s\n", n, s);

  return 0;
}
