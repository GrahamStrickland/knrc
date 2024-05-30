#include <stdio.h>

#include "qsort.h"

int main(int argc, char* argv[])
{
    int v[] = { 3, 14, 3, -19, 45, 2, 0, 100, 99 };
    int i, left = 0, right = 8;

    printf("Before qsort(v, %d, %d): ", left, right);

    for (i = 0; i <= right; i++)
        printf("%d ", v[i]);

    qsort(v, left, right);

    printf("\nBefore qsort(v, %d, %d): ", left, right);

    for (i = 0; i <= right; i++)
        printf("%d ", v[i]);

    printf("\n");
}
