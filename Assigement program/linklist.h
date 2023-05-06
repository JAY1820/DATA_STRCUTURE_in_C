#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    struct node *next;
};

struct node *head = NULL;
struct node *newnode, *temp;

void create(char data) {
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("No memory\n");
        exit(0);
    }
    newnode->data = data;
    newnode->next = NULL;
}

void insertEnd(char data) {
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

void insertFirst(char data) {
    create(data);
    if (head == NULL) {
        head = newnode;
        return;
    }
    newnode->next = head;
    head = newnode;
}

void insertSpecific(int pos, char data) {
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

void deleteFirst() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    temp = head;
    
    head = temp->next;
    
    free(temp);
}

void deleteEnd() {
     if (head == NULL) {
        printf("List is empty\n");
        return;
     }
     
     if (head->next == NULL) {
         free(head);
         head = NULL;
         return;
     }
     
     temp = head;
     
     while (temp->next->next != NULL) {
         temp = temp->next;
     }
     
     free(temp->next);
     
     temp->next = NULL;
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    temp = head;
    
    while (temp != NULL) {
        printf("%c -> ", temp->data);
        temp = temp->next;
    }
    
    printf("\n");
}

void deletespecific(int pos)
{
    int count=1;
    if(pos==1)
    {
        deletefirst();
    }
    else{
        temp=head;
        while(temp->next!=NULL && count!=pos)
        {
            count++;
            temp=temp->next;
        }
            temp->next=temp->next->next;
    }
}

void reverse() {
    struct node *prev = NULL;
    struct node *next = NULL;
    struct node *temp = head;
    
    while(temp != NULL) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    head = prev;
}