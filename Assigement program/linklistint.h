#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *newnode, *temp;

void create(int data) {
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("No memory\n");
        exit(0);
    }
    newnode->data = data;
    newnode->next = NULL;
}

void insertEnd(int data) {
    create(data);
    if (head == NULL) {
        head = newnode;
        return;
    }
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void insertFirst(int data) {
    create(data);
    if (head == NULL) {
        head = newnode;
        return;
    }
    newnode->next = head;
    head = newnode;
}

void insertSpecific(int pos, int data) {
    if (pos == 1) {
        insertFirst(data);
        return;
    }
    
    int count = 1;
    
    temp = head;
    
    while (temp != NULL && count < pos - 1) {
        count++;
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    
    create(data);
    
    newnode->next = temp->next;
    temp->next = newnode;
}





void deletenode(struct node *del) {
    struct node *temp = head;
    if (head == del) {
        head = del->next;
    } else {
        while (temp->next != del) {
            temp = temp->next;
        }
        temp->next = del->next;
    }
    free(del);
}


void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    temp = head;
    
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    
    printf("\n");
}