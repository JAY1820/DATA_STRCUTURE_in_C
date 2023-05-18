#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "int_stack.h"

#define MAX_SIZE 100

char *infixtopostfix(char *exp)

{
    int_stack s1;
    initIntStack(&s1);
    char *result = (char *)malloc(sizeof(char) * (strlen(exp) + 1));

    int i = 0, j = 0;
    for (i = 0; i < strlen(exp); i++)
    {
        // if not operator then print into result
        if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z'))
        {
            result[j++] = exp[i];
        }

        
        // if operning bracket then push into stack
        else if (exp[i] == '(')
        {
            push(&s1, exp[i]);
        }

        // if is closing brecket and stack is not empty then pop all the element until we get opening brecket
        else if (exp[i] == ')')
        {
            while (!isEmpty(&s1) && peek(&s1) != '(')
            {
                result[j++] = pop(&s1);
            }

            if (!isEmpty(&s1))
            {
                pop(&s1); // pop opening brecket
            }
        }

        else
        {
            //precedence of top of stack is greater than or equal to current operator then pop
          
            while (!isEmpty(&s1) && precedence(exp[i]) <= precedence(peek(&s1)))
            {
                result[j++] = pop(&s1);
            }
            push(&s1, exp[i]);
        }
    }
//check karega empty hai ya nahi stack
    while (!isEmpty(&s1))
    {
        result[j++] = pop(&s1);
    }

    result[j] = '\0';

    return result;
}


int main()
{
   //(a-b/c)*(a/k-l)
   printf("Enter the infix expression: ");
    char exp[MAX_SIZE];
    scanf("%s", exp);
    printf("Infix Expression: %s\n", exp);
    printf("Postfix Expression: %s\n", infixtopostfix(exp));
    
    return 0;
}