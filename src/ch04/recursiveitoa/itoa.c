#include <stdio.h>

#include "itoa.h"

/* itoa: convert n to characters in s */
void itoa(int n, char s[], int i)
{
    if (n < 0) {
        s[0] = '-';
        n = -n;
    }
    if (n / 10)
        itoa(n / 10, s, i++);
    s[i] = n % 10 + '0';
    s[i+1] = '\0';
}
