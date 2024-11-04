#include <stdio.h>

int main() {
   // int numbers[] = {10, 20, 30, 40, 50}; // Panjang array otomatis dihitung sebagai 5
   int numbers[5] = {10, 20, 30, 40, 50}; // Panjang array set manual dengan panjang elemen sebesar 5 elemen

   // Menampilkan panjang array
   int length = sizeof(numbers) / sizeof(numbers[0]);
   printf("Panjang array: %d\n", length);

   return 0;
}