#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

main()
{
    unsigned int x = 0x1fff;
    int p = 4, n = 3;
    unsigned int z = invert(x, p, n);
    printf("invert(%u (%x), %d, %d) = %u (%x)\n", x, x, p, 4, z, z);

    return 0;
}

/* invert: return x with n bits from p inverted */
unsigned invert(unsigned x, int p, int n)
{
    return x ^ (~(~0 << n) << (p+1-n));
}
