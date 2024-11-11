#include <stdio.h>
#include <stdlib.h>

void tambahElemen(int **array, int *size, int elemenBaru) {
    *array = realloc(*array, (*size + 1) * sizeof(int));

    if (*array == NULL) {
        fprintf(stderr, "Alokasi memori gagal!\n");
        exit(1);
    }

    (*array)[*size] = elemenBaru;

    (*size)++;
}

int main() {
    int *array = NULL;
    int size = 0;
}