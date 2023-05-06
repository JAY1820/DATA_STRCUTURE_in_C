#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteDuplicates(Node* head) {
    Node* first = head;
    while (first != NULL) {
        Node* second = first;
        while (second->next != NULL) {
            if (first->data == second->next->data) {
                Node* temp = second->next;
                second->next = second->next->next;
                free(temp);
            } else {
                second = second->next;
            }
        }
        first = first->next;
    }
}

int main() {
    Node* head = NULL;
    insertNode(&head, 4);
    insertNode(&head, 7);
    insertNode(&head, 9);
    insertNode(&head, 11);
    insertNode(&head, 9);
    insertNode(&head, 4);
    printf("Original Linked List: ");
    printList(head);
    deleteDuplicates(head);
    printf("Linked List after removing duplicates: ");
    printList(head);
    return 0;
}
