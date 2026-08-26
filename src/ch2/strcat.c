#include <stdio.h>
#define MAXWORD 32 /* maximum input word size */

int getword(char line[], int maxline);
void strCat(char s[], char t[]);

main() {
  int len;            /* current input word length */
  char word[MAXWORD]; /* current input word */

  while ((len = getword(word, MAXWORD)) > 0) {
    strCat(word, "ay");
    printf("%s\n", word);
  }

  return 0;
}

/* getword: read a line into s, return length */
int getword(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n' && c != '\t' &&
              c != ' ';
       ++i)
    s[i] = c;
  if (c == '\n' || c == '\t' || c == ' ')
    s[i++] = '\0';

  return i;
}

/* strCat: concatenate t to end of s; s must be big enough */
void strCat(char s[], char t[]) {
  int i, j;

  i = j = 0;
  while (s[i] != '\0') /* find end of s */
    i++;
  while ((s[i++] = t[j++]) != '\0') /* copy t */
    ;
}
