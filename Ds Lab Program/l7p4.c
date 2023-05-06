
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} Node;

Node *head = NULL;

void insertFirst(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    } else {
        Node *last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
}

void insertLast(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    } else {
        Node *last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
    }
}

void insertAt(int data, int position) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (position == 1) {
        insertFirst(data);
    } else {
        Node *temp = head;
        for (int i=1; i<position-1; i++) {
            temp=temp->next;
            if (temp == head) {
                printf("Invalid position\\n");
                return;
            }
        }
        Node *nextNode=temp->next;

        temp->next=newNode;
        nextNode->prev=newNode;

        newNode->prev=temp;
        newNode->next=nextNode;

    }
}

void deleteFirst() {
    if (head == NULL) {
        printf("List is empty\\n");
    } else if (head->next == head) {
        free(head);
        head=NULL;
    } else {
        Node *last=head->prev;

        last->next=head->next;
        head->next->prev=last;

        free(head);
        head=last->next;

    }
}

void deleteLast() {
    if (head == NULL) {
        printf("List is empty\\n");
    } else if (head->next == head) {
        free(head);
        head=NULL;
    } else {
      Node *last=head->prev;

      last->prev->next=head;
      head->prev=last->prev;

      free(last);
  }
}

void deleteAt(int position) {

  if (position == 1) {
      deleteFirst();
  } else {

      Node *temp=head;

      for (int i=1; i<position; i++) {

          temp=temp->next;

          if (temp == head) {
              printf("Invalid position\\n");
              return;
          }
      }

      temp->prev->next=temp->next;
      temp->next->prev=temp->prev;

      free(temp);

  }
}

void displayList() {

  if (head == NULL) {
      printf("List is empty\\n");
  } else {

      Node *temp=head;

      while(temp->next != head) {

          printf("%d ", temp->data);
          temp=temp->next;

      }

      printf("%d\\n", temp->data);

  }

}

int main() {
 printf("jaymin valaki: MAO75\n");
  insertFirst(10);
  insertFirst(20);
  insertLast(30);
  insertAt(40,2);
  displayList();
  printf("\ndisplay after delete");
  
  deleteFirst();
  deleteLast();
  printf("\n");
  deleteAt(2);
  printf("\n");
  displayList();

  return 0;

}
