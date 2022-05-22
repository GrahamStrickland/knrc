#include <stdio.h>

#define MAXLINE 32       /* maximum length of string */

int getword(char line[], int maxline);
int htoi(char hex[]);

main()
{
    int len;            /* current line length */
    char line[MAXLINE];  /* current input line */


    while ((len = getword(line, MAXLINE)) > 0)
        printf("%d\n", htoi(line));

    return 0;
}


/* getword: read a word into s, return length */
int getword(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'
            && c!= '\t' && c != ' '; ++i)
        s[i] = c;
    if (c == '\n' || c == '\t' || c == ' ')
        s[i + 1] = '\0';
    return i;
}

/* htoi: convert a hexadecimal string to an int */
int htoi(char hex[])
{
    int val = 0;
    int exp = 0;
    int curExp = 0;
    int i, j, start;

    /* check for '0x' or '0X' at beginning of string */
    if (hex[0] == '0') {
        if (hex[1] == 'x' || hex[1] == 'X')
            start = 2;
        else start = 0;
    }
    else start = 0;

    /* find value of largest exponent */
    i = start;
    while (exp < MAXLINE && hex[i] != '\0') {
        ++exp;
        ++i;
    }
    
    /* add each digit to val */
    for (i = start; i < MAXLINE && hex[i] != '\0' && exp >= 0; ++i)
    {   /* calculate current exponent */
        curExp = 1;
        for (j = exp; j > 1; --j) curExp = curExp * 16;
        
        /* convert alphanumeric values to int */
        if (hex[i] >= 'a' && hex[i] <= 'f')
            val = val + (curExp * (hex[i] - 'a' + 10));
        else if (hex[i] >= 'A' && hex[i] <= 'F')
            val = val + (curExp * (hex[i] - 'A' + 10));
        else if (hex[i] >= '0' && hex[i] <= '9')
            val = val + (curExp * (hex[i] - '0'));
        else {
            printf("Error, invalid character encountered.\n");
            return -1;
        }
        
        --exp;  /* decrement exponent for next value */
    }

    return val;
}
