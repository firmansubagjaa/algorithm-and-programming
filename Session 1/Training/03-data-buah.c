#include <stdio.h>

FILE* openFile(char *file_name, char *mode) {
    FILE* check = fopen(file_name, "r");
    FILE* file;

    file = fopen(file_name, mode);
    if (file == NULL) {
        fprintf(stderr, "\nFile %s tidak bisa dibuka!\n", file_name);
        return NULL;
    }
    printf("\nFile %s berhasil %s!\n", file_name, check == NULL ? "dibuat" : "dibuka");

    fclose(check);
    return file;
}

void createData(FILE *file, char *file_name) {
    if (file == NULL) {
        fprintf(stderr, "\nTerjadi kesalahan saat membuat file %s\n", file_name);
        return;
    }
    fprintf(file, "Nama Produk: Apel\n");
    fprintf(file, "Jenis: Buah\n");
    fprintf(file, "Stok: 50\n");
}

void closeFile(FILE *file, char *file_name) {
    if (file == NULL) {
        fprintf(stderr, "\nTerjadi kesalahan saat membuat file %s\n", file_name);
        return;
    }
    fclose(file);
    printf("\nData berhasil ditambahkan ke file %s", file_name);
}

int main() {
    char nama_file[50] = "daftar_buah_v1.0.0.txt";
    FILE *file = openFile(nama_file, "w");
    createData(file, nama_file);
    closeFile(file, nama_file);
    return 1;
}