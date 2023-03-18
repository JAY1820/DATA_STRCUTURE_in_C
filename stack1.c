#include <stdio.h>
#include <stdlib.h>

#define MAX 10



// Function to check if the stack is full
int is_full(int *top) 
{
    return *top == MAX - 1;
}

// Function to check if the stack is empty
int is_empty(int *top) {
    return *top == -1;
}

// Function to add an item to the stack
void push(char *st,char item,int *top) {
    if (!is_full(top)) {
        st[++(*top)] = item;
        printf("Item %c has been added to the stack\n", item);
    } else {
        printf("Error: Stack is full\n");
    }
}

// Function to remove an item from the stack
char pop(char *st,int *top) {
    if (!is_empty(top)) {
        return st[(*top)--];
    } else {
        printf("Error: Stack is empty\n");
        return '\0';
    }
}

// Function to peek at the top item in the stack
char peek(char *stack,int *top) {
    if (!is_empty(top)) {
        return stack[*top];
    } else {
        printf("Error: Stack is empty\n");
        return '\0';
    }
}

// Function to change the value of an item in the stack
void change(char *stack,int *top, int position,char item) 
{
    int tp= *top;
    if (position <= tp ) {
        char ch=stack[position - 1];
        stack[position - 1] = item;
        printf("Item %c has been changed to %c\n", ch, item);
    } else {
        printf("Error: Invalid position\n");
    }
}
char peep(char *stack,int *top, int position) {
    int tp= *top;
    if (position <= tp ) {
        return stack[position -1];
       // printf("Item %c has been changed to %c\n", stack[position - 1], item);
    } else {
        printf("Error: Invalid position\n");
    }
}

// Function to display the items in the stack
void display(char *stack, int *top) {
    int i;
    printf("Stack: ");
    for (i = *top; i >= 0; i--) {
        printf("%c ", stack[i]);
    }
    printf("\n");
}

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