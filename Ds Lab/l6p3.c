#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"

void sortList();
int main()
{
   struct node *tail=NULL;
	insertFirst();
    insertFirst();
    insertFirst();
    display();
	sortList();
	display();
	return 0;
}

void sortList()
{
	struct node *temp=head, *temp1=NULL;
    //temp1 is temprory
	int item;
	if(head==NULL)
	{
		return;
	}

	else
	{
		while(temp!=NULL)
		{
			temp1=temp->next;
			while(temp1!=NULL)
			{
				if(temp->data > temp1->data)
				{
					item=temp->data;
					temp->data= temp1->data;
					temp1->data=item;
				}
				temp1=temp1->next;
			}
			temp=temp->next;
		}
	}
}
