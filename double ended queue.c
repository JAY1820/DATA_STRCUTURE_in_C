#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void enqueueFront(int *queue, int *rear, int data) {
    if (*rear == SIZE - 1) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    for (int i = *rear; i >= 0; i--) {
        queue[i + 1] = queue[i];
    }
    (*rear)++;
    queue[0] = data;
    printf("Enqueued element at the front: %d\n", data);
}

void enqueueRear(int *queue, int *rear, int data) {
    if (*rear == SIZE - 1) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    (*rear)++;
    queue[*rear] = data;
    printf("Enqueued element at the rear: %d\n", data);
}

int dequeueFront(int *queue, int *rear) {
    if (*rear == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int frontElement = queue[0];

    for (int i = 1; i <= *rear; i++) {
        queue[i - 1] = queue[i];
    }
    (*rear)--;
    printf("Dequeued element from the front: %d\n", frontElement);
    return frontElement;
}

int dequeueRear(int *queue, int *rear) {
    if (*rear == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int rearElement = queue[*rear];
    (*rear)--;
    printf("Dequeued element from the rear: %d\n", rearElement);
    return rearElement;
}

void display(int *queue, int rear) {
    if (rear == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = 0; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int queue[SIZE];
    int rear = -1;

    enqueueFront(queue, &rear, 1);
    enqueueFront(queue, &rear, 2);
    enqueueRear(queue, &rear, 3);
    enqueueRear(queue, &rear, 4);
    display(queue, rear); // Queue elements: 2 1 3 4

    int frontElement = dequeueFront(queue, &rear);
    printf("Front element: %d\n", frontElement); // Front element: 2

    int rearElement = dequeueRear(queue, &rear);
    printf("Rear element: %d\n", rearElement); // Rear element: 4

    display(queue, rear); // Queue elements: 1 3

    return 0;
}
