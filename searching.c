#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void linear_search(int arr[],int n,int data)
{
  for(int i=0;i<n;i++)
  {
         if (arr[i]==data)
         {
            printf("element found at %d\n",i);
            return;
         }
  }
  printf("element not found\n");
}

void binary_search(int arr[],int n,int data)
{

   int left=0;
   int right=n-1;
   int mid;

   while(left<=right)
   {
      mid=(left+right)/2;
      if(data==arr[mid])
      {
        printf("element found at %d\n",mid);
        return;
      }
      else if(data<arr[mid]) 
      {
            right=mid-1;
      }
      else{
           left=mid+1;
      }

   }
      printf("element not found\n");
}

// int main()
// {
//     int arr[100];
//      printf("enter size of an array\n");
//         int n;
//         scanf("%d",&n);
//         int i;
//         for(i=0;i<n;i++)
//         {
//             scanf("%d",&arr[i]);
//         }
      
        
//         printf("enter the element to be searched\n");
//         int data;
//         scanf("%d",&data);
//         linear_search(arr,n,data);
//         printf("binary search\n");
//         binary_search(arr,n,data);

//     return 0;
// }