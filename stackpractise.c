#include <stdio.h>
#include <stdlib.h>
#define M 10

int is_full()
{
    return (top == M-1 );
}

int is_empty() {
    return (top == -1);
}

char push(int *a[],int top,int x)
{
    if (top == N - 1) {
        printf("Stack overflow\n");
        return;
    }
    top++;
    stack[top] = x;
}

int pop()
{
    int x;
    if (top == -1)
    {
        printf(" Stack underflow\n");
        return -1;
    }

    x = stack[top];
    top--;
    return x;
}




//  print the elements of the stack
void ps()
{
    if (is_empty())
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements are: ");
    for (int i = top; i >= 0; i--)
     {
        printf("%d ", stack[i]);
    }
    printf("\n");
}



int main()
{
char stack[M];
int top = -1;



    return 0;
}
