#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char book_name[50];
    char author_name[50];
    float price;
    int pages;
};

void displayAllBooks(struct Book *books, int num_books) {
    printf("Book information:\n");
    for (int i = 0; i < num_books; i++) {
        printf("Book %d:\n", i+1);
        printf("  Name: %s\n", books[i].book_name);
        printf("  Author: %s\n", books[i].author_name);
        printf("  Price: %.2f\n", books[i].price);
        printf("  Pages: %d\n", books[i].pages);
    }
}

int main() {
    int num_books;

    printf("How many? ");
    scanf("%d", &num_books);

    struct Book *books = (struct Book *) malloc(num_books * sizeof(struct Book));

    for (int i = 0; i < num_books; i++) {
        printf("Enter information for Book %d:\n", i+1);
        printf("  Name: ");
        scanf(" %[^\n]", books[i].book_name);
        printf("  Author: ");
        scanf(" %[^\n]", books[i].author_name);
        printf("  Price: ");
        scanf("%f", &books[i].price);
        printf("  Pages: ");
        scanf("%d", &books[i].pages);
    }

    printf("\nBooks starting with 'D':\n");
    for (int i = 0; i < num_books; i++) {
        if (books[i].book_name[0] == 'D') {
            printf("  Name: %s\n", books[i].book_name);
            printf("  Author: %s\n", books[i].author_name);
            printf("  Price: %.2f\n", books[i].price);
            printf("  Pages: %d\n", books[i].pages);
        }
    }

    displayAllBooks(books, num_books);

    free(books);
    return 0;
}
