#include <stdio.h>

struct student{
    int rno;
    char name[20];
};





typedef struct students
{
    int no;
    char n[20];
}ss1;

int main()
{
    
    struct student s1;
    ss1 s2;
   
    
    int a=10;
    int *ptr=&a;
    
    printf("\n%p",&a);
    printf("\n%d",a);
    printf("\n%d",*ptr);
    printf("\n%p",&ptr);
    printf("\n%p",*(&ptr));
    
    struct student *ptr1;
    ptr1=&s1;
    
    scanf("\n%d",&s1.rno);
    printf("\n %d",s1.rno);
    printf("\n %d",ptr1->rno);
    printf("\n %d",(*ptr1).rno);
    
    /* ------ */
    scanf("\n%d",&s2.no);
    printf("\n%d",s2.no);
    

    return 0;
}
