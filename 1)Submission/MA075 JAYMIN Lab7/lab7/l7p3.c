#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *prev, *next;
};
struct node* head = NULL;
struct node* tail = NULL;
void insertFront()
{
	int val;
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf(" Enter value= ");
	scanf("%d",&val);
	temp->data=val;
	temp->prev=NULL;
	temp->next=head;
	head=temp;
}
void insertEnd()
{
	int val;
	struct node *temp, *trav;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->prev=NULL;
	temp->next=NULL;
	printf(" Enter value= ");
	scanf("%d",&val);
	temp->data=val;
	temp->next=NULL;
	trav=head;
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		while(trav->next!=NULL)
		{
			trav = trav->next;
		}
		temp->prev=trav;
		trav->next=temp;
	}
}
void insertPosition()
{
	int val,pos,i=1;
	struct node *temp, *newnode;
	newnode=malloc(sizeof(struct node));
	newnode->next=NULL;
	newnode->prev=NULL;
	printf("Enter position= ");
	scanf("%d",&pos);
	printf("Enter value= ");
	scanf("%d",&val);
	newnode->data=val;
	temp=head;
	if(head==NULL)
	{
		head=newnode;
		newnode->prev=NULL;
		newnode->next=NULL;
	}
	else if(pos==1)
	{
		newnode->next=head;
		newnode->next->prev=newnode;
		newnode->prev=NULL;
	head=newnode;
	}
	else
	{
		while(i<pos-1)
		{
			temp = temp->next;
			i++;
		}
		newnode->next=temp->next;
		newnode->prev=temp;
		temp->next=newnode;
		temp->next->prev=newnode;
	}
}
void deleteFirst()
{
	struct node* temp;
	if(head==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		temp=head;
		head=head->next;
		if(head!=NULL)
		{
			head->prev=NULL;
		}
		free(temp);
	}
}
void deleteEnd()
{
	struct node* temp;
	if(head==NULL)
	{
		printf("List is empty\n");
	}
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	if(head->next==NULL)
	{
		head=NULL;
	}
	else
	{
		temp->prev->next=NULL;
		free(temp);
	}
}
void deletePosition()
{
	int pos,i=1;
	struct node *temp, *position;
	temp=head;
	if(head==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		printf("Enter position= ");
		scanf("%d",&pos);
		if(pos==1)
		{
			position=head;
			head=head->next;
			if(head!=NULL)
			{
				head->prev=NULL;
			}
			free(position);
		return;
		}
		while(i<pos-1)
		{
			temp=temp->next;
			i++;
		}
		position=temp->next;
		if(position->next!=NULL)
		{
			position->next->prev=temp;
		}
		temp->next=position->next;
		free(position);
	}
}
void display()
{
	struct node* temp;
	if(head==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		printf("ELement= ");
		temp=head;
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
int main()
{
	int choice;
	while (1)
	{
		printf("\n------------Doubly Linked List-----------\n");
		printf("\nPress 1. For Insert at first");
		printf("\nPress 2. For Insert at end ");
		printf("\nPress 3. For Insert at desired location");
		printf("\nPress 4. For Delete at first");
		printf("\nPress 5. For Delete at end");
		printf("\nPress 6. For Delete at desired location");
		printf("\nPress 7. For Display the list");
		printf("\nEnter Choice= ");
		scanf("%d",&choice);
		printf("\n");
		switch(choice)
		{
			case 1: insertFront();
					break;
			case 2: insertEnd();
					break;
			case 3: insertPosition();
					break;
			case 4: deleteFirst();
					break;
			case 5: deleteEnd();
					break;
			case 6: deletePosition();
					break;
			case 7: display();
					break;
			default: printf("Invalid Choice");
					break;
		}
	}
	return 0;
}

