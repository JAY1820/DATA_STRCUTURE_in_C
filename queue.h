#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

void enqueue(int *que,int *front,int *rear,int data){

    if(*rear == SIZE - 1){
        printf("\nQueue is full!!");
        return;
    }
     if(*front == -1){
        *front=0;
    }
    (*rear)++;
    que[*rear]=data;

   
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

    printf("\nQueue is:");
    for(int i=*front;i<=*rear;i++){
          printf("%d | ",q[i]);
    }
    printf("\n");
}


int isEmpty()
{
    return front == NULL;
}