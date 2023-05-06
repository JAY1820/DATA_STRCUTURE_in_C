#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Function to check if the stack is full
int is_full(int *top)
 {
    return *top == MAX - 1;
}

// Function to check if the stack is empty
int is_empty(int *top)
 {
    return *top == -1;
}

// Function to add an item to the stack
void push(char *st,char item,int *top) 
{
   if(is_full(top)){
       printf("stack is overflow\n");
   }else{
       st[++(*top)]=item;
   }
}

// Function to remove an item from the stack
char pop(char *st,int *top) {
    if(is_empty(top)){
        printf("stack is empty:\n");
    }else{
        return st[(*top)--];
    }
}

// Function to peek at the top item in the stack
char peek(char *st,int *top) {

     if(is_empty(top)){
        printf("stack is empty:\n");
    }else{
         return st[(*top)];
    }    
}

//function for peep  search of the any item
char peep(char *stack,int *top, int position) {
    int tp= *top;
    if (position <= tp ) {
        return stack[position -1];  //postion start with 0
    } else {
        printf("Error: Invalid position\n");
    }
}
// Function to change the value of an item in the stack
void change(char *stack,int *top, int position,char item) {
    int tp= *top;
    if (position <= tp ) {
        stack[position - 1] = item;
        printf("Item %c has been changed to %c\n", stack[position - 1], item);
    } else {
        printf("Error: Invalid position\n");
    }
}

// Function to display the items in the stack
void display(char *stack, int *top) {
    int i;
    //print a stack
    for (i = *top; i >= 0; i--)
     {
        printf("%c ", stack[i]);
    }
    printf("\n");
}
