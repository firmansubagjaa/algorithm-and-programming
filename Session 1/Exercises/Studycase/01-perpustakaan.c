#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "data_buku.txt" // Nama file untuk menyimpan data buku


struct Buku{
    char judul[100];
    char penulis[50];
    int tahunTerbit;
};

void printBuku(struct Buku *buku, int size) {
    for (int i = 0; i < size; i++) {
        printf("Buku %d:\n", i+1);
        printf("Judul   : %s\n", (buku + i)->judul);
        printf("Penulis : %s\n", (buku + i)->penulis);
        printf("Tahun Terbit: %d\n\n", (buku + i)->tahunTerbit);
    }
}
void simpanDataKeFile(struct Buku *buku, int size) {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        fprintf(stderr, "Gagal membuat file untuk menulis.\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%s\n%s\n%d\n", (buku + i)->judul, (buku + i)->penulis, (buku + i)->tahunTerbit);
    }

    fclose(file);
    printf("Data buku berhasil disimpan ke file.\n");
};
int bacaDataDariFile(struct Buku *buku) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        fprintf(stderr, "File tidak ditemukan atau gagal dibuka.\n");
        return 0;
    }

    int i = 0;
    while (fscanf(file, "%99[^\n]%*c", (buku + i)->judul) == 1) { // Membaca judul
        fscanf(file, "%49[^\n]%*c", (buku + i)->penulis);
        fscanf(file, "%d%c", &(buku + i)->tahunTerbit);

        i++;
        if (i >= 100) break; //Menghindari pembacaan lebih dari 100 buku
    }

    fclose(file);
    return i; // Mengembalikan jumlah buku yang berhasil dibaca
}

int main() {
    struct Buku *data = NULL;
    int maxBuku = 0;
    int capacity = 2;

    // Alokasi memori pertama kali
    data = (struct Buku *)malloc(capacity * sizeof(struct Buku));
    if (data == NULL) {
        fprintf(stderr, "Gagal untuk alokasi memori!");
        return 1;
    }

    // Membaca data dari file jika ada
    maxBuku = bacaDataDariFile(data);
    if (maxBuku > 0) {
        printf("Data buku berhasil dibaca dari file:\n");
        printBuku(data, maxBuku);
    }

    while(1) {
        if (maxBuku == capacity) {
            capacity *= 2;
            data = (struct Buku *)realloc(data, capacity * sizeof(struct Buku));
            if (data == NULL) {
                fprintf(stderr, "Gagal untuk realokasi memori!\n");
                return 1;
            }
        }

        printf("Masukkan data buku %d\n", maxBuku + 1);
        printf("Judul       : ");
        fgets(data[maxBuku].judul, sizeof(data[maxBuku].judul), stdin);
        data[maxBuku].judul[strcspn(data[maxBuku].judul, "\n")] = '\0';


        printf("Penulis   : ");
        fgets(data[maxBuku].penulis, sizeof(data[maxBuku].penulis), stdin);
        data[maxBuku].penulis[strcspn(data[maxBuku].penulis, "\n")] = '\0';

        printf("Tahun Terbit: ");
        scanf("%d", &data[maxBuku].tahunTerbit);
        getchar();  // Menangani karakter newline setelah scanf

        maxBuku++;

        char lanjut;
        printf("Apakah Anda ingin memasukkan data lagi? (y/n): ");
        scanf(" %c", &lanjut);
        getchar();  // Menangani newline dari input sebelumnya

        if (lanjut == 'n' || lanjut == 'N') {
            break;
        }
    }
     // Mencetak data buku
    printf("\nData Buku:\n");
    printBuku(data, maxBuku);

    // Menyimpan data buku ke file
    simpanDataKeFile(data, maxBuku);

    // Membebaskan memori
    free(data);
    printf("Memori telah dibebaskan.\n");

    return 0;
}

