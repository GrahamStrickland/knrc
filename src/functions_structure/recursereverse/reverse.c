#include <stdio.h>

#include "reverse.h"

/* reverse: reverse s in place */
void reverse(char s[], int start, int end)
{
    if (start == end - 1 || start == end)
        return;
    else {
        char c = s[end - 1];
        s[end - 1] = s[start];
        s[start] = c;

        reverse(s, start + 1, end - 1);
    }
}
