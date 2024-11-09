#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n;

    printf("Masukkan jumlah elemen array: ");
    scanf("%d", &n);
    getchar();

    arr = (int*) malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Alokasi memori gagl!\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        printf("Masukkan elemen %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    getchar();

    printf("\nArray yang dimasukkan:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemen %d: %d\n", i + 1, arr[i]);
    }

    free(arr);

    return 0;
}