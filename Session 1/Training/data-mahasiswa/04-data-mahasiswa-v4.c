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
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        fprintf(stderr, "Gagal membuka file %s.\n", filename);
        return NULL;
    }

    printf("Berhasil %s file %s.\n", mode[0] == 'w' ? "membuat" : "membuka", filename);
    return file;
}

// Fungsi untuk menulis data ke file
void tulisDataKeFile(FILE *file, struct Mahasiswa *mhs) {
    fprintf(file, "Nama: %s\n", mhs->nama);
    fprintf(file, "NIM: %d\n", mhs->nim);
    fprintf(file, "Nilai: %.2f\n", mhs->nilai);
}

void tutupFile(FILE *file) {
    fclose(file);
    printf("File berhasil ditutup.\n");
}

int main() {
    char filename[50] = "data_mahasiswa_v4.txt";
    FILE *file = bukaFile(filename, "w");

    if (file != NULL) {
        int jumlahMahasiswa = 0;
        int kapasitas = 2; // Mulai dengan alokasi kapasitas awal
        struct Mahasiswa *mahasiswa = (struct Mahasiswa *)malloc(kapasitas * sizeof(struct Mahasiswa));

        if (mahasiswa == NULL) {
            fprintf(stderr, "Gagal mengalokasi memori.\n");
            tutupFile(file);
            return 1;
        }

        while (1) {
            if (jumlahMahasiswa >= kapasitas) {
                kapasitas *= 2;
                mahasiswa = (struct Mahasiswa *)realloc(mahasiswa, kapasitas * sizeof(struct Mahasiswa));
                
                if (mahasiswa == NULL) {
                    fprintf(stderr, "Gagal mengalokasi ulang memori.\n");
                    tutupFile(file);
                    return 1;
                }
            }

            // Input data mahasiswa
            printf("\nMasukkan data mahasiswa ke-%d\n", jumlahMahasiswa + 1);
            printf("Nama: ");
            getchar(); // Menghapus newline dari input sebelumnya
            fgets(mahasiswa[jumlahMahasiswa].nama, sizeof(mahasiswa[jumlahMahasiswa].nama), stdin);
            mahasiswa[jumlahMahasiswa].nama[strcspn(mahasiswa[jumlahMahasiswa].nama, "\n")] = '\0';

            printf("NIM: ");
            while(scanf("%d", &mahasiswa[jumlahMahasiswa].nim) != 1) {
                printf("NIM harus berupa angka. Masukkan kembali: ");
                while(getchar() != '\n'); // Hapus input tidak valid
            }

            printf("Nilai: ");
            while(scanf("%f", &mahasiswa[jumlahMahasiswa].nilai) != 1) {
                printf("Nilai harus berupa angka. Masukkan kembali: ");
                while(getchar() != '\n'); // Hapus input tidak valid
            }
            while(getchar() != '\n'); // Hapus newline setelah scanf
            
            // Tulis data mahasiswa ke file
            tulisDataKeFile(file, &mahasiswa[jumlahMahasiswa]);
            jumlahMahasiswa++;

            // Pilihan untuk menambah data lagi atau berhenti
            char pilihan;
            printf("Apakah ingin menambah mahasiswa lagi? (y/n): ");
            scanf(" %c", &pilihan);
            if (pilihan == 'n' || pilihan == 'N') {
                break;
            }
        }

        // Menutup file dan membebaskan memori
        tutupFile(file);
        free(mahasiswa);
        printf("\nMemori berhasil dibebaskan.\n");
    }

    return 0;
}
