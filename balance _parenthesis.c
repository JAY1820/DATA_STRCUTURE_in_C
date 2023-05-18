#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "int_stack.h"


void balance(char *exp)
{
   int_stack s1;
    initIntStack(&s1);
    int i;
   for ( i = 0; i < strlen(exp); i++)
   {
       if(exp[i]=='(' || exp[i]=='{'|| exp[i]=='[')
       {
        push(&s1,exp[i]);

       }
         else if(exp[i]==')' || exp[i]=='}'|| exp[i]==']')
         {
              if(isEmpty(&s1))
              {
                printf("not balance\n");
                return;
              }

              else if(exp[i]==')' && peek(&s1)!='(')
              {
                printf("not balance\n");
                return;
              }

              else if(exp[i]=='}' && peek(&s1)!='{')
              {
                printf("not balance\n");
                return;
              }

              else if(exp[i]==']' && peek(&s1)!='[')
              {
                printf("not balance\n");
                return;
              }

              else
              {
                pop(&s1);
              }
              
         }
       
   }
   
}

int main()
{

 printf("enter the string\n");
 char exp[MAX_SIZE];
 scanf("%s",exp);
 printf("balance string is is %s\n",prefix);

 return 0;
}


