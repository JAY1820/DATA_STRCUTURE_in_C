#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, *arr1, *arr2;

    printf("Enter the size: ");
    scanf("%d", &n);

    arr1 = (int *)malloc(n * sizeof(int));
    if (arr1 == NULL) {
        printf(" failed!");
        return 1;
    }

    printf("Enter %d element:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("\nAddress of the original array: %p", arr1);
    printf("\nElements of the original array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }

    printf("\n\nEnter the new size of the array: ");
    scanf("%d", &n);

    arr2 = (int *)realloc(arr1, n * sizeof(int));
    if (arr2 == NULL) {
        printf("Memory allocation failed!");
        free(arr1);
        return 1;
    }

    printf("\nAddress of the modified array: %p", arr2);
    printf("\nElements of the modified array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }

    free(arr2);

    return 0;
}
