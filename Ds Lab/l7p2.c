#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertAtBeginning(struct Node **last, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (*last == NULL) {
        *last = newNode;
        newNode->next = *last;
    } else {
        newNode->next = (*last)->next;
        (*last)->next = newNode;
    }
}

void insertAtEnd(struct Node **last, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (*last == NULL) {
        *last = newNode;
        newNode->next = *last;
    } else {
        newNode->next = (*last)->next;
        (*last)->next = newNode;
        *last = newNode;
    }
}

void insertAfter(struct Node **last, int key, int data) {
    struct Node *newNode, *p;
    p = (*last)->next;
    do {
        if (p->data == key) {
            newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data = data;
            newNode->next = p->next;
            p->next = newNode;
            if (p == *last)
                *last = newNode;
            return;
        }
        p = p->next;
    } while (p != (*last)->next);
}

void deleteFirst(struct Node **last) {
    if (*last == NULL)
        return;

    struct Node *temp = (*last)->next;

    if ((*last)->next == *last) {
        free(temp);
        *last = NULL;
        return;
    }

    (*last)->next = temp->next;
    free(temp);
}

void deleteLast(struct Node **last) {
    if (*last == NULL)
        return;

    struct Node *temp, *p;

    if ((*last)->next == *last) {
        temp = *last;
        free(temp);
        *last = NULL;
        return;
    }

    p = (*last)->next;

    while (p->next != *last)
        p = p->next;

    temp = p->next;
    p->next = temp->next;
    free(temp);
}
void deleteNode(struct Node **last, int key) {
    if (*last == NULL)
        return;

    struct Node *temp, *p;

    if ((*last)->data == key) {
        temp = *last;

        if ((*last)->next == *last) {
            free(temp);
            *last = NULL;
            return;
        }

        p = (*last)->next;

        while (p->next != *last)
            p = p->next;

        p->next = temp->next;
        free(temp);
        return;
    }

    p = (*last)->next;

    while (p->next != *last) {
        if (p->next->data == key) {
            temp = p->next;
            p->next = temp->next;
            free(temp);
            return;
        }
        p = p->next;
    }
}

void display(struct Node *last) {
    struct Node *p;

    if (last == NULL) {
        printf("\nList is empty\n");
        return;
    }

    p = last->next;

    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != last->next);

    printf("\n");
}

int main() {
    struct Node *last = NULL;

    insertAtBeginning(&last, 12);
    insertAtBeginning(&last, 8);
    insertAtBeginning(&last, 6);

    display(last);

    insertAtEnd(&last, 24);
    insertAtEnd(&last, 20);

    display(last);

    insertAfter(&last, 8, 10);

    display(last);

    deleteFirst(&last);

    display(last);

    deleteLast(&last);

    display(last);

    deleteNode(&last, 10);

    display(last);

    return 0;
}
