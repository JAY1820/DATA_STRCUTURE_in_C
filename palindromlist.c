#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    char data;
    struct node *next;
} *head = NULL, *temp, *newnode;

void create() {
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("No memory\n");
        exit(0);
    }
    newnode->next = NULL;
    scanf(" %c", &newnode->data);
}

void insertEnd() {
    create();
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

void display() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        temp = head;
        while (temp != NULL) {
            printf("%c-> ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

bool isPalindrome(struct node *head) {
    int length = 0;
    struct node *temp = head;
    
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    
     char *arr = (char *)malloc(length * sizeof(char));
    temp = head;
    for (int i = 0; i < length; i++)
    
    {
        arr[i] = temp->data;
        temp = temp->next;
    }
    
    for (int i = 0; i < length / 2; i++)
    {
        if (arr[i] != arr[length - i - 1]) 
        {
            free(arr);
            return false;
        }
    }
    free(arr);
    return true;
}

int main() {
    insertEnd();
    insertEnd();
    insertEnd();
    display();

    bool result = isPalindrome(head);
    if (result) {
        printf("The linked list is a palindrome\n");
    } else {
        printf("The linked list is not a palindrome\n");
    }

    display();
}