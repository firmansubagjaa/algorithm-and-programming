#include <stdio.h>

int main() {
   int numbers[] = {10, 20, 30, 40, 50};
   int leng = sizeof(numbers) / sizeof(numbers[0]);
   int *ptr = numbers;// Pointer ke elemen pertama array

   // Menampilkan elemen array menggunakan pointer aritmetic
   printf("Elemen pertama: %d\n", *ptr);        // Output: 10
   printf("Elemen kedua: %d\n", *(ptr + 1));    // Output: 20
   printf("Elemen ketiga: %d\n",  *(ptr + 2));  // Output: 30
   printf("\n");
   
   // Menggunakan looping untuk menampilkan seluruh elemen array
   for (int i = 0; i < leng; i++) {
      printf("Elemen ke-%d: %d\n", i + 1, *(ptr + i));
   }
   return 0;
}