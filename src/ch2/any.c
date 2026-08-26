#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int getLine(char line[], int maxline);
int any(char s1[], char s2[]);

main() {
  int len;            /* current line length */
  int loc;            /* location returned by any() */
  char line[MAXLINE]; /* current input line */

  while ((len = getLine(line, MAXLINE)) > 0) {
    loc = any(line, "aeiouAEIOU");
    printf("%sFirst vowel = %d\n", line, loc);
  }

  return 0;
}

/* getLine: read a line into s, return length */
int getLine(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n')
    s[i++] = c;

  s[i] = '\0';
  return i;
}

/* any: returns the location of first occurrence of characters
 *  from s2 in s1, or -1 if none occur */
int any(char s1[], char s2[]) {
  int i, j;

  for (i = 0; i < MAXLINE && s1[i] != '\0'; ++i)
    for (j = 0; j < MAXLINE && s2[j] != '\0'; ++j)
      if (s1[i] == s2[j])
        return i;

  return -1;
}
