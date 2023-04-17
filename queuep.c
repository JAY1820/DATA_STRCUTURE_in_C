#include<stdio.h>
#include<stdlib.h>
#define size 10

int queue[size];
int data;
int front=-1,rear=-1;
int *f=&front;
int *r=&rear;

void enqueue(int data)
{
if(rear==size-1) 
{
    printf("\n queue is full");
    return;
}
if(front==-1)
{
    front=0;
}
rear++;
queue[rear]=data;
}


int dequeue()
{
    int temp;
   if(front==-1) 
   {
    printf("your queue is empty\n");
    return -1; 
   }
   temp=queue[front]; //stote first value in temp for return
   if(front==rear) //if have only one element
   {
       front=rear=-1; 
   }
   else
   {
       front++; //increment the front
   }
   return temp; //return the dequeued element

}

void display()
{
     if(front==-1)
   {
    printf("your queue is empty\n");
    return;
   }
     printf("queue is:\n");

    for(int i=front;i<=rear;i++)
    {
          printf("%d | ",queue[i]);
    }
    printf("\n");

}


int main()
{
    enqueue(3);
    enqueue(5);
    enqueue(4);
    display();
    dequeue(); 
    display(); 
    return 0;   
}