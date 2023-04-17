#include <stdio.h>
#include <stdlib.h>
#include "linklistint.h"

void deletenode(int pos)
{
    if (temp == head)
    {
        temp = head;

        head = temp->next;

        free(temp);
    }
    else
    {
        int count=0;
        temp = head;
        while (temp->next != NULL && count!=pos)
        {
            count++;
            temp = temp->next;
        }
        temp->next = temp->next->next;
    }
}



int main() {
    insertEnd(1);
    insertEnd(2);
    insertEnd(3);
    insertEnd(1);
    insertEnd(4);
    insertEnd(2);
    insertEnd(5);

    display();


    struct node *current = head;
    while (current != NULL) 
    {
        struct node *temp = current;
        while (temp->next != NULL) 
        {
            if (temp->next->data == current->data) 
            {
                struct node *duplicate = temp->next;
                deletenode(duplicate);
            } else {
                temp = temp->next;
            }
        }
        current = current->next;
    }

    display();

    return 0;
}