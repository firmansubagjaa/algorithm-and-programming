#include <stdio.h>

// Fungsi untuk menggandakan setiap elemen dalam array
void doubleArray(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      *(arr + i) *= 2; // Mengalikan elemen ke-i dengan 2
   }
}

int main() {
   int numbers[] = {1,2,3,4,5};
   int size = sizeof(numbers) / sizeof(numbers[0]);

   printf("Array sebelum diubah: ");
   for (int i = 0; i < size; i++) {
      printf("%d ", numbers[i]);
   }
   printf("\n");

   // Menggunakan pointer untuk menggandakan setiap elemen
   doubleArray(numbers, size); // Mengirimkan alamat dari array

   printf("Array setelah diubah: ");
   for (int i = 0; i < size; i++) {
      printf("%d", numbers[i]);
   }
   printf("\n");
   return 0;
}