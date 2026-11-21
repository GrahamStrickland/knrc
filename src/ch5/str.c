#include <stdio.h>
#include <stdlib.h>

void strcpy(char *s, char *t);
int strcmp(char *s, char *t);

int main() {
  char amessage[] = "now is the time"; /* an array */
  char *pmessage = "now is the time";  /* a pointer */

  printf("hello, world\n");
  printf("%s\n", amessage);
  printf("%s\n", pmessage);

  return EXIT_SUCCESS;
}

/* strcpy: copy t to s; array subscript version */
/*void strcpy(char *s, char *t) {
  int i;

  i = 0;
  while ((s[i] = t[i]) != '\0')
    i++;
}*/

/* strcpy: copy t to s; pointer version 1 */
/*void strcpy(char *s, char *t) {
  while ((*s = *t) != '\0') {
    s++;
    t++;
  }
}*/

/* strcpy: copy t to s; pointer version 2 */
/*void strcpy(char *s, char *t) {
  while ((*s++ = *t++) != '\0')
    ;
}*/

/* strcpy: copy t to s; pointer version 3 */
void strcpy(char *s, char *t) {
  while (*s++ = *t++)
    ;
}

/* strcmp: return <0 if s<t, 0 is s==t, >0 if s>t */
/*int strcmp(char *s, char *t) {
  int i;

  for (i = 0; s[i] == t[i]; i++)
    if (s[i] == '\0')
      return 0;
  return s[i] - t[i];
}*/

/* strcmp: return <0 if s<t, 0 is s==t, >0 if s>t */
int strcmp(char *s, char *t) {
  for (; *s == *t; s++, t++)
    if (*s == '\0')
      return 0;
  return *s - *t;
}
