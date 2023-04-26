#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int data)
{
    if (rear == SIZE - 1)
    {
        printf("\nQueue is full!!");
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    rear++;
    queue[rear] = data;
}

int dequeue()
{
    int temp;
    if (front == -1)
    {
        printf("\nQueue is empty");
        return -1;
    }

    temp = queue[front];
    if (front >= rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front += 1;
    }
    return temp;
}


int isEmpty()
{
    return front == -1;
}