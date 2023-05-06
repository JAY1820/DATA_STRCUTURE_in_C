#include <stdio.h>
#include <stdlib.h>
#include "linklistint.h"


void removeDuplicates() {
    struct node *current = head;
    while (current != NULL) {
        struct node *temp = current;
        while (temp->next != NULL) {
            if (temp->next->data == current->data) {
                deletenode(temp->next);
            } else {
                temp = temp->next;
            }
        }
        current = current->next;
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

    removeDuplicates();

    display();

    return 0;
}