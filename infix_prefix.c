#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "int_stack.h"

#define MAX_SIZE 100

//reverse the string
void reverse(char *exp)
{
    int i,j;
    char temp;
    for(i=0,j=strlen(exp)-1;i<j;i++,j--)
    {
        temp=exp[i];
        exp[i]=exp[j];
        exp[j]=temp;
    }
}

char *infixtoprefix(char *exp)
{
    int_stack s1;
    initIntStack(&s1);
    reverse(exp);
    char * result= (char *) malloc(sizeof(char*) * strlen(exp)+1);

    int i=0,j=0;

    for(i=0;i<strlen(exp);i++)
    {
        if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z'))
        {
            result[j++]=exp[i];
        }

        else if (exp[i]==')')
        {
            push(&s1,exp[i]);
        }

        else if (exp[i]=='(')
        {
            while (!isEmpty(&s1) && peek(&s1) != ')')
            {
                result[j++] = pop(&s1);
            }

            if(!isEmpty(&s1))
            {
                pop(&s1);
            }

            else
            {
               while (!isEmpty(&s1) && precedence(exp[i])<=precedence(peek(&s1)))
               {
                  result[j++]=pop(&s1);
               }
               push(&s1,exp[i]);
               
            }
        }
        else
        {
            while (!isEmpty(&s1) && precedence(exp[i])<=precedence(peek(&s1)))
            {
                result[j++]=pop(&s1);
            }
            push(&s1,exp[i]);
        }
    }

    while (!isEmpty(&s1))
    {
        result[j++]=pop(&s1);
    }
    
    result[j] ='\0';
    reverse(result);
    return result;
}

int main()
{

 printf("enter the infix expression\n");
 char exp[MAX_SIZE];
 scanf("%s",exp);
 printf("infix expression is %s\n",exp);
 char *prefix = infixtoprefix(exp);
 
 printf("prefix expression is %s\n",prefix);

 return 0;
}
