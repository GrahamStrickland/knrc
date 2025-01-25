#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int getLine(char line[], int maxline);
void squeeze(char string[], int character);

main() {
  int len;            /* current line length */
  char line[MAXLINE]; /* current input line */

  while ((len = getLine(line, MAXLINE)) > 0) {
    squeeze(line, 'a');
    printf("%s", line);
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

/* squeeze: delete all c from s */
void squeeze(char s[], int c) {
  int i, j;

  for (i = j = 0; s[i] != '\0'; i++)
    if (s[i] != c)
      s[j++] = s[i];
  s[j] = '\0';
}
