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
    if (check != NULL) {
        fclose(check);
    }
    return file;
}

void closeFile(FILE *file) {
    if (file != NULL) {
        fclose(file);
        printf("\nBerhasil untuk menutup file.\n");
    }
}

struct Barang* postData(struct Barang *barang, int *jumlah, int *kapasitas, FILE *file) {
    if (*jumlah >= *kapasitas) {
        *kapasitas *= 2;
        struct Barang *temp = (struct Barang*)realloc(barang, *kapasitas * sizeof(struct Barang));
        if (temp == NULL) {
            fprintf(stderr, "Gagal alokasi ulang memori!");
            closeFile(file);
            free(barang);
            exit(1);
        }
        barang = temp;
    }
    printf("Masukkan nama barang: ");
    getchar();
    fgets(barang[*jumlah].nama, sizeof(barang[*jumlah].nama), stdin);
    barang[*jumlah].nama[strcspn(barang[*jumlah].nama, "\n")] = '\0';

    printf("Masukkan jumlah stok: ");
    while (scanf("%u", &barang[*jumlah].stok) != 1) {
        printf("Input yang anda masukkan harus berupa angka, silahkan dimasukkan kembali: ");
        while(getchar() != '\n');
    }
    printf("Masukkan harga barang: ");
    while (scanf("%f", &barang[*jumlah].harga) != 1) {
        printf("Input yang anda masukkan harus berupa angka, silahkan dimasukkan kembali: ");
        while(getchar() != '\n');
    }
    (*jumlah)++;
    return barang;
}

void addDatatoFile(FILE *file, struct Barang *barang, const int *jumlah) {
    for (int i = 0; i < *jumlah; i++) {
        fprintf(file, "%s | %d | %.2f\n",
            barang[i].nama,
            barang[i].stok,
            barang[i].harga
        );
    }
}

int main() {
    char filename[50] = "data_barang.txt";
    FILE *file = openFile(filename, "w");
    if (file == NULL) {
        return 1;
    }
    
    int jumlahBarang = 0;
    int kapasitas = 2;
    struct Barang *barang = (struct Barang*)malloc(kapasitas * sizeof(struct Barang));

    if (barang == NULL) {
        fprintf(stderr, "Gagal mengalokasi memori!");
        fclose(file);
        return 1;
    }

    int pilihan;
    do {
        printf("\nPilihan menu:\n");
        printf("1. Tambah Barang\n");
        printf("2. Simpan dan keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                barang = postData(barang, &jumlahBarang, &kapasitas, file);
                break;
            case 2:
                addDatatoFile(file, barang, &jumlahBarang);
                closeFile(file);
                break;
            default:
                printf("\nPilihan tidak valid.");
                break;
        }
    } while (pilihan != 2);

    free(barang);
    printf("\nMemori berhasil dilepaskan.\n");

    return 0;
}