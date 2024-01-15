#include <stdio.h>
#define TABSTOPS 8          /* fixed number of tab stops */

/* detab: replaces tabs in the input with
the proper number of blanks to tab to the next stop*/
main()
{
    int count = 0, c, i;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            count = 0;
            putchar('\n');
        }
        else if (c == '\t') {
            for (i=0; i < (TABSTOPS - (count % TABSTOPS)); ++i)
                putchar(' ');
            count = count + i;
        }
        else {
            putchar(c);
            ++count;
        }
    }

    return 0;
}
