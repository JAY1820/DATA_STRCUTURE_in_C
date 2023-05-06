
void create(linklist *l1,int data))
{
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    newnode->next = NULL;
    scanf(" %c", &newnode->data);
}

void insertFirst(linklist *l1,int data))
{
    create();
    if (head == NULL)
    {
        head = temp= newnode;
        return;
    }
    else{
    temp->next =newnode;
    temp = newnode;
    }
    temp->next=head;
}

void insertEnd(linklist *l1,int data))
{
    create();
    if (head == NULL)
    {
        head = newnode;
        head->next = head;
        return;
    }
    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
}

void deletefirst(linklist *l1)
{
    struct node *temp1;
    if(head==NULL)
    {
        printf("list is empty\n");
    }
    
    else{
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        
        temp1=head;
        head=temp1->next;
        free(temp1);
        temp->next=head;
        
    }
}

void deleteend(linklist *l1)
{
   struct node *previous;   
     if(head==NULL)
    {
        printf("list is empty\n");
    }
    else{
        temp=head;
        
     while (temp->next != NULL)
    {
      previous = temp;
      temp = temp->next;
      
    }
    previous->next = NULL;
    free(temp);
    }
}
void deletePosition(linklist *l1) {
    int pos, i = 1;
    struct node *temp, *prevnode;
    temp = head;
    printf("Enter the position you want to delete: ");
    scanf("%d", &pos);
    if (pos < 1 || pos > length()) {
        printf("Invalid Position!");
    }
    else if (pos == 1) {
        deletefirst();
    }
    else {
        while (i < pos) {
            prevnode = temp;
            temp = temp->next;
            i++;
        }
        prevnode->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = prevnode;
        }
        free(temp);
    }
}

void display(linklist *l1)
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = head;
        do
        {
            printf("%c-> ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}
