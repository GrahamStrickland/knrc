#include <stdio.h>

void shellsort(int v[], int n);

main()
{
    int i;
    int n = 13;
    int arr[] = {3, 12, 8, 12, 98,
                 52, 10, 91, 10, 9,
                 4, -1, 89};

    printf("Unsorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    shellsort(arr, n);
    printf("\nSorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

/* shellsort: sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n)
{
    int gap, i, j, temp;

    for (gap = n/2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for(j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
}
