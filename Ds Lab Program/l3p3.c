#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, i, sum = 0;
    int *arr1, *arr2;

    printf("Enter the size : ");
    scanf("%d", &n);

    arr1 = (int *)malloc(n * sizeof(int));
    if (arr1 == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }

    printf("Enter %d integer elements for the array:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
        sum += arr1[i];
    }

    printf("\nSum of elements in the original array: %d", sum);

    printf("\n\nEnter the new size of the array: ");
    scanf("%d", &m);

    arr2 = (int *)realloc(arr1, m * sizeof(int));
    if (arr2 == NULL) {
        printf("Memory allocation failed!");
        free(arr1);
        return 1;
    }

    if (m > n) {
        printf("Enter %d integer elements for the revised array:\n", m - n);
        for (i = n; i < m; i++) {
            scanf("%d", &arr2[i]);
            sum += arr2[i];
        }
    }

    printf("\nSum of elements in the revised array: %d", sum);

    free(arr2);

    return 0;
}
