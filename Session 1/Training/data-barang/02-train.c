#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Barang {
    char nama[50];
    unsigned int stok;
    float harga;
};

FILE *openFile(const char *filename, char *mode) {
    FILE *check = fopen(filename, "r");
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        fprintf(stderr, "Terjadi kesalahan.");
        return NULL;
    }
    printf("\nBerhasil untuk %s file %s.\n", check == NULL ? "Membuat" : "Membuka");
    return file;
}

void closeFile(FILE *file) {
    if (file != NULL) {
        free(file);
        fclose(file);
        printf("\nBerhasil untuk menutupkan file.\n");
    }
}

void addData(FILE *file, const char *filename, struct Barang *barang, int *jumlah, int *kapasitas) {
    if (file == NULL) {
        fprintf(stderr, "Terjadi kesalahan pada saat menambahkan data.");
        closeFile(file);
        exit(1);
    }

    if (*jumlah >= *kapasitas) {
        *kapasitas *= 2;
        barang = (struct Barang*)realloc(barang, *kapasitas * sizeof(struct Barang));
        if (barang == NULL) {
            fprintf(stderr, "Gagal merelokasikan memori!");
            exit(1);
        }
    }
    for (int i = 0; i < jumlah; i++) {
        fprintf(file, "%s | %d | %.2f\n",
        (barang + i)->nama,
        (barang + i)->stok,
        (barang + i)->harga
        );
    }
}

int main() {
    char filename[50] = "data_barang.txt";
    FILE *file = openFile(filename, "w");
    int jumlahBarang = 0;
    int kapasitas = 2;
    struct Barang *barang = (struct Barang*)malloc(kapasitas * sizeof(struct Barang));

    if (barang == NULL) {
        fprintf(stderr, "Gagal mengalokasi memori!");
        return 1;
    }

    int pilihan;
    do {

    } while (pilihan != 2);
}