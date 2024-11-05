#include <stdio.h>
#include <string.h>

struct Mahasiswa {
   char nama[50];
   int usia;
   float ipk;
};

union Data {
   int intVal;
   float floatVal;
   char charVal;
};

int main() {
   // Menggunakan struct
   struct Mahasiswa mhs1;
   strcpy(mhs1.nama, "Budi");
   mhs1.usia = 21;
   mhs1. ipk = 3.85;
   printf("Nama: %s, Usia:%d, IPK: %.2f\n", mhs1.nama, mhs1.usia, mhs1.ipk);

   // Menggunakan union
   union Data data1;
   data1.intVal = 90;
   printf("Nilai integer: %d\n", data1.intVal);

   data1.floatVal = 0.5;
   printf("Nilai float: %f\n", data1.floatVal);

   printf("Nilai integer setelah float ditulis: %d\n", data1.intVal); // Hasil: Tidak terduga

   return 0;
}