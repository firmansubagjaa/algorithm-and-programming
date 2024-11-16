/*
   Mendefinisikan masalah
      Membuat program untuk menghitung jumlah elemen
      array dengan pointer dengan spesifikasi requirements:
         1. Meminta pengguna untuk memasukkan panjang
            array.
         2. Meminta pengguna untuk mengisi elemen array.
         3. Menggunakan pointer untuk menghitung jumlah
            semua elemen dalam array.
      Contoh output
         Masukkan panjang array: 5
         Masukkan elemen array: 1 2 3 4 5
         Jumlah semua elemen dalam array adalah: 15
   
   Membuat model masalah
   set total as integer
   total += *(ptr + i)

   Merancang algoritma dengan pseudocode
   START
      set function sumArray(int *numbers, int size) as int
         set total = 0
         set for(i = 0; i < size; i++)
            total = total + *(ptr + i)
         end for

         return total
      end function

      set function main as integer
         set size as int
         showing "Masukkan panjang array: "
         get input size from user
         set numbers[size] as int
         showing "Masukkan elemen array: "
         set for (i = 0; i < size; i++) 
            get input numbers[] from user
         end for
         set result = sumArray(numbers, size) as int
         showing "Jumlah semua elemen dalam array adalah: [result]"
         return 0
      end main
   END
*/
#include <stdio.h>

int sumArray(int *numbers, int size) {
   int total = 0;
   for (int i = 0; i < size; i++) {
      total += *(numbers + i);
   }
   return total;
}

int main() {
   int size;
   printf("Masukkan panjang array: ");
   scanf("%d", &size);
   int numbers[size];
   printf("Masukkan elemen array: ");
   for (int i = 0; i < size; i++) {
      scanf("%d", &numbers[i]);
   }
   int result = sumArray(numbers, size);
   printf("Jumlah elemen dalam array adalah: %d", result);

   return 0;
}