#include <stdio.h>

FILE* bukaFile(const char *nama_file, char *mode) {
    FILE *file = fopen(nama_file, mode);
    if (file == NULL) {
        fprintf(stderr, "File %s gagal untuk dibuka!\n", nama_file);
        return NULL;
    }
    return file;
}

void tulisDataKeFile(FILE *file) {
    if (file == NULL) {
        fprintf(stderr, "File tidak valid!\n");
        return;
    }
    fprintf(file, "Nama: Firman Subagja\n");
    fprintf(file, "NIM: A0011\n");
    fprintf(file, "Nilai: A\n");
}

void menutupData(FILE *file) {
    if (file == NULL) {
        fprintf(stderr, "File tidak valid!\n");
        return;
    }
    fclose(file);
    printf("Data telah berhasil ditulis ke file.");
}

int main() {
    FILE *file = bukaFile("data_mahasiswa_v1.txt", "w");
    tulisDataKeFile(file);
    menutupData(file);
    return 0;
}