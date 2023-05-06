#include <stdio.h>

int main() {
    char str1[100], str2[100];
    char *p1, *p2;
    int flag = 0;

    printf("Enter first string: ");
    scanf("%s",str1);

    printf("Enter second string: ");
    scanf("%s",str1);

    p1 = str1;
    p2 = str2;
    while (*p1 != '\0' || *p2 != '\0') {
        if (*p1 != *p2) {
            flag = 1;
            break;
        }
        p1++;
        p2++;
    }

    if (flag == 0) {
        printf("Strings are equal\n");
    } else {
        printf("Strings are not equal\n");
    }

    return 0;
}
