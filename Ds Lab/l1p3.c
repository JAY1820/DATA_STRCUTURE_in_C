#include <stdio.h>

int main() {
    int number;
    int *p;
    int **p2;

  printf("Enter the number");
  scanf("%d",&number);

    p=&number;
    p2=&p;

    printf("Address of number: %p\n", &number);
    printf("Value of num: %d\n", number);

    printf("Address of *p: %p\n", &p);
    printf("Value of *p: %p\n", p);

    printf("Address of **p: %p\n", &p);
    printf("Value of **p: %p\n", p);
    
    return 0;
}