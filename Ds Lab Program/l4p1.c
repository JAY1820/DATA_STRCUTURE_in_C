#include <stdio.h>
#include <stdlib.h>
#include "stack_op.h"
#define MAX 10


int main() {
    char stack[MAX];
    int top1 = -1;
    int *top=&top1;
    int choice;
    char item;
    int pos;

    while (1) {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Change\n");
        printf("6. Check if full\n");
        printf("7. Check if empty\n");
        printf("8. Peep\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item: ");
                scanf(" %c", &item);
                push(stack,item,top);
                break;
            case 2:
                item = pop(stack,top);
                printf("Item %c has been removed from the stack\n", item);
                break;
            case 3:
                item = peek(stack,top);
                printf("Top item: %c\n", item);
                break;
            case 4:
                display(stack,top);
                break;
            case 5:
                printf("Enter the item: ");
                scanf(" %c", &item);
                printf("Enter the position: ");
                scanf("%d", &pos);
                change(stack,top,pos,item);
                break;
            case 7:
                if (is_empty(top))
                    printf("Stack is empty\n");
                else
                    printf("Stack is not empty\n");
                break;
            case 6:
                if (is_full(top))
                    printf("Stack is full\n");
                else
                    printf("Stack is not full\n");
                break;
            case 8:
                pos=0;
                printf("Enter position for see:");
                scanf("%d",&pos);
                printf("Peeped element: %c",peep(stack,top,pos));
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("Invalid choice!!\n");
                break;
            }
        }
    }
