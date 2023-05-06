#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "stackint.h"
#define MAX 10
int main(){
    char exp[10];
    int st[MAX];
    int tp = -1,i=0,num,operand1,operand2,ans;
    int *top=&tp;
    printf("Enter Postfix expression:");
    scanf("%s",exp);
    //push(st,')',top);
    //printf("%d\n",'0');
    while(exp[i] != '\0' ){

        if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' || exp[i]=='%'  ){
            operand1= pop(st,top);
            operand2= pop(st,top);
             switch (exp[i]) {
                case '+':
                    push(st,operand2 + operand1,top);
 break;
                case '-':
                    push(st,operand2 - operand1,top);
                    break;
                case '*':
                    push(st,operand2 * operand1,top);
                    break;
                case '/':
                    push(st,operand2 / operand1,top);
                    break;
                case '%':
                    push(st,operand2 % operand1,top);
                    break;
            }
        }
        else{
            num=exp[i] - 48;
            push(st,num,top);

        }
        i++;
    }
    //display(st,top);
    printf("Answer=%d",pop(st,top));
    return 1;
}