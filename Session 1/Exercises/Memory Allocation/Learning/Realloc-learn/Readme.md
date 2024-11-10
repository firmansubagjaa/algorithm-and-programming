# Realloc
## 1. Apa itu realloc?
**realloc** adalah fungsi dalam bahasa C yang digunakan untuk **mengubah ukuran blok memori** yang sudah dialokasikan sebelumnya. Ini sangat berguna ketika kita memiliki array atua struktur data dinamis dan kita ingin memperbesar atau mengecilkan ukurannya selama program berjalan

## Sintaks realloc:
```c
ptr = realloc(ptr, ukuran_baru);
```
- **ptr**: Pointer yang sebelumnya menunjuk ke blok memori yang dialokasikan (menggunakan malloc, calloc, atau realloc).
- **ukuran_baru**: Ukuran memori baru yang diinginkan, biasanya dalam bentuk byte.

*realloc* akan mengalokasikan memori yang lebih besar atau lebih kecil, bergantung pada ukuran baru yang diberikan. Jika gagal dalam alokasi memori baru, ia akan mengembalikan *NULL*, dan memori lama tetap tidak berubah.

## Apa yang terjadi dengan *realloc*?
- **Jika Ukurang Bertambah**: *realloc* akan mencoba untuk memperbesar blok memori. Jika tidak dapat dilakukan dalam lokasi yang sama, maka ia akan mengalokasikan blok memori yang lebih besar, menyalin data dari blok lama ke blok baru, dan akhirnya membebaskan blok lama.
- **Jika Ukuran Berkurang**: *realloc* akan mengurangi ukuran blok memori. Sebagian memori yang sebelumnya dialokasikan akan dibebaskan.

## Contoh Penggunaan *realloc*
Berikut adalah contoh kode yang menggunakan *realloc* untuk mengubah ukuran array yang dialokasikan secara dinamis:
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n;

    // Alokasi memori awal dengan malloc
    printf("Masukkan jumlah elemen pertama: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        fprintf(stderr, "Alokasi memori gagal!\n");
        return 1;
    }

    // Mengisi nilai array
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    printf("Array setelah alokasi awal:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // Mengubah ukuran array menggunakan realloc
    printf("\nMasukkan jumlah elmeen baru: ");
    scanf("%d", &n);
    arr = (int *)realloc(arr, n * sizeof(int));

    if (arr == NULL) {
        fprintf(stderr, "Realokasi memori gagal!\n");
        return 1;
    }

    // Mengisi nilai baru dalam array
    for (int i = 0; i < n; i++) {
        arr[i] = (i + 1) * 10;
    }

    prinntf("Array setelah realokasi:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // Bebaskan memori yang dialokasikan
    free(arr);

    return 0;
}
```
### Penjelasan Kode:
1. **Alokasi Mmeori dengan *malloc***:
    - *arr = (int *)malloc(n * sizeof(int))*; digunakan untuk mengalokasikan memori untuk array dengan ukuran *n* elemen bertipe *int*.
2. **Mengisi dan Menampilkan Array**:
    - Array diisi dengna nilai dari 1 sampai *n*, kemudian ditampilkan.
3. **Mengubah Ukuran Array dengan *realloc***:
    - Setelah memasukkan jumlah elemen baru, kita menggunakan *realloc& untuk mengubah ukuran array menjadi ukuran yang baru, sesuai dengan input pengguna.
4. **Mengisi dan Menampilkan Array setelah *realloc***:
    - Array yang telah diperbesar (atau diperkecil) diisi dengna nilai baru dan ditampilkan.
5. **Bebaskan Memori**:
    - Setelah selesai, memori yang dialokasikan dibebaskan menggunakan *free*.

## Kelebihan dan kekurangan *realloc*:
- **Kelebihan**:
    - Memungkinkan kamu untuk mengubah ukuran blok memori yang sudah ada, menghindari kebutuhan untuk mengalokasikan ulang memori dan menyalin data secara manual.
    - Memudahkan penanganan data dianmis yang ukurannya tidak diketahui sebelumnya atau berubah-ubah.
- **Kekurangan**:
    - Jika *realloc* gagal, memori lama tetap tidak berubah dan kita harus menangani kasus tersebut dengan hati-hati.
    - Jika kita tidak menangani *NULL* dengan benar, kita bisa kehilangan referensi ke blok memori yang sudah dialokasikan (memory leak).

## Kapan Menggunakan *realloc*?
- **Diperlukan saat ukuran array atau struktur data berubah** selama *runtime* dan kamu ingin menghindari alokasi ulang dan salinan data manual.
- **Contoh**: Ketika kamu membuat aplikasi yang mengelola daftar elemen yang dapat ditambahkan atau dihapus secara dinamis (misalnya dalam aplikasi daftar belanja, permainan, atau aplikasi berbasis koelksi data).