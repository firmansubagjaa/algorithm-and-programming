#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Mahasiswa {
    char nama[50];
    int umur;
    float nilai;
};

int main() {
    struct Mahasiswa *mhs;

    mhs = (struct Mahasiswa *)malloc(sizeof(struct Mahasiswa));
    
    if (mhs == NULL) {
        fprintf(stderr, "Alokasi memori gagal!\n");
        free(mhs);
        return 1;
    }

    printf("Masukkan nama mahasiswa: ");
    fgets(mhs->nama, sizeof(mhs->nama), stdin);
    mhs->nama[strcspn(mhs->nama, "\n")] = '\0';

    printf("Masukkan umur mahasiswa: ");
    if (scanf("%d", &mhs->umur) != 1 && scanf("%d", &mhs->umur) < 0) {
        fprintf(stderr, "Nilai umur tidak valid!");
        free(mhs);
        return 1;
    }

    printf("Masukkan nilai mahasiswa: ");
    if(scanf("%f", &mhs->nilai) != 1 && scanf("%f", &mhs->nilai) < 0) {
        fprintf(stderr, "Input nilai mahasiswa tidak valid");
        free(mhs);
        return 1;
    }

    printf("\nData mahasiswa yang diinput:\n");
    printf("Nama: %s\nUmur: %d\nNilai: %.2f\n", mhs->nama, mhs->umur, mhs->nilai);

    return 0;
}