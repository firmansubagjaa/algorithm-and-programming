#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n;

    // Minta input jumlah elemen array
    printf("Masukkan jumlah elemen array: ");
    scanf("%d", &n);

    // Mengalokasikan memori untuk array dengan n elemen
    arr = (int*) malloc(n * sizeof(int));

    // Mengecek apakah malloc berhasil
    if (arr == NULL) {
        printf("Alokasi memori gagal!\n");
        return 1;
    }

    // Menampilkan nilai array
    printf("\n Array yang dimasukkan:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemen %d\n", i+1, arr[i]);
    }

    return 0;
}