#include <stdio.h>

int main() {
  int a[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  
  int *p = a; 

  printf("a= %p\n", a);

   for (int i =0; i<15; i++) {
    printf("Array elements %d  \n", *(p+i));
   }
   printf("\n");

   return 0;
}