#include <stdio.h>


struct student {
    char name[50];
    int idno;
    float marks;
};
int main() 
{
    int n, i;
    float m;
    printf("Enter the number of student: ");
    scanf("%d", &n);

    struct student s[n];

    for (i = 0; i < n; i++) {
        printf("\n name is  %d: ", i + 1);
        scanf("%s", s[i].name);

        printf("idno is  %d: ", i + 1);
        scanf("%d", &s[i].idno);

        printf(" marks is  %d: ", i + 1);
        scanf("%f", &s[i].marks);
    }

    printf("\nEnter the minimum marks limit of students: ");
    scanf("%f", &m);

    printf("\nmarks less than %.2f:\n", m);
    for (i = 0; i < n; i++) {
        if (s[i].marks < m) {
            printf("%s, %d\n", s[i].name, s[i].idno);
        }
    }
    return 0;
}
