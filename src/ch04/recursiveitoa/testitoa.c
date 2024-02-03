#include <stdio.h>

#include "itoa.h"

main(int argc, char* argv[])
{
    int n = -1031234, i = 9;

    char s[i];

    itoa(n, s, i);

    printf("%s", s);

    return 0;
}
