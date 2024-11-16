#include <stdio.h>

struct Car {
   char brand[100];
   int year;
};

int main() {
   struct Car cars[3];

   for (int i =0; i < 3; i++) {
      printf("Masukkan merek mobil %d: ", i + 1);
      scanf("%s", cars[i].brand);
      printf("Masukkan tahun mobil %d: ", i + 1);
      scanf("%d", &cars[i].year);
   }

   printf("\nData mobil yang dimasukkan:\n");
   for (int i = 0; i < 3; i++) {
      printf("Mobil %d: Merek %s, tahun: %d\n", i + 1, cars[i].brand, cars[i].year);
   }
   return 0;
}