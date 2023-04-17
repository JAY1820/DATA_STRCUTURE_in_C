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


int main() {
    
    int choice;
    int item;
    int pos;
   
    while (1) {
        printf("1. insertatfirst\n");
        printf("2. insertatend\n");
        printf("3. insertany\n");
        printf("4. deleteatfirst\n");
        printf("5. deleteatend\n");
        printf("6. deletespecific\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch (choice) {
            case 1:
                insertFirst();
                break;
           
            case 2:
                insertEnd();
                break;
           
            case 3:
                printf("give position:\n");
                scanf("%d",&pos);
                insertSpecific(pos);
                display();
                break;
            case 4:
                  deletefirst();
                break;
            case 5:
                  deleteend(); 
                break;
            
            case 6:
                printf("give position:\n");
                scanf("%d",pos);
                deletespecific(pos);
                display();
                break;
               
           case 7:
                     display();
                     break;
           case 8:
                exit(0);
                break;
            default:
                printf("Invalid choice!!\n");
                break;
            }
        }
    }
