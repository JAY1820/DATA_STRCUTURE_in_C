#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int data)
{
    if ((rear + 1) % SIZE == front)
    {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    rear = (rear + 1) % SIZE;
    queue[rear] = data;
    printf("Enqueued element: %d\n", data);
}

int dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int data = queue[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
    printf("Dequeued element: %d\n", data);
    return data;
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements:\n");
    int i = front;
    while (i != rear)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % SIZE;
    }
    printf("%d\n", queue[rear]);
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
