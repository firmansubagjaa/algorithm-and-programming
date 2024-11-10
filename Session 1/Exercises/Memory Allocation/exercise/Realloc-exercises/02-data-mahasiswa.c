/*
    Mendefinisikan masalah
        Membuat program untuk menangani data Mahasiswa yang memiliki nama, umur, dan nilai dengan fitur Create, Read, Update, dan Delete (CRUD) dengan menggunakan alokasi memori dinamin yaitu malloc dan realloc
    
    Membuat model
        mendefinisikan struct mahasiswa
            - char nama[50]
            - int umur
            - float nilai
    
    Perancangan Algoritma
        skip dulu dan langsung penulisan program

    Menulis Program
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Mahasiswa {
    char nama[50];
    int umur;
    float nilai;
};

// Deklarasi fungsi CRUD
void tambahMahasiswa(struct Mahasiswa **mhs, int *count, int *size);
void tampilkanMahasiwa(struct Mahasiswa *mhs, int count);
void cariMahasiswa(struct Mahasiswa *mhs, int count);
void cariMahasiswa(struct Mahasiswa *mhs, int count);
void perbaruiMahasiswa(struct Mahasiswa *mhs, int count);
void hapusMahasiswa(struct Mahasiswa *mhs, int count);

int main() {
    struct Mahasiswa *mahasiswa = NULL;
    int count = 0;
    int size = 2;
    int pilihan;

    // Alokasi awal untuk 2 mahasiswa
    mahasiswa = (struct Mahasiswa *)malloc(size * sizeof(struct Mahasiswa));
    if (mahasiswa == NULL) {
        fprintf(stderr, "Alokasi memori gagal!\n");
        return 1;
    }

    while (1) {
        printf("\nMenu CRUD Mahasiswa:\n");
        printf("1. Lihat semua data mahasiswa\n");
        printf("2. Cari data mahasiswa berdasarkan nama\n");
        printf("3. Tambah data mahasiswa\n");
        printf("4. Perbarui data mahasiswa\n");
        printf("5. Hapus data mahasiswa\n");
        printf("6. Keluar\n");
        printf("Pilihan opsi: ");
        scanf("%d", &pilihan);
        getchar();//  Bersihkan buffer newline

        switch (pilihan)
        {
        case 1:
            /* code */
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            free(mahasiswa);
            return 0;
        default:
            printf("Opsi tidak valid!\n");
            break;
        }
    }
}

// Fungsi untuk menambahkan data mahasiswa
void tambahMahasiswa(struct Mahasiswa **mhs, int *count, int *size) {
    if (*count == *size) {
        *size += 2;
        *mhs = (struct Mahasiswa *)realloc(*mhs, sizeof(struct Mahasiswa));
        if (*mhs == NULL) {
            fprintf(stderr, "Realokasi memori gagal!\n");
            exit(1);
        }
    }
    printf("Masukkan nama: ");
    fgets((*mhs)[*count].nama, sizeof((*mhs)[*count].nama), stdin);
    (*mhs)[*count].nama[strcspn((*mhs)[*count].nama, "\n")] = '\0';

    printf("Masukkan umur: ");
    scanf("%d", (*mhs)[*count].umur);

    printf("Masukkan nilai: ");
    scanf("%f", &(*mhs)[*count].nilai);
    getchar(); // Bersihkan newline

    (*count)++;
}