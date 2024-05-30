#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000     /* maximum input line length */

int getLine(char line[], int maxline);
void expand(char s1[], char s2[]);

int main(int argc, char* argv[])
{
    int len;                                    /* length of input line */
    char string1[MAXLINE], string2[MAXLINE];    /* strings for storing input and output */

    while ((len = getLine(string1, MAXLINE)) > 0) {
        expand(string1, string2);
        printf("%s", string2);
    }

    return 0;
}

/* getLine: read a line into s, return length */
int getLine(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* expand: expands shorthand notations in s1 into s2 */
void expand(char s1[], char s2[])
{
    int i, j, c;

    for (i = j = 0; i < MAXLINE && s1[i] != '\0' && j < MAXLINE; ++i, ++j) {
        if (i != 0 && s1[i] == '-' && !isspace(s1[i-1]) && !isspace(s1[i+1]))
        {
            for (c = s1[i-1], j = j-1; c <= s1[i+1] && j < MAXLINE; c++, j++)
                s2[j] = c;
            i += 1;
            j--;
        }
        else s2[j] = s1[i];
    }
    s2[j] = '\0';
}
