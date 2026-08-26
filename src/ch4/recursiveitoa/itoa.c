#include <stdio.h>

#include "itoa.h"

/* itoa: convert n to characters in s */
void itoa(int n, char s[], int i) {
  if (n < 0) {
    s[0] = '-';
    n = -n;
    s[i] = '\0';
  } else if (n >> i == 1)
    s[i] = '\0';

  if (n / 10)
    itoa(n / 10, s, --i);
  else if (s[0] == '-')
    s[1] = n + '0';
  else
    s[0] = n + '0';

  s[i] = n % 10 + '0';
}
