#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

#include "calc.h"

/* getop: get next operator or numeric operand */
getop(char s[]) {
    static char buf[BUFSIZE];
    static int bufp = 0;
    int i, c;

    while ((bufp > 0 && (c = buf[bufp]) == ' ' || c == '\t') || 
            ((s[0] = c = getch()) == ' ' || c == '\t'))
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;       /* not a number */
    i = 0;
    if (isdigit(c))     /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')       /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF) {
        if (bufp >= BUFSIZE)
            printf("getop: too many characters\n");
        else
            buf[bufp++] = c;
    }

    return NUMBER;
}

