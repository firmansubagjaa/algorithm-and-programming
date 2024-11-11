#include <stdio.h>

int main() {
    // Membuka file untuk menulis (baca/tulis mode)
    FILE *file = fopen("data.txt", "w");

    // Mengecek apakah file berhasil dibuka
    if (file == NULL) {
        fprintf(stderr, "Gagal membuka file.\n");
        return 1; // Keluar dengan kode kesalahan
    }

    // Menulis data ke file
    fprintf(file, "Nama: John Doe\n");
    fprintf(file, "NIM: 12345678\n");
    fprintf(file, "Nilai: 88.5\n");

    // Menutup file setelah selesai
    fclose(file);

    printf("\nData berhasil ditulis ke file.\n");
    return 0;
}