#include <stdio.h>

void print_variables(int x, int y, int z[], int *ip);

int main()
{
    int x = 1, y = 2, z[10];
    int *ip;            /* ip is a pointer to int */

    int i;
    for (i = 0; i < 10; ++i)
        z[i] = i * 2;

    ip = &x;            /* ip now points to x */ 
    print_variables(x, y, z, ip);
    y = *ip;            /* y is now 1 */
    print_variables(x, y, z, ip);
    *ip = 0;            /* x is now 0 */
    print_variables(x, y, z, ip);
    ip = &z[0];         /* ip now points to z[0] */
    print_variables(x, y, z, ip);

    *ip = *ip + 10;
    print_variables(x, y, z, ip);
    y = *ip + 1;
    print_variables(x, y, z, ip);
    *ip += 1;
    print_variables(x, y, z, ip);
    ++*ip;
    print_variables(x, y, z, ip);
    (*ip)++;
    print_variables(x, y, z, ip);

    return 0;
}

void print_variables(int x, int y, int z[], int *ip)
{
    int i;

    printf("x = %d, y = %d, ", x, y);
    printf("z = [");
    for (i = 0; i < 10; ++i) {
        printf("%d", z[i]);
        printf(i < 9 ? ", " : "]");
    }
    printf(", *ip = %d\n", *ip);
}
