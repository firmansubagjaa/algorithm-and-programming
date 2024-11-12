#include <stdio.h>
#include <stdlib.h>

void arrayModified(int *ptr, int size) {
    printf("Array sebelum modifikasi: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(ptr + i));
    }

    for (int i = 0; i < size; i++){
        *(ptr + i) += 5;
    }

    printf("\nArray sesudah modifikasi: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");
}

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int *ptr = arr;
    arrayModified(ptr, size);
    return 0;
}