#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int getLine(char line[], int maxline);
void reverse(char s[]);

/* reverse input one line at a time */
main() {
  int len;            /* current line length */
  char line[MAXLINE]; /* current input line */

  while ((len = getLine(line, MAXLINE)) > 0) {
    reverse(line);
    printf("%s", line);
  }

  return 0;
}

/* getLine: read a line into s, return length */
int getLine(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

/* reverse: reverses all characters in input string s */
void reverse(char s[]) {
  int i = 0, j, lim;

  while (s[i] != '\0')
    ++i;
  lim = i;

  char r[lim];

  for (j = 0; j < lim; ++j)
    r[j] = s[j];
  j = j - 2;

  for (i = 0; i < lim - 1; ++i) {
    s[i] = r[j];
    --j;
  }
}
