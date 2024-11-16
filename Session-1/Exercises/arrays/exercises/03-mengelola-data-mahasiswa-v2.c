#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Mahasiswa{
    char nama[50];
    unsigned int nim;
    float nilai;
};

// Fungsi untuk mencetak data mahasiswa
void printMahasiswa(struct Mahasiswa *mhs, int size) {
    for (int i = 0; i < size; i++) {
        printf("Mahasiswa %d:\n", i+1);
        printf("Nama: %s\n", (mhs + 1)->nama);
        printf("NIM : %d\n",  (mhs + 1)->nim);
        printf("Nilai: %.2f\n", (mhs + 1)->nilai);
    }
}

// Fungsi untuk menghitung rata-rata nilai
float hitungRataNilai(struct Mahasiswa *mhs, int size) {
    float totalNilai = 0.0;
    for (int i = 0; i < size; i++) {
        totalNilai += (mhs + i)->nilai;
    }
    return totalNilai / size;
}

int main() {
    struct Mahasiswa *mhs = NULL;
    int maxMahasiswa = 0;
    int capacity = 2;

    mhs = (struct Mahasiswa*)malloc(capacity * sizeof(struct Mahasiswa));
    if (mhs == NULL) {
        fprintf(stderr, "Gagal mengalokasi memori!");
        return 1;
    }

    while(1) {
        if (maxMahasiswa == capacity) {
            capacity *= 2;
            mhs = (struct Mahasiswa *)realloc(mhs, capacity * sizeof(struct Mahasiswa));
            if (mhs == NULL) {
                fprintf(stderr, "Gagal merelokasikan memori!\n");
                return 1;
            }
        }
        printf("Masukkan data mahasiswa %d\n", maxMahasiswa + 1);
        printf("Nama : ");
        fgets(mhs[maxMahasiswa].nama, sizeof(mhs[maxMahasiswa].nama), stdin);
        mhs[maxMahasiswa].nama[strcspn(mhs[maxMahasiswa].nama, "\n")] = '\0';

        printf("NIM : ");
        scanf("%d", &mhs[maxMahasiswa].nim);

        printf("Nilai : ");
        scanf("%f", &mhs[maxMahasiswa].nilai);

        getchar();

        maxMahasiswa++;

        char lanjut;
        printf("Apakah Anda ingin memasukkan data lagi? (y/n): ");
        scanf("%c", &lanjut);
        getchar();

        if (lanjut == 'n' || lanjut == 'N') {
            break;
        }
    }

    // Mencetak data mahasiswa
    printf("\nData Mahasiswa:\n");
    printMahasiswa(mhs, maxMahasiswa);

    float rataNilai = hitungRataNilai(mhs,maxMahasiswa);
    printf("Rata-rata nilai: %.2f\n", rataNilai);

    // Membebaskan memori
    free(mhs);
    printf("Memori telah dibebaskan.\n");

    return 0;
}