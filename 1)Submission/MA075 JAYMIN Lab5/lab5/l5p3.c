#include<stdio.h>
#include<stdlib.h>
#include "stackint.c"
#define SIZE 5
void enqueue(int *que,int *front,int *rear,int data){

    if(*rear == SIZE - 1){
        printf("\nQueue is full!!");
        return;
    }
    *rear+=1;
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
void displayQue(int *q,int *front,int *rear){
    if(*front == -1){
        printf("\nQueue is empty!!");
        return;
    }
    printf("\nQueue:");
    for(int i=*front;i<=*rear;i++){
          printf(" %d | ",q[i]);
    }
    printf("\n");
}
void reverse(int *que,int *front,int *rear){
    if(*front == -1){
        printf("\nQueue is empty!!");
        return;
    }
    int stack[SIZE],t=-1;
    int *top=&t;
    for(int i=*front;i<=*rear;i++){
        push(stack,que[i],top);
    }
    *front=*rear=-1;
    for(int i=*top;i>=0;i--){
        enqueue(que,front,rear,stack[i]);
    }
//    printf("\ni=%d",pop(stack,top));
//     printf("\ni=%d",pop(stack,top));
//      printf("\ni=%d",pop(stack,top));
//       printf("\ni=%d",pop(stack,top));
    printf("\nNormal Queue Reversed !!\nCheck by Display Option.\n");
}
int main(){
    int queue[SIZE],f=-1,r=-1,item;
    int *front=&f;
    int *rear=&r;
    while(1){
        int ch;
        printf("\n:Menu:");
        printf("\n1.Insert\n2.delete\n3.display\n4.Reverse\n5.exit");
        printf("\nEnter Choice=");
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
                displayQue(queue,front,rear);
                break;
            case 4:
                reverse(queue,front,rear);
                break;
            case 5:
                exit(0);
            default :
                printf("\nPlease enter valid choice!!");
        }
    }
    return 0;
}
