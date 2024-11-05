/*
   Mendefinisikan masalah
      Membuat program untuk akses dan modifikasi
      Elemen array dengan pointer
         1. Menginisialisasi sebuah array 
               int numbers[] = {10, 20, 30, 40, 50}
         2. Menggunakan pointer untuk mencetak semua elemen
            array
         3. Menggunakan pointer untuk menggandakan nilai
            setiap elemen dalam array
         4. Mencetak kembali elemen array setelah modifikasi
   
   Membuat model permasalahan
      - sizeof(numbers) / sizeof(numbers[0])
      - *ptr
      - *(ptr + i) = *(ptr + i) * 2
        *(ptr + i) *= 2
   
   Merancang algoritma pseudo-code
   START
   set function showingData(int *ptr, int length, char *word) as void
      showing "Elemen array [word] modifikasi" 
      for (i = 0; i < length; i++)
         showing "[*(ptr + i)] "
      end for
   end function showingData

   set function doubleQuote(int *ptr, int length) as int
      set for (i = 0; i < length; i++) {
         *(ptr + i) *= 2
      end for
   end function doubleQuote

   set main
      set int numbers[] = {10, 20, 30, 40, 50}
      set int length = sizeof(numbers) / sizeof(numbers[0])
      call function showingData(numbers, length, "sebelum")
      call function doubleQoute(numbers, length)
      call function showingData(numbers, length, "Sesudah")
   end main
   END
*/

//Menulis program
#include <stdio.h>

void showingData(int *ptr, int length, char *word) {
   printf("Elemen array %s modifikasi: ", word);
   for(int i = 0; i < length; i++) {
      printf("%d ", *(ptr + i));
   }
   printf("\n");
}

int doubleQuote(int *ptr, int length) {
   for (int i = 0; i < length; i++) {
      *(ptr + i) *= 2;
   }
}

int main() {
   int numbers[] = {10, 20, 30, 40, 50};
   int length = sizeof(numbers) / sizeof(numbers[0]);
   showingData(numbers, length, "sebelum");
   doubleQuote(numbers, length);
   showingData(numbers, length, "sesudah");

   return 0;
}
