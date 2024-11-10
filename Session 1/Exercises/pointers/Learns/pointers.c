#include <stdio.h>

// tanpa pointer
// void doubleValue(int value) {
//    value = value * 2; // Menggandakan nilai
// }

// dengan pointer

void doubleValue(int *ptr) {
   *ptr = *ptr * 2; // Mengandakan nilai yang ditunjuk oleh ptr
}

int main() {
   int num = 5;// Nilai awal
   doubleValue(&num); // Memanggil fungsi
   printf("Niali di luar fungsi: %d\n", num); // Output
   return 0;
}