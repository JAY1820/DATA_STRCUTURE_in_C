#include<stdio.h>
#include<stdlib.h>
#include "cqueue.h"
#define size 10


int main()
{
    void* queue[size]; 
    int front=-1,rear=-1;
    int choice; 
    void* data; 
    while(1) 
    {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice); 
        switch(choice) 
        {
            case 1: 
                printf("Enter the data: ");
                scanf("%d",&data); 
                enqueue(queue,&front,&rear,data); 
                break;
            case 2: 
                data=dequeue(queue,&front,&rear); 
                if(data!=NULL) 
                {
                    printf("The dequeued element is: %d\n",data); 
                }
                break;
            case 3: 
                display(queue,&front,&rear); //pass the queue, front and rear by reference
                break;
            case 4: 
                printf("Thank you for using this program.\n");
                exit(0); 
            default: 
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;   
}