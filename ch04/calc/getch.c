#include <stdio.h>

#define BUFSIZE 100

static char buf[BUFSIZE];   /* buffer for ungetch */
static int  bufp = 0;       /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */ 
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

