#include <stdio.h>

#include "printd.h"

int main(int argc, char *argv[]) {
  printd(1013.0984);
  printf("\n");
  printd(-1013.0984);
  printf("\n");
  printd(10130984);
  printf("\n");
  printd(-10130984);
  printf("\n");

  return 0;
}
