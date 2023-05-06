#include <stdio.h>

int main() {
    char str[100];
    char *p;
    int vowels = 0, consonants = 0;

    printf("Enter a string: ");
    scanf("%s",str);
    p = str;
    
    while (*p != '\0') {
        if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u' ||
            *p == 'A' || *p == 'E' || *p == 'I' || *p == 'O' || *p == 'U') {
            vowels++;
        } else if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z')) {
            consonants++;
        }
        p++;
    }

    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);

    return 0;
}
