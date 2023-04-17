#include<stdio.h>
#include<stdlib.h>
#include "linklist.h"


void reverse() {
    struct node *prev = NULL;
    struct node *next = NULL;
    struct node *temp = head;
    
    while(temp != NULL) {
        next = temp->next;
        temp->next = prev;  //prev is null
        prev = temp;
        temp = next;
    }
    head = prev;
}

int main()
{
   
    insertEnd();
    insertEnd();
    insertEnd();
    display();
    reverse();
    display();
    

}
