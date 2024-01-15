#include <stdio.h>
#include <string.h>

#define MAXLEN 100      /* maximum length of string */

void itob(int n, char s[], int b);
void reverse(char s[]);

main()
{
    char s[MAXLEN];
    int n = -268435455, b = 2;
    itob(n, s, b);

    printf("(%d)_10 = (%s)_%d\n", n, s, b);

    return 0;
}

/* itob: convert n to characters in s using base b */
void itob(int n, char s[], int b)
{
    int i, sign;

    if ((sign = n) < 0) /* record sign */
        n = -n;
    i = 0;
    do {        /* generate digits in reverse order */
        s[i++] = n % b + '0';   /* get next digit */
    } while ((n /= b) > 0);     /* delete it */
    if (sign < 0)
        s[i++] = '-';
    reverse(s);
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
