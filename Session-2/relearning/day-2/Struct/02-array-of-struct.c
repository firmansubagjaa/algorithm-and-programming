#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Buku {
    char judul[100];
    char pengarang[50];
    int tahuTerbit;
};

int main() {
    int jumlahBuku = 2;
    int kapasitas = 0;
    struct Buku *buku1 = (struct Buku*)malloc(jumlahBuku * sizeof(struct Buku));
    if (buku1 == NULL) {
        fprintf(stderr, "Gagal mengalokasikan memori!\n");
        return 1;
    }

    int pilihan;
    return 0;
}