#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    int *arr;

    printf("Masukkan ukuran array: ");
    scanf("%d", &size);
    arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Gagal alokasi memori!\n");
        return 1;
    }
    int *ptr = arr;
    for (int i = 0; i < size; i++) {
        printf("Masukkan nilai elemen ke-%d: ", i + 1);
        scanf("%d", (ptr + i));
    }

    printf("Nilai array yang sudah dimasukkan: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(ptr + i));
    }

    free(arr);
    return 0;
}