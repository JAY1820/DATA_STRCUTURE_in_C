#include<stdio.h>
#include<stdlib.h>
#include "queue.h"
#define size 10

int main()
{
  int queue[size];
  int f=-1,r=-1,item;
    int *front=&f;
    int *rear=&r;
    enqueue(queue,front,rear,5);
    enqueue(queue,front,rear,10);
    enqueue(queue,front,rear,15);
    enqueue(queue,front,rear,20);
    display(queue,front,rear);
    dequeue(queue,front,rear); 
    display(queue,front,rear);

}