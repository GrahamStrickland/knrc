#include <stdio.h>

unsigned int rightrot(unsigned int x, int n);

main()
{
    unsigned int x = 0x1fff;
    int n = 3;
    unsigned int z = rightrot(x, n);
    printf("rightrot(%u (%x), %d) = %u (%x)\n", x, x, n, z, z);

    return 0;
}

/* rightrot: returns x rotated to the right by n positions */
unsigned int rightrot(unsigned int x, int n)
{
    return (x >> n) | (x << (32 - n)) ;
}
