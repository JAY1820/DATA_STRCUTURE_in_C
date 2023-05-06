#include <stdio.h>

int isEven(int num) {
    return num % 2 == 0;
}

void checkNumber(int num, int (*pfunc)(int)) {
    if (pfunc(num)) {
        printf("%d is even.\n", num);
    } else {
        printf("%d is odd.\n", num);
    }
}

int main() {
    int num;
    int (*pfunc)(int);

    printf("Enter a number: ");
    scanf("%d", &num);

    pfunc = &isEven;

    checkNumber(num, pfunc);

    return 0;
}