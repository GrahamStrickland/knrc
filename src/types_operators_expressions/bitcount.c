#include <stdio.h>

int bitcount(unsigned x);

main() {
  unsigned int x = 0x1f93ff;
  int c = bitcount(x);

  printf("bitcount(%u (%x)) =  %d\n", x, x, c);

  return 0;
}

/* bitcount: count 1 bits in x */
int bitcount(unsigned x) {
  int b;

  for (b = 0; x != 0; x >>= 1)
    if (x & 01)
      b++;
  return b;
}
