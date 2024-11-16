#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int size;

    printf("Masukkan panjang array of number: ");
    scanf("%d", &size);

    arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Gagal untuk alokasi memori!\n");
        return 1;
    }

    // Set values for every 3rd element
    for (int i = 0; i < size; i++) {
         arr[i] = (i + 1) * 3;
    }

    printf("Menampilkan elemen number di dalam array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free allocated memory
    free(arr);

    return 0;
}