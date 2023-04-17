

#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prev;
    char data;
    struct node *next;
}*newnode,*head=NULL,*temp;

void create()
{
    newnode= (struct node *) malloc(sizeof(struct node));
     if (newnode == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    newnode->prev=NULL;
    newnode->next = NULL;
    scanf(" %c", &newnode->data);
}

void insertfirst() 
{
    create();
    if(head == NULL) {
        head = newnode;
        return;
    }
   
    newnode->next = head; //store head address in new node
    head = newnode; 
}

void insertend()
{
    create();
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    
    temp = head; 
    while(temp->next != NULL) 
    {
        temp = temp->next; 
    }
    temp->next = newnode; //newnode address is 500 it store temp
    newnode->prev = temp; // link newnode to last node (400)
}

void display()
{
     if (head == NULL)
     {
         printf("List is empty\n");
         return;
     }
     
     temp=head;
     while (temp != NULL)
     {
         printf("%c -> ", temp->data);
         temp = temp->next;
     }
     printf("\n");
}

void deleteend()
{
    struct node *temp1;
     if (head == NULL)
     {
         printf("List is empty\n");
         return;
     }
       temp=head;
     while (temp->next != NULL)
     {
         temp = temp->next;
     }   
     temp1=temp->prev;
     temp->prev=NULL;
     temp=temp1;
     temp->next=NULL;
     free(temp1);
}

void deletefirst()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    
    temp = head;
    head = head->next;
    
    if(head != NULL) {
        head->prev = NULL;
    }
    
    free(temp);
}

int main()
{
   insertfirst();
   display();
   insertend();
   insertend();
   display();
   insertfirst();
   insertfirst();
   display();
//   deleteend();
//   display();
   deletefirst();
   display();

   return 0;
}