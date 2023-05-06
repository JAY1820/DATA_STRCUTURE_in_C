#include <stdio.h>
#include <stdlib.h>
#include "linklistint.h"

int main(int argc, char *argv[])
{
    struct node *slow = head;
    struct node *fast = head;

     if (argc != 31)
    {
        printf("Please give proper input.\n");
        return 1;
    }

    for (int i = 1; i < argc; i++)
    {
        int value = atoi(argv[i]);
        insertEnd(value);
    }

   

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("middle element is  %d\n", slow->data);

    
    
    return 0;
}