#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisi struct Mahasiswa
struct Mahasiswa {
    char nama[50];
    int nim;
    float nilai;
};

// Fungsi untuk membuka file
FILE* bukaFile(const char *filename, const char *mode) {
    FILE* check = fopen(filename, "r");
    FILE* file = fopen(filename, mode);
    if (file == NULL) {
        fprintf(stderr, "Gagal membuka file %s.", filename);
        return NULL;
    }

    printf("Berhasil %s file %s.\n", check == NULL ? "membuat" : "membuka", filename);
    if (check != NULL) {
        fclose(check);
    }
    return file;
}

// Fungsi untuk menulis data ke file
void tulisDataKeFile(FILE *file, const char *filename, const char *nama, int nim, float nilai) {
    if (file == NULL) {
        fprintf(stderr, "Terjadi kesalahan pada saat membuka file %s.", filename);
        return;
    }
    fprintf(file, "Nama: %s\n", nama);
    fprintf(file, "NIM: %d\n", nim);
    fprintf(file, "Nilai: %f\n", nilai);
}

void tutupFile(FILE *file, const char *filename) {
    if (file == NULL) {
        fprintf(stderr, "Terjadi kesalahan pada saat membuka file %s.", filename);
        return;
    }
    fclose(file);
    printf("Berhasil berhasil ditutup.\n");
}

int main() {
    char filename[50] = "data_mahasiswa_v3.txt";
    FILE *file = bukaFile(filename, "w");

    if (file != NULL) {
        int jumlahMahasiswa = 3;
        struct Mahasiswa *mahasiswa = NULL;
        mahasiswa = (struct Mahasiswa *)malloc(jumlahMahasiswa * sizeof(struct Mahasiswa));

        if (mahasiswa == NULL) {
            fprintf(stderr, "Gagal mengalokasi memori.\n");
            tutupFile(file, filename);
            return 1; // Keluar jika alokasi memori gagal
        }

        for (int i = 0; i < jumlahMahasiswa; i++) {
            printf("\nMasukkan data mahasiswa ke-%d\n", i+1);
            printf("Nama: ");
            getchar(); // Clear any leftover newline
            fgets((mahasiswa + i)->nama, sizeof((mahasiswa + i)->nama), stdin);
            (mahasiswa + i)->nama[strcspn((mahasiswa + i)->nama, "\n")] = '\0';
            
            printf("NIM: ");
            while(scanf("%d", &(mahasiswa + i)->nim) != 1) {
                printf("NIM harus berupa angka. Masukkan kembali: ");
                while(getchar() != '\n'); // Clear invalid input
            }

            printf("Nilai: ");
            while(scanf("%f", &(mahasiswa + i)->nilai) != 1) {
                printf("Nilai harus berupa angka. Masukkan kembali: ");
                while(getchar() != '\n'); // Clear invalid input
            }
            while(getchar() != '\n'); // Clear newline after successful scanf
        }

        // Menulis data mahasiswa ke file
        for (int i = 0; i < jumlahMahasiswa; i++) {
            tulisDataKeFile(file, filename, (mahasiswa + i)->nama, (mahasiswa + i)->nim, (mahasiswa + i)->nilai);
        }

        // Menutup file setelah selesai
        tutupFile(file, filename);

        // Membebaskan memori setelah selesai digunakan
        free(mahasiswa);
        printf("\nMemori berhasil dibebaskan");
    }

    return 0;
}