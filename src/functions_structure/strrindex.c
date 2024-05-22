#include <stdio.h>
#define MAXLINE 1000        /* maximum input line length */

int getLine(char line[], int max);
int strrindex(char s[], char t);

main()
{
    int pos = 0;        /* position of character to be searched for */
    char c = 'o';       /* character to be searched for */
    char line[MAXLINE]; /* current input line */

    while (getLine(line, MAXLINE) > 0) {
        pos = strrindex(line, c);
        if (pos >= 0) 
            printf("Rightmost occurrence of %c in %s%d\n",
                    c, line, pos);
        else
            printf("%c does not occur in %s",
                    c, line);

    }

    return 0;
}

/* getLine: get line into s, return length */
int getLine(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* strrindex: return position of rightmost occurrence of t in s,
 * -1 if there is none */
int strrindex(char s[], char t)
{
    int i, pos = -1;

    for (i = 0; i < MAXLINE && s[i] != '\0'; ++i) {
        if (s[i] == t)
            pos = i;
    }

    return pos;
}
