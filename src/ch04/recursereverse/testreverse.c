#include <stdio.h>

#include "reverse.h"

main(int argc, char* argv[])
{
    int len = 8;
    char s[] = "Racecar";

    printf("Before calling reverse, s = %s\n", s);
    reverse(s, len);
    printf("After calling reverse, s = %s\n", s);

    return 0;
}
