#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Buku {
    char judul[50];
    char pengarang[100];
    int unsigned jumlahHalaman;
};

void inputBuku(struct Buku *buku, int jumlah) {
    if (buku == NULL) {
        fprintf(stderr, "Alokasi memori gagal!\n");
        return;
    }

    for(int i = 0; i < jumlah; i++) {
        printf("\nBuku ke-%d:\n", i + 1);
        getchar(); // Clear buffer

        printf("Judul: ");
        fgets(buku[i].judul, sizeof(buku[i].judul), stdin);
        buku[i].judul[strcspn(buku[i].judul, "\n")] = '\0'; 

        printf("Pengarang: ");
        fgets(buku[i].pengarang, sizeof(buku[i].pengarang), stdin);
        buku[i].pengarang[strcspn(buku[i].pengarang, "\n")] = '\0'; 
        
        printf("Jumlah Halaman: ");
        if (scanf("%u", &buku[i].jumlahHalaman) != 1 || buku[i].jumlahHalaman == 0) {
            fprintf(stderr, "Input jumlah halaman tidak valid!\n");
            return;
        }
    }
}

void showingBuku(struct Buku *buku, int jumlah) {
    if (buku == NULL) {
        fprintf(stderr, "Data buku kosong!\n");
        return;
    }

    printf("\nDaftar buku:\n");
    for (int i = 0; i < jumlah; i++){
        printf("Buku ke-%d\n", i+1);
        printf("Judul: %s, Pengarang: %s, Jumlah Halaman: %d\n", 
               buku[i].judul, buku[i].pengarang, buku[i].jumlahHalaman);
    }
}

void pencarianBuku(struct Buku *buku, int jumlah) {
    char keyword[50];
    int found = 0;
    
    printf("\nCari buku berdasarkan judul: ");
    getchar(); // Clear buffer
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    for (int i = 0; i < jumlah; i++) {
        if (strcmp(keyword, buku[i].judul) == 0) {
            printf("Buku ditemukan!\n");
            printf("Judul: %s\nPengarang: %s\nJumlah Halaman: %d\n", 
                   buku[i].judul, buku[i].pengarang, buku[i].jumlahHalaman);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Buku dengan judul '%s' tidak ditemukan!\n", keyword);
    }
}

int main() {
    struct Buku *buku1;
    int unsigned jumlah;

    printf("Jumlah buku yang akan didata: ");
    if (scanf("%d", &jumlah) != 1 || jumlah <= 0) {
        fprintf(stderr, "Input jumlah buku tidak valid!\n");
        return 1;
    }

    buku1 = (struct Buku *)malloc(jumlah * sizeof(struct Buku));
    if (buku1 == NULL) {
        fprintf(stderr, "Alokasi memori gagal!\n");
        return 1;
    }

    inputBuku(buku1, jumlah);
    showingBuku(buku1, jumlah);
    pencarianBuku(buku1, jumlah);
    free(buku1);
    return 0;
}