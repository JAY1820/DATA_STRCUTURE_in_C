#include <stdio.h>

void increment(int *num) {
    *num += 2;
}

void decrement(int *num) {
    *num -= 2;
}

void modify(int num, void (*pfunc)(int *)) {
    pfunc(&num);
    printf("modify number is : %d\n", num);
}

int main() {
    int num;
    int choice;
    void (*pfunc)(int *);

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Enter 1 to increment 2:\n");
    printf("Enter 2 to decrement 2:\n ");
    scanf("%d", &choice);

    if (choice == 1) {
        pfunc = &increment;
    } else if (choice == 2) {
        pfunc = &decrement;
    } else {
        printf("Invalid choice\n");
        return 1;
    }

    printf("no: %d\n", num);
    modify(num, pfunc);

    return 0;
}
