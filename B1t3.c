/*

Write a Program to Reverse a Linked List in groups of given size
Given a linked list, write a function to reverse every k node (where k is an input to the
function).
Example:
Input: 1->2->3->4->5->6->7->8->NULL, K = 3
Output: 3->2->1->6->5->4->8->7->NULL
Input: 1->2->3->4->5->6->7->8->NULL, K = 5
Output: 5->4->3->2->1->8->7->6->NULL ]


*/

#include<stdio.h>
#include<stdlib.h>
#include "linklist_term.h"

struct node* reverse1(struct node* head, int k) {
    struct node* temp = head;
    struct node* next = NULL;
    int count = 0;
    struct node* prev = NULL;
  
    while (temp != NULL && count < k) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
        count++;
        printf(next %d\n", next->data");
    }    

    if (next != NULL) {
        head->next = reverse1(next, k);
    }
    return prev;
}

int main() {
    struct node* head = NULL;
    int n, k;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter the data: ");
        scanf("%d", &data);
        insertEnd(&head, data);
    }

    printf("Enter the value of k: ");
    scanf("%d", &k);
    head = reverse1(head, k);
    
    printf("Reversed linked list:\n");
    display(head);

    return 0;
}
