#include <ctype.h>

#include "../functions_structure/calc/getch.c"

#define SIZE 10

int getint(int *pn);

int main(int argc, char *argv[]) {
  if (argc == 2) {
    if (getint((int *)argv[1]) > 0)
      printf("Success, %d", *argv[1]);
    else
      printf("Failure");
  }

  return 0;
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
  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}
