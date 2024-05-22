#include <stdio.h>
#define TABSTOPS 8      /* number of tab stops */

main()
{
    int count = 0, c, spaces;

    while ((c = getchar()) != EOF)
    {
        if (c == '\n')      /* reset count for newlines */ 
        {
            count = 0;
            spaces = 0;
            putchar('\n');
        }
        else if (c == ' ')  /* set number of spaces to output */
        {
            ++spaces;
            ++count;
        }
        else {  /* output characters or tabs and spaces */
            while (spaces > 0)
            {   /* output tabs if enough spaces */
                if (spaces > TABSTOPS)
                {
                    putchar('\t');
                    spaces = spaces - TABSTOPS;
                }
                else    /* output spaces */
                {
                    putchar(' ');
                    spaces--;
                }
            }   /* output non-whitespace characters */
            putchar(c);
            ++count;
            spaces = 0;
        }
    }
    return 0;
}
