# FUNCTION & RECURSION

## 1. Function

- **Pengertian**: sebuah _function_ adalah blok kode yang dirancang untuk melakukan tugas tertentu.
- Tujuan dari menggunakan fungsi **untuk memecah program yang kompleks menjadi bagian-bagian yang lebih kecil dan dapat dikelola, serta untuk menghindari penulisan kode yang berulang.**
- **Sintaks Dasar**

```c
return_type function_name(parameter_list) {
   // Body of the function
}
```

- **return_type**: Tipe data dari nilai yang dapat dikembalikan oleh fungsi. Misalnya
  - int
  - void
  - float, dll
- **function_name**: Nama fungsi yang diugnakan untuk memanggilnya.
- **parameter_list**: parameter (jika ada) yang diperlukan oleh fungsi. -**Contoh**:

```c
#include <stdio.h>

// Fungsi untuk menjumlahkan dua bilangan
int add(int a, int b) {
   return a + b
}

int main() {
   int result = add(5, 3);
   printf("Hasil penjumlahan: %d\n", result);
   return 0;
}
```

Pada contoh di atas, fungsi _add_ menerima dua parameter _a_ dan _b_, lalu mengembalikan hasil penjumlahannya.

## 2. Recursion

- **Pengertian:** _Recursion_ adalah teknik pemrograman di mana sebuah fungsi memanggil dirinya sendiri secara langsung atau tidak langsung untuk menyelesaikan suatu masalah yang lebih besar dengan memecahnya menjadi submasalah yang lebih kecil.
- Teknilk ini berguna untuk menyelesaikan masalah yang dapat dipecah menjadi beberapa bagian dengan pola yang berulang, seperti menghitung faktorial atau menyelasikan masalah deret Fibonacci.
- **Contoh Masalah Rekursif**
  - **Faktorial**: n! = n x (n-1) _ ... _ 1. Jika _n - 0_ atau _n - 1_, maka n1 = 1.
- **Contoh Kode:**

```c
#include <stdio.h>

// Fungsi rekursif untuk menghitung faktorial
int factorial(int n) {
   if (n == 0 || n == 1) {
      return 1; // Kasus dasar
   } else {
      return n * factorial(n - 1); Memanggil fngsi itu sendiri
   }

   int main() {
      int number = 5;
      printf("Faktorial dari %d adalah %d\n", numebr, factorial(number));
      return 0;
   }
}
```

Pda contoh ini, fungsi _faktorial_ memanggil dirinya sendiri dengan _n - 1_ hingga mencapai base case di mana _n_ sama dengan 0 atau 1.

## Poin Penting yang harus Dipahami

1. **Function** membantu kode lebih modular dan mudah dikelola.
2. **Recursion** sangat kuat, tetapi juga memiliki risiko seperti _stack overflow_ jika tidak diimplementasikan dengan base case yang benar.
3. Pahamai bagaimana _recursion_ bekerja dengan memvisualisasikan setiap langkah pemaggilan fungsi, yang dapat membantu dalam debugging.
