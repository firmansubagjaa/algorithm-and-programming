#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    int *arrInteger;
    float *arrFloat;

    printf("Masukkan nilai panjang array: ");
    scanf("%d", &size);

    arrInteger = (int *)malloc(size * sizeof(int));
    arrFloat = (float *)malloc(size * sizeof(float));

    if (arrInteger == NULL) {
        fprintf(stderr, "Gagal mengalokasi memori!\n");
        return 1;
    }

    if (arrFloat == NULL) {
        fprintf(stderr, "Gagal mengalokasi memori!\n");
        free(arrInteger);
        return 1;
    }
    printf("\nBerhasil mengalokasi memori\n");

    printf("\nInput untuk array of integer\n");
    for(int i = 0; i < size; i++) {
        printf("Masukkan elemen integer ke-%d: ", i+1);
        scanf("%d", (arrInteger + i));
    }
    printf("\n");

    printf("Input untuk array of float\n");
    for (int i = 0; i < size; i++) {
        printf("Masukan elemen float ke-%d: ", i+1);
        scanf("%f", (arrFloat + i));
    }
    printf("\n");

    for (int i = 0; i < size; i++) {
        printf("Array of integer ke-%d: %d\n", i + 1, *(arrInteger + i));
    }
    printf("\n");

    for (int i = 0; i < size; i++) {
        printf("Array of float ke-%d: %.2f\n", i + 1, *(arrFloat + i));
    }

    free(arrInteger);
    free(arrFloat);
    return 0;
}