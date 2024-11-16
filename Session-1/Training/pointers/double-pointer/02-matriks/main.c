#include <stdio.h>
#include <stdlib.h>

int main() {
    int baris, kolom;
    int **matriks;

    printf("Masukkan jumlah baris: ");
    scanf("%d", &baris);
    printf("Masukkan jumlah kolom: ");
    scanf("%d", &kolom);
    getchar();

    matriks = (int **)malloc(baris * sizeof(int *));
    if (matriks == NULL) {
        fprintf(stderr, "Gagal mengalokasi memori untuk baris!\n");
        return 1;
    }

    for (int i = 0; i < baris; i++) {
        matriks[i] = (int *)malloc(kolom * sizeof(int));
        if (matriks[i] == NULL) {
            fprintf(stderr, "Gagal mengalokasi memori untuk kolom pada baris %d!\n", i);
            return 1;
        }
    }

    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            printf("Masukkan elemen matriks [%d][%d]", i, j);
            scanf("%d", &matriks[i][j]);
        }
    }

    printf("\nMatriks yang dimasukkan:\n");
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            printf("%d ", matriks[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < baris; i++) {
        free(matriks[i]);
    }
    free(matriks);

    return 0;
}