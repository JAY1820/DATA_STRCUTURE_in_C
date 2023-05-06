#include <stdio.h>
#include "linklistint.h"

int main(int argc, char *argv[]) {
    if (argc != 31) {
        printf("Please enter 30 integers as command line arguments.\n");
        return 1;
    }

    struct node *head = NULL;
    for (int i = 1; i < argc; i++) {
        int value = atoi(argv[i]);
        head == insertEnd(value);
    }

    struct node *slow = head;
    struct node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("The middle element is %d\n", slow->data);

    return 0;
}