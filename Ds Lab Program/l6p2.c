#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

int peep();
void change(int x,int y);

int main()
{
    insertFirst();
    insertFirst();
    insertFirst();
    insertFirst();
    display();
    deletefirst();
    display();
    peep();
    change(2,4);
    return 0;
}

int peep()
{
    if (head == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    printf("Value is: %c\n",head->data);
    return head->data;
    
}
void change(int pos,int val)
{
	int cnt = 1;
	temp=head;
	while(temp->next!=NULL&&cnt!=pos)
	{
		cnt++;
		temp=temp->next;
	}
	temp->data=val;
}