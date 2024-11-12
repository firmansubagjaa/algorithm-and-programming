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

struct Barang* postData(struct Barang *barang, int *jumlah, int *kapasitas, FILE *file) {
    if (*jumlah >= *kapasitas) {
        *kapasitas *= 2;
        barang = (struct Barang*)realloc(barang, *kapasitas * sizeof(struct Barang));
        if (barang == NULL) {
            fprintf(stderr, "Gagal alokasi ulang memori!");
            closeFile(file);
            exit(1);
        }
    }
    printf("Masukkan nama barang: ");
    getchar();
    fgets(barang[*jumlah].nama, sizeof(barang[*jumlah].nama), stdin);
    barang[*jumlah].nama[strcspn(barang[*jumlah].nama, "\n")] = '\0';

    printf("Masukkan jumlah stok: ");
    while (scanf("%d", &barang[*jumlah].stok) != 1) {
        printf("Input yang anda masukkan harus berupa angka, silahkan dimasukkan kembali: ");
        while(getchar() != "\n");
    }
    printf("Masukkan harga barang: ");
    while (scanf("%d", &barang[*jumlah].harga) != 1) {
        printf("Input yang anda masukkan harus berupa angka, silahkan dimasukkan kembali: ");
        while(getchar() != "\n");
    }
    (*jumlah)++;
    return barang;
}

void addData(FILE *file, struct Barang *barang, const int *jumlah) {
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
        printf("\nPilihan menu:\n");
        printf("1. Tambah Barang\n");
        printf("2. Simpan dan keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            barang = postData(barang, &jumlahBarang, &kapasitas, file);
            break;
        
        default:
            break;
        }
    } while (pilihan != 2);
}