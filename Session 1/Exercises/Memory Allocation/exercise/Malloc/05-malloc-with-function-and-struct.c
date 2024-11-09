#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Mahasiswa {
    char nama[50];
    int umur;
    float nilai;
};

void inputMahasiswa(struct Mahasiswa *mhs, int jumlah) {
    for (int i = 0; i < jumlah; i++) {
        printf("\nMahasiswa ke-%d\n", i+1);
        printf("Masukkan nama mahasiswa: ");
        fgets(mhs[i].nama, sizeof(mhs[i].nama), stdin);
        mhs[i].nama[strcspn(mhs[i].nama, "\n")] = '\0';

        printf("Masukkan umur mahasiswa: ");
        if (scanf("%d", &mhs[i].umur) != 1) {
            fprintf(stderr, "Input umur mahasiswa tidak valid!\n");
            free(mhs);
            break;
        }

        printf("Masukkan nilai mahasiswa: ");
        if (scanf("%f", &mhs[i].nilai) != 1) {
            fprintf(stderr, "Input nilai mahasiswa tidak valid!\n");
            free(mhs);
            break;
        }
        getchar();
    }
}

void showingDataMahasiswa(struct Mahasiswa *mhs, int jumlah) {
    printf("\nDaftar data para mahasiswa\n");
    for (int i = 0; i < jumlah; i++) {
        printf("Nama: %s, Umur: %d, Nilai: %.2f\n", mhs[i].nama, mhs[i].umur, mhs[i].nilai);
    }
}

int main() {
    struct Mahasiswa *mhs;
    int jumlah;

    printf("Masukkan jumlah mahasiswa: ");
    if (scanf("%d", &jumlah) != 1) {
        fprintf(stderr, "Input jumlah mahasiswa tidak valid!");
        return 1;
    }
    getchar();

    mhs = (struct Mahasiswa *)malloc(jumlah * sizeof(struct Mahasiswa));

    if (mhs == NULL) {
        fprintf(stderr, "Alokasi memori gagal!\n");
        return 1;
    }
    inputMahasiswa(mhs, jumlah);
    showingDataMahasiswa(mhs, jumlah);
    

    free(mhs);

    return 0;
}