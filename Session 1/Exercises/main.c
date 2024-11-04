/*
   Sequence process

   Definisi masalah
   Membuat program komputer yang mana
   hanya berupa penjumlahan dari angka A dan
   angka B.

   Membuat model masalah
   Hasil = A + B

   Merancang algoritma
   1. Mulai
   2. Set variable A, B, dan hasil
   3. Set hasil = A + B;
   4. Tampilkan "Hasil penjumlahan dari
      [A] dan [B] adalah [hasil]"
   5. Selesai

   Menulis program
*/
#include <stdio.h>

int main() {
   int A, B, hasil;

   printf("Masukkan nilai pertama: ");
   scanf("%d", &A);

   printf("Masukkan nilai kedua yang akan dijumlahkan: ");
   scanf("%d", &B);

   hasil = A + B;
   printf("Hasil penjumlahan dari %d dan %d adalah: %d", A, B, hasil);
   return 0;
}

/*
   Menjalankan kode
   kita jalankan  program dengan memanggil
   - gcc main.c -o 
   dan melakukan pengujian

   Perbaikan kesalahan (debuggin)
   Program telah berjalan dengan baik.

   Dokumentasi
   Program ini bertujuan untuk melakukan
   operasi aritmatika berupa penjumlahan
   antara Angka A dan Angka B.
*/