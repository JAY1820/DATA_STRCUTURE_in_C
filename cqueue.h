#include<stdio.h>
#include<stdlib.h>
#define size 10

void enqueue(void* queue[], int *front, int *rear, void* data) 
{
if((*rear+1)%size==*front) //changed rear and front to pointers
{
    printf("\n queue is full");
    return;
}
if(*front==-1) 
{
    *front=0;
}
*rear=(*rear+1)%size; //changed rear to pointer and incremented it
queue[*rear]=data; //changed rear to pointer
}


void* dequeue(void* queue[], int *front, int *rear) 
{
    void* temp; 
   if(*front==-1) 
   {
    printf("your queue is empty\n");
    return NULL; 
   }
   temp=queue[*front]; 
   if(*front==*rear) 
   {
       *front=*rear=-1; 
   }
   else
   {
       *front=(*front+1)%size; //changed front to pointer and incremented it
   }
   return temp; 

}

void display(void* queue[], int *front, int *rear) 
{
     if(*front==-1) 
   {
    printf("your queue is empty\n");
    return;
   }
     printf("queue is:\n");

    for(int i=*front;i!=*rear;i=(i+1)%size) 
    {
          printf("%d | ",queue[i]); 
    }
    printf("%d | ",queue[*rear]); 
    printf("\n");

}
