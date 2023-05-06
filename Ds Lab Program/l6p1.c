#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

int main() {
    
    int choice;
    int pos;
   
    while (1) {
        printf("1. insertatfirst\n");
        printf("2. insertatend\n");
        printf("3. insertany\n");
        printf("4. deleteatfirst\n");
        printf("5. deleteatend\n");
        printf("6. deletespecific\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch (choice) {
            case 1:
                insertFirst();
                break;
           
            case 2:
                insertEnd();
                break;
           
            case 3:
                printf("give position:\n");
                scanf("%d",&pos);
                insertSpecific(pos);
                // display();
                break;
            case 4:
                  deletefirst();
                break;
            case 5:
                  deleteend(); 
                break;
            
            case 6:
                printf("give position:\n");
                scanf("%d",&pos);
                deletespecific(pos);
                display();
                break;
               
           case 7:
                     display();
                     break;
           case 8:
                exit(0);
                break;
            default:
                printf("Invalid choice!!\n");
                break;
            }
        }
    }
