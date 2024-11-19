/*
    Soal 5: Menghitung Panjang String
*/
#include <stdio.h>

void wordLength(char *word) {
    int length = 0;
    while (*word != '\0') {
        length++;
        word++;
    }
    printf("Panjang string: %d", length);
}

int main() {
    int size = 5;
    char word[6] = "Hello"; // Need space for null terminator

    wordLength(word);

    return 0;
}