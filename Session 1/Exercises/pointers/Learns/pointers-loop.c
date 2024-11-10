#include <stdio.h>

int main() {
   // Deklarasi dan inisialisasi array
   int numbers[] = {10, 20, 30, 40, 50};
   int length = sizeof(numbers) / sizeof(numbers[0]); // Menghitung jumlah elemen
   int sum = 0;

   // Mendeklarasikan pointer dan menginisialisasi dengan alamat awal array
   int *ptr = numbers;// ptr menunjuk ke elemen pertama dari array numbers

   // looping melalui array menggunakan pointer
   for (int i = 0; i < length; i++) {
      // Menggunakan pointer untuk mengakses elemen
      sum += *(ptr + i); // Menambahkan elemen ke total
   }

   // Menampilkan hasil
   printf("Jumlah elemen dalam array: %d\n", sum);

   // Menampilkan elemen menggunakan pointer
   printf("Elemen dalam array: ");
   for (int i = 0; i < length; i++) {
      printf("%d ", *(ptr + i)); // Mencetak setiap elemen;
   }
   printf("\n");

   return 0;
}