#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// Function to check if the stack is full
int is_full(int *top) {
    return *top == MAX - 1;
}

// Function to check if the stack is empty
int is_empty(int *top) {
    return *top == -1;
}

// Function to add an item to the stack
void push(int *st,int item,int *top) {
    if (!is_full(top)) {
        st[++(*top)] = item;
        //printf("Item %c has been added to the stack\n", item);
    } else {
        printf("Error: Stack is full\n");
    }
}

// Function to remove an item from the stack
char pop(int *st,int *top) {
    if (!is_empty(top)) {
        return st[(*top)--];
    } else {
        printf("Error: Stack is empty\n");
        return '\0';
    }
}

// Function to peek at the top item in the stack
char peek(int *stack,int *top) {
    if (!is_empty(top)) {
        return stack[*top];
    } else {
        printf("Error: Stack is empty\n");
        return '\0';
    }
}

// Function to change the value of an item in the stack
void change(int *stack,int *top, int position,int item) {
    int tp= *top;
    if (position <= tp ) {
        stack[position - 1] = item;
        printf("Item %c has been changed to %c\n", stack[position - 1], item);
    } else {
        printf("Error: Invalid position\n");
    }
}

// Function to display the items in the stack
void display(int *stack, int *top) {
    int i;
    //printf("Stack: ");
    for (i = *top; i >= 0; i--) {
        printf("%i", stack[i]);
    }
    printf("\n");
}

