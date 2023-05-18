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

void BFS(int A[][8], int start, int n)
{
    int i = start, v;
    int visited[8] = {0};
    printf("%d ", i);
    visited[i] = 1;
    enqueue(i);

    while (!isEmpty())
    {
        i = dequeue();

        for (v = 1; v <= n; v++)
        {
            if (A[i][v] == 1 && visited[v] == 0)
            {
                printf("%d ",v);
                visited[v] = 1;
                enqueue(v);
            }
        }
    }
}

void DFS(int A[][8],int start,int n)
{
    static int visited[]={0};
    int v;
    int i=start;
    
    if(visited[i]==0)
 {
 printf("%d ",start);
 visited[i]=1;

 for(v=1;v<n;v++)
 {
 if(A[i][v]==1 && visited[v]==0)
 DFS(A,v,n);
 }
 }
}

int main()
{

    //adjacency matrix of graph 5  by 5
    int A[5][5]= {{0,0,0,0,0},
                  {0,0,1,1,0},
                  {0,1,0,0,1},
                  {0,1,0,0,1},
                  {0,0,1,1,0}};

    

    BFS(A, 1, 5);
    printf("\n");
    DFS(A,2,5);

    return 0;
}