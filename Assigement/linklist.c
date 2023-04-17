#include <stdio.h>
#include <stdlib.h>
struct node
{
    char data;
    struct node *next;
} *head = NULL, *temp, *newnode;

void create()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    newnode->next = NULL;
    scanf(" %c", &newnode->data);
}

void insertFirst()
{
    create();
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    newnode->next = head;
    head = newnode;
}

void insertEnd()
{
    create();
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void insertSpecific(int pos)
{
    struct node *pred;
    int count=1;
    if (pos == 1)
    {
        insertFirst();
    }
    else
    temp = head;
    {
        while (temp->next != NULL && count != pos)  //insertend condtion check
        {
            count++;
            temp = temp->next;
        }
        create();
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void deletefirst()
{
    
    if(head==NULL)
    {
        printf("list is empty\n");
    }
    
    else{
        temp=head;
        head=temp->next;
        free(temp);
    }
}

void deleteend()
{
   struct node *previous;   
     if(head==NULL)
    {
        printf("list is empty\n");
    }
    else{
        temp=head;
        
     while (temp->next != NULL)
    {
      previous = temp;
      temp = temp->next;
    }
    previous->next = NULL;
    free(temp);
    }
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

void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("%c-> ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}


int main()
{
    insertFirst();
    insertFirst();
    insertFirst();
    insertEnd();
    insertSpecific(3);
    display();
    deleteend();
    display();
    return 0;
}