#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);

main() {
  int x = 0xF994, p = 4, n = 3;
  int z = getbits(x, p, n);
  printf("getbits(%u (%x), %d, %d) = %u (%x)\n", x, x, p, n, z, z);

  return 0;
}

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n) {
  return (x >> (p + 1 - n) & ~(~0 << n));
}
