# STRUCTURES AND UNION

## 1. Struct (Struktur)

- **Pengertian**:
  - tipe data yang memungkinkan kamnu mengelompokkan beberapa variabel dengan tipe yang berbeda dalam satu unit.
  - Ini sangat berguna ketika kita ingin merepresentasikan object yang memiliki beberapa atribut. BErikut adalah penjelasan dan contoh penggunaan struct
    1. **Definisi Struct**: Untuk mendefinisikan struct, kamu menggunakan kata kunci _struct_, diikuti oleh nama struct dan daftar anggota di dalam kurung kurawal.
    ```c
    struct Mahasiswa {
       char nama[50];
       int usia;
       float ipk;
    }
    ```
    2. **Membuat Variable Struct**: Setelah mendefinisikan struct, kamu bisa membuat varabel dari tipe struct tersebut.
    ```c
    struct Mahasiswa mhs1;
    ```
    3. **MEngakss Anggota Struct**: KIta bisa mengakses anggota struct menggunakan operator titik ( . ).
    ```c
    strcpy(mhs1.nama, "Andi");
    mhs1.usia = 20;
    mhs1.ipk = 3.75;
    ```

## Union (Unis)

**Pengertian**: **Union** juga mirip dengan **struct**, tetapi hanya menyimpan satu nilai dari beberapa kemungkinan pada satu waktu. Ukuran union adalah ukurang anggota terbesar, karena semua anggota menggunakan ruang memori yang sama.

1. **Definisi Union**: Seperti struct, union juga didefinisikan dengan kata kunci _union_.
   ```c
   union Data {
      int intVal;
      float floatVal;
      char charVal;
   }
   ```
2. **Membuat Variabel Union**: Kitabisa membuat varabel union seperti ini:
   ```c
   union Data data1;
   ```
3. **Mengakses Anggot Union**: Kita uga menggunakan operator titik untuk mengakses anggot union, tetapi ingat bahwa hanya satu anggota yang daapat menyimpan nilai pada satu waktu.

   ```c
   data1.intVal = 10; // Menyimpan integer
   printf("%d\n", data1.intVal);

   data1.floatVal = 15.5; // Menyimpan float
   printf("%d\n", data1.floatVal); // Nilai dari intVal tidak valid lagi
   ```

   ## Perbedaan Antara Struct dan Union

   - Penggunaan Memori:
     - **Struct**: Setiap anggota memiliki ruang memori sendiri. Ukuran struct adalah total ukuran semua anggotanya.
     - **Union**: Semua anggota berbagi ruang meori yang sama. Ukuran union adalah ukuran anggota terbesar.
   - Akses Anggota:
     - Di struct, semua anggota dapat diakses secara bersamaan dan memiliki nilai yang valid.
     - Di union, hanya satu anggota yang dapat memiliki nilai yang valid pada satu waktu.

## Contoh Penggunaan

Berikut adalah contoh program sederhana menggunakan struct dan union:

```c
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
   mhs1.ipk = 3.85;
   printf("Nama: %s, Usia: %d, IPK: %.2f\n", mhs1.nama, mhs1.usia, mhs1.ipk);

   // Menggunakan union
   union Data data1;
   data1.intVal = 100;
   printf("Nilai integer: %d\n", data1.intVal);

   data1.floatVal = 9.5;
   printf("Nilai float: %f\n", data1.floatVal); // integer value is now invalid

   return 0;
}
```
