#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
void Enqueue(int *que,int *front,int *rear,int data){
    if(*front == (*rear + 1)%SIZE){
        printf("\nQueue is full!!\n");
        return;
    }
    else{
        *rear=(*rear+1)%SIZE;
        que[*rear]=data;
    }
    if(*front==-1){
        *front=0;
    }

}
int Dequeue(int *que,int *front,int *rear){
    if(*front == -1 && *rear == -1 ){
        printf("\nQueue is Empty!!\n");
        return -1;
    }
    int temp=que[*front];
    if(*front == *rear){
        *front=-1;
        *rear=-1;
    }
    else{
        *front=(*front+1)%SIZE;
    }
    return temp;
}
void display(int *que,int *front,int *rear){
    if(*front == -1 && -1 == *rear){
        printf("Queue is empty");
        return;
    }
    printf("\n Circular Queue:");
    for(int i=*front;i!=*rear;i=(i+1)%SIZE){
        printf(" %d |",que[i]);
    }
    printf(" %d |\n",que[*rear]);
}
int main(){
    int que[SIZE],*front,f=-1,r=-1,*rear;
    front=&f;
    rear=&r;
    int ch,item;

    while(1){

        printf("\n:Menu:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice=");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("\nEnter Item:");
                scanf("%d",&item);
                Enqueue(que,front,rear,item);
                break;
            case 2:
                printf("Dequeued Item:%d",Dequeue(que,front,rear));
                break;
            case 3:
                display(que,front,rear);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nEnter Valid choice!!\n");
        }
    }
    return 1;
}
