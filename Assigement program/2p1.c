#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "linklistint.h"

void Subsets(struct node *head,int no) {
    int subset[no];
        for (int i = 0; i < pow(2,no); i++) 
        {
        temp = head;
        printf("{");
        for (int j = 0; j < no; j++) 
        { 
              // 0/ 2^0 % 2 = 0/ 1%2 = ans is 1 so condtion true and print data
             if ((i / (int)pow(2,j)) % 2 == 1) {
                printf("%d ", temp->data);
            }
            
            temp = temp->next;
        }
        
        printf("}\n");
    }
}

int main() {
    int no;
    int loop = 0;
    
    printf("give the total np of elements in the set: ");
    scanf("%d", &no);
    printf("Enter the elements: "); 

    for (int i = 0; i < no; i++)
    {
         int data;
        scanf("%d", &data);
        insertEnd(data);
    }
    display();

    printf("Set: ");
    display();
    
    printf("\nSubsets:\n");
    
    Subsets(head,no);

    return 0;
}