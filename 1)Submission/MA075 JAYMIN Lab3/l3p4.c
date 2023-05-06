#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int empID;
    char name[50];
    int age;
};

int main() {
    int n, i;
    struct Employee *employees;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    employees = (struct Employee *)malloc(n * sizeof(struct Employee));
    if (employees == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);

        printf("Employee ID: ");
        scanf("%d", &employees[i].empID);

        printf("Name: ");
        scanf("%s", employees[i].name);

        printf("Age: ");
        scanf("%d", &employees[i].age);
    }

    printf("\nEmployee Details:\n");

    for (i = 0; i < n; i++) {
        printf("\nEmployee %d:\n", i + 1);

        printf("Employee ID: %d\n", employees[i].empID);
        printf("Name: %s\n", employees[i].name);
        printf("Age: %d\n", employees[i].age);
    }

  

    return 0;
}
