#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node *front=NULL;
struct node *rear=NULL;
void enqueue(int data);
void dequeue();
void display();
int main()
{
	int choice,val;
	while(1)
	{
		printf("\nPress 1. For Insert data in Queue");
		printf("\nPress 2. For Delete data From Queue");
		printf("\nPress 3. For Display Elements Of Queue");
		printf("\nPress 4. For Exit");
		printf("\nEnter Your Choice= ");
		scanf("%d",&choice);
		printf("\n");
		switch(choice)
		{
			case 1: printf("Enter value= ");
			scanf("%d",&val);
			enqueue(val);
			break;
			case 2: dequeue();
			break;
			case 3: display();
			break;
			case 4: exit(0);
			default: printf("Invalid choice");
			break;
	}
}
	return 0;
}
void enqueue(int value)
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=value;
	temp->next=NULL;
	if((front==NULL)&&(rear==NULL))
	{
		front=rear=temp;
		rear->next=front;
	}
	else
	{
		rear->next=temp;
		rear=temp;
		temp->next=front;
	}
}
void dequeue()
{
	struct node* temp;
	temp=front;
	if((front==NULL)&&(rear==NULL))
	{
		printf("Queue is Empty\n");
	}
	else if(front==rear)
	{
		front=rear=NULL;
		free(temp);
	}
	else
	{
		front=front->next;
		rear->next=front;
		free(temp);
	}
}
void display()
{
	struct node* temp;
	temp=front;
	if((front==NULL)&&(rear==NULL))
	{
		printf("Queue is Empty\n");
	}
	else
	{
		printf("Elements= ");
	do
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}while(temp!=front);
	printf("\n");
	}
}
