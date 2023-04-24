#include <stdio.h>
#include <stdlib.h>
#include "linklistint.h"

struct node {
    int data;
    struct node *next;
};

struct node *create(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("No memory\n");
        exit(0);
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insertEnd(struct node **head, int data) {
    struct node *newnode = create(data);
    if (*head == NULL) {
        *head = newnode;
        return;
    }
    struct node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void display(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct node *merge(struct node *head1, struct node *head2) {
    struct node *temp, *head;

    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;

    if (head1->data < head2->data) {
        head = head1;
        head1 = head1->next;
    } else {
        head = head2;
        head2 = head2->next;
    }

    temp = head;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            temp->next = head1;
            head1 = head1->next;
        } else {
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }

    if (head1 != NULL)
        temp->next = head1;
    else
        temp->next = head2;

    return head;
}

int main(int argc, char *argv[]) {
    struct node *head1 = NULL, *head2 = NULL, *merged_list = NULL;
    int i, num;

    // Divide the command line arguments equally into two unsorted lists
    for (i = 1; i <= 10; i++) {
        num = atoi(argv[i]);
        insertEnd(&head1, num);
    }
    for (i = 11; i <= 20; i++) {
        num = atoi(argv[i]);
        insertEnd(&head2, num);
    }

    printf("First list: ");
    display(head1);

    printf("Second list: ");
    display(head2);

    merged_list = merge(head1, head2);
    printf("Merged list: ");
    display(merged_list);

    return 0;
}
