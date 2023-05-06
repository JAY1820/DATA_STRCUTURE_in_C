#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof( Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void insertNode(Node** head, int data) {
     Node* node = newNode(data);
    if (*head == NULL) {
        *head = node;
    } else {
         Node* curr = *head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = node;
    }
}

void displayList( Node* head) {
    printf("{ ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("} ");
}

void Recursion( Node* head,  Node* subset) {
    if (head == NULL) {
        printf("{ ");
        displayList(subset);
        printf("}\n");
        return;
    }
     Node* copy = newNode(head->data);
    copy->next = subset;
    Recursion(head->next, copy);
    Recursion(head->next, subset);
}

void SubSet( Node* head) {
    Node* subset = NULL;
    Recursion(head, subset);
}

int main() {
    Node* create = NULL;
    insertNode(&create, 4);
    insertNode(&create, 5);
    insertNode(&create, 6);
    printf("Set: ");
    displayList(create);
    printf("Subsets:\n");
    SubSet(create);
    return 0;
}
