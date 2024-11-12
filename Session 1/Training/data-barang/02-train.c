#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Barang {
    char nama[50];
    unsigned int stok;
    float harga;
};

FILE *openFile(const char *filename) {
    FILE *check = fopen(filename, "r");
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Terjadi kesalahan.");
        return NULL;
    }
    printf("\nBerhasil untuk %s file %s.\n", check == NULL ? "Membuat" : "Membuka");
    return file;
}

void closeFile(FILE *file) {
    if (file != NULL) {
        fclose(file);
        printf("\nBerhasil untuk menutupkan file.\n");
    }
}

void addData(FILE *file, const char *filename) {
    if (file == NULL) {
        fprintf(stderr, "Terjadi kesalahan pada saat menambahkan data.");
        return;
    }
    fprintf(file, "Nama: Firman");
    fprintf(file, "NIM: A001");
    fprintf(file, "Nilai: 100");
}