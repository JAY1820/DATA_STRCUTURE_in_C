#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void bubble_sort(int arr[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
               int temp=arr[j];
               arr[j]=arr[j+1];
               arr[j+1]=temp;
            }
        }
    }
}

void insertion_sort(int arr[],int n)
{

    int i,j;
    for(i=1;i<n-1;i++)
    {
        int temp=arr[i];
        //make j =arr[0];
       for(j=i-1; j>=0 && temp[arr[j]]>temp; j--)
       {
           arr[j+1]=arr[j];
       }
         arr[j+1]=temp;

}
}

void selection_sort(int arr[], int n)
{
    int i, j;
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        { //swap
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

//lb is lower bound and ub is upper bound
int partition(int arr[],int lb,int ub)
{
   int pivot=arr[lb];
   int start=lb;
   int end =ub;
   while(start<end)
   {
       while (arr[start]<=pivot)
       {
                start++;
       }
       while (arr[end]>pivot)
       {
           end--;
       }
       //swap start and end
        if(start<end)
        {
            int temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
        }
   }
   //swap lb and end if start >end
   if(start>end)
   {
       int temp=arr[lb];
       arr[lb]=arr[end];
       arr[end]=temp;
   }
    return end;
} 

void quick_sort(int arr[],int lb,int ub)
{
     if(lb<ub)
     {
        int loc;  //give me the location of pivot element
        loc=partition(arr,lb,ub);
        quick_sort(arr,lb,loc-1);
        quick_sort(arr,loc+1,ub);
     }
} 


void merge_sort(int arr[],int lb,int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        merge_sort(arr,lb,mid);
        merge_sort(arr,mid+1,ub);
        merge(arr,lb,ub,mid);
    }
}

int merge(int arr[],int lb,int ub,int mid)
{
   int b[100];
   int i=lb;
   int j=mid+1;
   int k=lb; //fill in b

   while(i<=mid && j<=ub)
   {
       //left part chota hai to b[k] me arr[i] dal do
       if(arr[i]<arr[j]) 
       {
            b[k]=arr[i]; i++;
       }   else
       {
           b[k]=arr[j]; j++; 
       }
       k++;
   }
   //left part me kuch bacha hai to b me dal do
   if(i>mid)
   {
       while (j<=ub)
       {
           b[k]=arr[j]; j++; k++;
       }
       
   }
   //right part me kuch bacha hai to b me dal do
   else
   {
       while(i<=mid)
       {
           b[k]=arr[i]; i++; k++;
       }
   }
   //copy b to arr
    for(k=lb;k<=ub;k++)
    {
         arr[k]=b[k];
    }

}

int main()
{
   
    int arr[100];
    int size;
    printf("enter size of an array\n");
    scanf("%d",&size);
    for (int  i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
     }
    printf("bubble sort\n");
    // bubble_sort(arr,size);
    //    insertion_sort(arr,size);
       selection_sort(arr,size);
    //  quick_sort(arr,0,size-1);
    merge_sort(arr,0,size-1);

   printf("sorted array\n");
    for (int  i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}