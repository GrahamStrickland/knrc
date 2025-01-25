#include <stdio.h>

#define str "I am a string"

int strLen(char s[]);

main() {
  printf("strLen(str) = %d\n", strLen(str));

  return 0;
}

/* strLen: return length of s */
int strLen(char s[]) {
  int i;

  i = 0;
  while (s[i] != '\0')
    ++i;
  return i;
}
