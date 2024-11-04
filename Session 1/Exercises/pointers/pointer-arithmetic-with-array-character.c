#include <stdio.h>

int main() {
   char str[] = "Hello";
   char *ptr = str; // Pointer ke elemen pertama dari string

   // Menampilkan karakter satu per satu menggunakan pointer arithmetic
   while(*ptr != '\0') {
      printf("%c ", *ptr);
      ptr++;
   }

   return 0;
}