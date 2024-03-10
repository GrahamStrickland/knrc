#include <stdio.h>

#include "reverse.h"

main(int argc, char* argv[])
{
    int len = 7;
    char s1[] = "Racecar";

    printf("Before calling reverse, s = %s\n", s1);
    reverse(s1, 0, len);
    printf("After calling reverse, s = %s\n", s1);

    len = 14;
    char s2[] = "Madam I'm Adam";

    printf("Before calling reverse, s = %s\n", s2);
    reverse(s2, 0, len);
    printf("After calling reverse, s = %s\n", s2);

    return 0;
}
