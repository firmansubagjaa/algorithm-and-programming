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
    int jumlah, i;

    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &jumlah);
    getchar();

    mhs = (struct Mahasiswa *)malloc(jumlah * sizeof(struct Mahasiswa));

    if (mhs == NULL) {
        fprintf(stderr, "Alokasi memori gagal!\n");
        free(mhs);
        return 1;
    }

    for (i = 0; i < jumlah; i++) {
        printf("\nMahasiswa ke-%d\n", i + 1);
        printf("Masukkan nama mahasiswa: ");
        fgets(mhs[i].nama, sizeof(mhs[i].nama), stdin);
        mhs[i].nama[strcspn(mhs[i].nama, "\n")] = '\0';

        printf("Masukkan umur mahasiswa: ");
        if (scanf("%d", &mhs[i].umur) != 1) {
            fprintf(stderr, "Input umur tidak valid!");
            free(mhs);
            return 1;
        }

        printf("Masukkan nilai mahasiswa: ");
        if (scanf("%f", &mhs[i].nilai) != 1) {
            fprintf(stderr, "Input nilai tidak valid!");
            free(mhs);
            return 1;
        }
        getchar();
    }

    printf("\nData mahasiswa:\n");
    for (i = 0; i < jumlah; i++) {
      printf("Nama: %s, Umur: %d, Nilai: %.2f\n", mhs[i].nama, mhs[i].umur, mhs[i].nilai);  
    } 

    free(mhs);

    return 0;
}