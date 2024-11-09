/*
    Malloc
    - digunakan untuk mengalokasikan sejumlah memori dalam heap.
    - Fungsi ini menerima satu parameter, yaitu ukuran memori yang dibutuhkan, dan mengembalikan pointer ke awal blok memori yang dialokasikan.
    - Memori yang dialokasikan menggunakan malloc() tidak diinisialisasi, sehingga nilai awalnya bisa acak.

    Sintaks dari malloc():
        ptr = (tipe_data*) malloc(ukuran_memori);
    - tipe_data*: adalah tipe data pointer yang sesuai (misalnya, int*, float*, dsb)
    - ukuran_memori: jumlah byte yang ingin dialokasikan, biasanya menggunakan sizeof(tipe_data). 
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    int n;

    // Meminta jumlah elemen yang ingin disimpan
    printf("Masukkan jumlah elemen: ");
    scanf("%d", &n);

    // Alokasi memori untuk array menggunakan malloc
    ptr = (int*)malloc(n * sizeof(int)); // mengalokasikan memori untuk n elemen integer

    // Mengecek apakah alokasi memori berhasil
    if (ptr == NULL) {
        printf("Alokasi memori gagal!\n");
        return 1;
    }

    // Mengisi array dengan nilai
    for (int i = 0; i < n; i++) {
        printf("Masukkan elemen %d: ", i + 1);
        scanf("%d", &ptr[i]); // mengisi array dengan input pengguna
    }

    // Menampilkan nilai array
    printf("Isi array yang dimasukkan: \n");
    for (int i = 0; i < n; i++) {
        printf("Elemen %d: %d\n", i + 1, ptr[i]);
    }

    // Membebaskan memori setelah selesai digunakan
    free(ptr);

    return 0;
}