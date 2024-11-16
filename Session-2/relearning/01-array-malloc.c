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

    // Initialize all elements to 0 first
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }

    // Set values for every 3rd element
    for (int i = 0; i < size; i++) {
        if (i % 3 == 0) {
            arr[i] = i + 1;
        }
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