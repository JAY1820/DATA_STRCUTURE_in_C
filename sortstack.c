
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int data)
{
    if (top == SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = data;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    int data=stack[top];
    top--;
    return data;
}

int peek()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top];
}

void sort_stack()
{
    int temp[SIZE];
    int i=0;
    while(top!=-1)
    {
        temp[i]=pop();
        i++;
    }
    int j;
    for(i=0;i<top;i++)
    {
        for(j=0;j<top-i;j++)
        {
            if(temp[j]>temp[j+1])
            {
                int t=temp[j];
                temp[j]=temp[j+1];
                temp[j+1]=t;
            }
        }

    
        
    }
}


int main()
{
    printf("enter size of stack\n");
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {
        int data;
        scanf("%d",&data);
        push(data);
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",pop());
    }

    sort_stack();

    return 0;
}