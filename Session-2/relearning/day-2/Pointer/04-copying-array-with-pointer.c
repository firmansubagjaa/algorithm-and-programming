/*
    Soal 4: Menyalin Array dengan Pointer
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int size = 5;
    int nums[5] = {10, 20, 30, 40, 50};
    int *ptrNums = (int *)malloc(size * sizeof(int));

    if (ptrNums == NULL) {
        fprintf(stderr, "Gagal untuk mengalokasi memori!\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        ptrNums[i] = nums[i];
    }

    printf("Array tanpa menggunakan pointer: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    printf("\nArray menggunakan pointer: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", ptrNums[i]);
    }
    printf("\n");

    free(ptrNums);
    return 0;
}