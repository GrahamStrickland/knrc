#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

main() {
  int x = 0xF994, y = 0xFA49;
  int p = 4, n = 3;
  int z = setbits(x, p, n, y);
  printf("getbits(%u (%x), %d, %d, %u (%x)) = %u (%x)\n", x, x, p, n, y, y, z,
         z);

  return 0;
}

/* setbits: set n bits from position p of x to rightmost
 * n bits of y */
unsigned setbits(unsigned x, int p, int n, unsigned y) {
  return (x & ((~0 << n) << (p + 1 - n))) |
         ((y >> (p + 1 - n) & ~(~0 << n)) << (p + 1 - n));
}
