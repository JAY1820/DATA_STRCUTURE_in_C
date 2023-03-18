#include <stdio.h>
#include <stdlib.h>
#include "stack_op.h"
#define MAX 10

void main()
{
    char stack[MAX];
    char data=' ';
    int top=-1;
    int *tp=&top;

    printf("Give a  String:");
    while(data!='\n')
    {
       scanf("%c",&data);
       push(stack,data,tp);
    }
    printf("After reverse String:");
    display(stack,tp);
}
