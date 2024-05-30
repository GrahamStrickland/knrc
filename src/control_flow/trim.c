#include <stdio.h>
#include <string.h>

#define MAXLINE 1000        /* maximum unput line size */

int getLine(char line[], int maxline);
int trim(char s[]);

int main(int argc, char* argv[])
{
    int len;        /* current line length */
    int numChars;   /* store number of characters */
    char line[MAXLINE];     /* current input line */

    while ((len = getLine(line, MAXLINE)) > 0) {
        numChars = trim(line);
        if (numChars > 0)
            printf("%s\n", line);
    }

    return 0;
}

/* getLine: read a line into s, return length */
int getLine(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* trim: remove trailing blanks, tabs, newlines */
int trim(char s[])
{
    int n;

    for (n = strlen(s)-1; n >= 0; n--)
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
            break;
    s[n+1] = '\0';
    return n;
}
