#include <stdio.h>

int main() {
   int numbers[5]; // Deklarasi array dengan ukuran 5

   // Mengisi array dengan nilai
   for (int i = 0; i < 5; i++) {
      printf("Masukkan nilai untuk elemen ke-%d: ", i);
      scanf("%d", &numbers[i]); // Mengisi elemen array dengan input dari pengguna
   }

   // Menampilkan elemen-elemen array
   printf("\n\nElemen-elemen dalm array adalah:\n");
   for (int i = 0; i < 5; i++) {
      printf("Elemen ke-%d: %d\n", i, numbers[i]);
   }

   return 0;
}