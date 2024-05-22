#include <stdio.h>

#define MAXLINE 1000        /* maximum string length */

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

main()
{
    char inpString[MAXLINE] = "Hello, this is\na\tstring\n\tchars\n   ";
    char outpString[MAXLINE] = "";
    escape(inpString, outpString);

    printf("escape(\n%s\n)\n=\n%s\n", inpString, outpString);
    printf("unescape(\n%s\n)\n=\n%s\n", outpString, inpString);

    return 0;
}

/* escape: converts \n and \t in characters in s to escape sequences in t */
void escape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; i < MAXLINE && s[i] != '\0'; ++i) {
        switch(s[i]) {
        case '\n':
            t[j++] = '\'';
            t[j++] = '\\';
            t[j++] = 'n';
            t[j++] = '\'';
            break;
        case '\t':
            t[j++] = '\'';
            t[j++] = '\\';
            t[j++] = 't';
            t[j++] = '\'';
            break;
        default:
            t[j++] = s[i];
        }
            
    }
    t[++j] = '\0';
}

/* unescape: converts escape sequences \n and \t to newlines and tabs */
void unescape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; i < MAXLINE && s[i] != '\0'; ++i) {
        if (s[i++] == '\'')
        switch(s[i++]) {
        case 'n':
            if (s[i++] == '\'')
                t[j++] = '\n';
            else {
                i -= 2;
                t[j++] = '\'';
            }
            break;
        case 't':
            if (s[i++] == '\'')
                t[j++] = '\t';
            else {
                i -= 2;
                t[j++] = '\'';
            }
            break;
        default:
            t[j++] = s[i];
        }
    }
    t[++j] = '\0';
}
