#include<stdio.h>
#include<stdlib.h>
#define size 5

int queue[size];
int data;
int front=-1,rear=-1;
int *f=&front;
int *r=&rear;


void enqueue(int data)
{
if((rear+1)%size==front) //changed the condition to check for full queue
{
    printf("\n queue is full");
    return;
}
if(front==-1)
{
    front=0;
}
rear=(rear+1)%size; //changed the increment to wrap around
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
   temp=queue[front]; 
   
   if(front==rear) //if have only one element
   {
       front=rear=-1; 
   }
   else
   {
       front=(front+1)%size; //changed the increment to wrap around
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

    for(int i=front;i!=rear;i=(i+1)%size) 
    {
          printf("%d | ",queue[i]);
    }
    printf("%d | ",queue[rear]); 
    printf("\n");

}


int main()
{
    enqueue(3);
    enqueue(5);
    enqueue(4);
    display();
    enqueue(3);
    enqueue(6);
    display();
    dequeue();
    enqueue(7);
    display();
    
    return 0;   
}