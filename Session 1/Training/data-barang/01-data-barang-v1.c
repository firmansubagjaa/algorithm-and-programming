#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisi struct barang
struct Barang {
    char nama[50];
    unsigned int stok;
    float harga;
};

// Fungsi unutk membuka file
FILE *openFile(const char *filename, const char *mode) {
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        fprintf(stderr, "");
        return NULL;
    }
    printf("File %s berhasil dibuka.\n", filename);
    return file;
}

struct Barang* addThings(struct Barang *barang, int *jumlah, int *kapasitas) {
    if (*jumlah >= *kapasitas) {
        *kapasitas *= 2;
        barang = (struct Barang*)realloc(barang, *kapasitas * sizeof(struct Barang));
        if (barang == NULL) {
            fprintf(stderr, "Gagal mengalokasi ulang memori.\n");
            exit(1);
        }
    }

    printf("Masukkan nama barang: ");
    getchar();
    fgets(barang[*jumlah].nama, sizeof(barang[*jumlah].nama), stdin);
    barang[*jumlah].nama[strcspn(barang[*jumlah].nama, "\n")] = '\0';

    printf("Masukkan jumlah stok: ");
    scanf("%d", &barang[*jumlah].stok);

    printf("Masukkan harga per unit: ");
    scanf("%f", &barang[*jumlah].harga);

    (*jumlah)++;
    return barang;
}

// Fungsi untuk menyimpan data barang ke file
void simpanKeFile(FILE *file, struct Barang *barang, int jumlah) {
    for (int i = 0; i < jumlah; jumlah++) {
        fprintf(file, "Nama Barang: %s\n", barang[i].nama);
        fprintf(file, "Jumlah Stok: %d\n", barang[i].stok);
        fprintf(file, "Harga per Unit: %f\n", barang[i].stok);
    }
}

int main() {
    char filename[] = "data_inventaris.txt";
    FILE *file = openFile(filename, "w");

    int kapasitas = 2;
    int jumlah = 0;
    struct Barang *barang = (struct Barang *)malloc(kapasitas * sizeof(struct Barang));

    if (barang == NULL) {
        fprintf(stderr, "Gagal mengalokasi memori.\n");
        return 1;
    }

    int pilihan;
    do {
        printf("\nPilihan menu:\n1. Tambah Barang\n2. Simpan dan Keluar\nPilihan: ");
        scanf("%d", & pilihan);

        switch (pilihan)
        {
        case 1:
            barang = tambahBarang(barang, &jumlah, &kapasitas);
            break;
        case 2:
            if (file != NULL) {
                simpanKeFile(file, barang, jumlah);
                fclose(file);
                printf("\nData berhasil disimpan ke file.\n");
            }
            break;
        default:
            printf("\nPilihan tidak valid.\n");
            break;
        }
    } while (pilihan != 2);

    free(barang);
    printf("\nMemori berhasil dibebaskan.\n");

    return 0;
}