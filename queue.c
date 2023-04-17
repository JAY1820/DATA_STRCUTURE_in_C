#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

void enqueue(int *que,int *front,int *rear,int data){

    if(*rear == SIZE - 1){
        printf("\nQueue is full!!");
        return;
    }
    (*rear)++;
    que[*rear]=data;
    if(*front == -1){
        *front=0;
    }
}

int dequeue(int *q,int *front,int *rear){
    int temp;
    if(*front == -1){
        printf("\nQueue is empty");
        return -1;
    }
    temp=q[*front];
     if(*front >= *rear ){
        *front=-1;
        *rear=-1;
    }
    else{
        *front+=1;
    }
    return temp;
}

void display(int *q,int *front,int *rear){
    if(*front == -1){
        printf("\nQueue is empty!!");
        return;
    }
    printf("\nQueue:");
    for(int i=*front;i<=*rear;i++){
          printf("%d | ",q[i]);
    }
    printf("\n");
}

int main()
{
    int queue[SIZE],f=-1,r=-1,item;
    int *front=&f;
    int *rear=&r;
    while(1){
        int ch;
        printf("\n:Menu:");
        printf("\n1.Insert\n2.delete\n3.display\n4.exit");
        printf("\nEnter Choice Number=");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("\nEnter Item:");
                scanf("%d",&item);
                enqueue(queue,front,rear,item);
                break;
            case 2:
                    printf("Deleted Item:%d",dequeue(queue,front,rear));
                break;
            case 3:
                display(queue,front,rear);
                break;
            case 4:
                exit(0);
            default :
                printf("\nPlease enter valid choice!!");
        }
    }
    return 0;
}
