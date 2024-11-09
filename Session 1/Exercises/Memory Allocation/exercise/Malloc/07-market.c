#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produk {
    char nama[100];
    float harga;
    int unsigned jumlahStok;
};

void inputProduk (struct Produk *produk, int jumlah) {
    for (int i = 0; i < jumlah; i++) {
        printf("\nProduk ke-%d:\n", i + 1);
        printf("Nama Produk: ");
        fgets(produk[i].nama, sizeof(produk[i].nama), stdin);
        produk[i].nama[strcspn(produk[i].nama, "\n")] = '\0';

        printf("Harga: ");
        if(scanf("%f", &produk[i].harga) != 1 || produk[i].harga <= 0) {
            fprintf(stderr, "Input harga tidak valid!\n");
            free(produk);
            return;
        }

        printf("Stok: ");
        if (scanf("%d", &produk[i].jumlahStok) != 1 || produk[i].jumlahStok <= 0) {
            fprintf(stderr, "Input jumlah stok tidak valid!\n");
            free(produk);
            return;
        }
        getchar();
    }
}

void displayProduk (struct Produk *produk, int jumlah) {
    printf("\nDaftar produk yang sudah diinputkan:\n");
    for (int i = 0; i < jumlah; i++) {
        printf("Nama Produk: %s, Harga: %.2f, Stok: %d\n", produk[i].nama, produk[i].harga, produk[i].jumlahStok);
    }
}

void SearchProduk (struct Produk *produk, int jumlah) {
    char keyword[100];
    int itsFound = 0;

    printf("\nMencari produk: ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = '\0';
    for (int i = 0; i < jumlah; i++) {
        if (strcmp(keyword, produk[i].nama) == 0) {
            printf("\nProduk ditemukan!\n");
            printf("Nama Produk: %s, Harga: %.2f, Stok: %d\n", produk[i].nama, produk[i].harga, produk[i].jumlahStok);
            itsFound = 1;
            break;
        }
    }

    if (!itsFound) {
        printf("Produk tidak ditemukan!\n");
    }
}

int main() {
    struct Produk *produk;
    int jumlah;

    printf("Jumlah produk yang akan diinputkan: ");
    if (scanf("%d", &jumlah) != 1 || jumlah < 0) {
        fprintf(stderr, "Input jumlah produk tidak valid!\n");
        return 1;
    }
    getchar();

    inputProduk(produk, jumlah);
    displayProduk(produk, jumlah);
    SearchProduk(produk, jumlah);
    free(produk);
    return 1;
}