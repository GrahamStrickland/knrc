#include <ctype.h>
#include <stdlib.h>

#include "../ch4/calc/getch.c"

#define SIZE 10

int n, array[SIZE], getint(int *);

int main(int argc, char *argv[]) {
  int res;
  for (n = 0; n < SIZE && (res = getint(&array[n])) != EOF && res != 0; n++)
    ;

  int i;
  for (i = 0; i < SIZE && i < n; i++)
    printf("%d ", array[i]);

  return EXIT_SUCCESS;
}

/* getint: get next integer from input into *pn */
int getint(int *pn) {
  int c, sign;

  while (isspace(c = getch())) /* skip white space */
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c); /* it's not a number */
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
    c = getch();
  if (!isdigit(c)) {
    ungetch(c); /* also not a number */
    return 0;
  }
  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}
