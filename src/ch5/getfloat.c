#include <ctype.h>
#include <stdlib.h>

#include "../ch4/calc/getch.c"

#define SIZE 10

int n, getfloat(float *);
float array[SIZE];

int main(int argc, char *argv[]) {
  int res;
  for (n = 0; n < SIZE && (res = getfloat(&array[n])) != EOF && res != 0; n++)
    ;

  int i;
  for (i = 0; i < SIZE && i < n; i++)
    printf("%f ", array[i]);

  return EXIT_SUCCESS;
}

/* getfloat: get next 32-bit floating point number from input into *pf */
int getfloat(float *pf) {
  int c, sign;

  while (isspace(c = getch())) /* skip white space */
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
    ungetch(c); /* it's not a number */
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
    c = getch();
  for (*pf = 0.0; isdigit(c); c = getch())
    *pf = 10.0 * *pf + (c - '0');
  if (c == '.') {
    int num, denom;
    c = getch();
    for (num = 0, denom = 1; isdigit(c); c = getch(), denom *= 10)
      num = 10 * num + (c - '0');
    *pf += (float)num / (float)(denom);
  }
  *pf *= (float)sign;
  if (c != EOF)
    ungetch(c);
  return c;
}
