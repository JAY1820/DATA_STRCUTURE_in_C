#include <stdio.h>
#define MAX_SIZE 100

typedef struct
{
    int top;
    int arr[MAX_SIZE];
} int_stack;


void initIntStack(int_stack *s)
{
    s->top = -1;
}

void push(int_stack *s, int item)
{
    if (s->top == MAX_SIZE - 1)
    {
        printf("Stack Overflow!\n");
        return;
    }
    else
    {
        s->arr[++s->top] = item;
    }
}

int pop(int_stack *s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    else
    {
        int item = s->arr[s->top--];
        return item;
    }
}
int peek(int_stack *s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    else
    {
        int item = s->arr[s->top];
        return item;
    }
}
void display(int_stack *s)
{
    int i;
    for (i = 0; i <= s->top; i++)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int isEmpty(int_stack *s)
{
    return s->top == -1;
}

int precedence(char op)
{
    if (op == '*' || op == '/')
    {
        return 3;
    }
    else if (op == '+' || op == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}