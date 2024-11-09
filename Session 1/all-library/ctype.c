#include <stdio.h>
#include <ctype.h>

int isAllDigits(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0; // Bukan digit
        }
    }
    return 1; // Semua karakter adalah digit
}

int main() {
    char str[] = "12345";
    char str1[] = "hell0";
    if (isAllDigits(str1)) {
        printf("String hanya berisi digit.\n");
    } else {
        printf("String berisi karakter non-digit.\n");
    }
    return 0;
}