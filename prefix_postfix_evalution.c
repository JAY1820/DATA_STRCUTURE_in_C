#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "int_stack.h"

#define MAX_SIZE 100
int prefixevalution(char *exp)
{
    int_stack s;
    initIntStack(&s);
    int i;
    // prefix start with end
    for (i = strlen(exp) - 1; i >= 0; i--)
    {
        // Push operand to stack
        if (exp[i] >= '0' && exp[i] <= '9')
        {
            push(&s, exp[i] - '0');
        }

        else
        {
            int op1 = pop(&s);
            int op2 = pop(&s);
            
            switch (exp[i])
            {
            case '+':
                push(&s, op1 + op2);
                break;
            case '-':
                push(&s, op1 - op2);
                break;
            case '*':
                push(&s, op1 * op2);
                break;
            case '/':
                push(&s, op1 / op2);
                break;
            }
        }
    }

    return pop(&s);
}


int postfixevaluation(char *exp)
{
    int_stack s1;
    initIntStack(&s1);

    int i;
    for (i = 0; i < strlen(exp); i++)
    {
        if (exp[i] >= '0' && exp[i] <= '9')
        {
            push(&s1, exp[i] - '0');
        }
        else
        {
            int op2 = pop(&s1);
            int op1 = pop(&s1);

            switch (exp[i])
            {
            case '+':
                push(&s1, op1 + op2);
                break;

            case '-':
                push(&s1, op1 - op2);
                break;

            case '*':
                push(&s1, op1 * op2);
                break;

            case '/':
                push(&s1, op1 / op2);
                break;

            default:
                break;
            }
        }
    }
    return pop(&s1); // Return the final result
}

int main()
{
    char exp[100];
    char exp1[100];
    printf("Enter the prefix expression: ");
    scanf("%s", exp);
    printf("The prefix result is: %d\n", prefixevalution(exp));

    printf("Enter the postfix expression: ");
    scanf("%s", exp1);
    printf("The postfix result is: %d\n", postfixevaluation(exp1));

    return 0;
}
