#include <stdio.h>

void doubleValue(int *ptr) {
   *ptr *= 2; // Mengalikan nilai yang ditunjuk oleh ptr dengan 2
}

int main() {
   int num = 10;
   printf("Nilai awal: %d\n", num);

   // Menggunakan pointer untuk mengubah nilai
   doubleValue(&num); // Mengirimkan alamat dari num

   printf("Nilai setelah diubah: %d\n", num);

   return 0;
}