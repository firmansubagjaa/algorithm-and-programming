# Memory Allocation

## 1. Apa itu Memory Allocation?
**Memory Allocation** adalah proses pengalokasian ruang di memori komputer untuk menyimpan data saat program berjalan. Di C, ada dua jenis utama dari memory allocation:
1. **Static Memory Allocation**: Memori dialokasikan saat kompilasi ( *compile-time* ). Misalnya, variabel lokal atau variabel dengan ukuran tetap yang dideklarasikan di dalam suatu fungsi.
2. **Dynamic Memory Allocation**: Memori dialokasikan saat program berjalan (*run-time*), memungkinkan kita mengalokasikan memori sesuai kebutuhan. Tekni ini dilakukan mengugnakan fungsi seperti **malloc**, **calloc**, **realloc**, dan **free**.

## 2. Static vs Dynamic Memory Allocation
- **Static**: Ukuran memori tetap dan tidak bisa diubah selama program berjalan.
- **Dynamic**: Ukuran memori bisa disesuaikan saat program berjalan, berguna untuk data yang ukurannya berubah-ubah.

## 3. Fungsi Dynamic Memori Allocation dalam C
- **Malloc (Memory Allocation)**: Mengalokasikan blok memori mentah dengan ukuran tertentu.
    ```c
    int *arr = (int *) malloc(5 * sizeof(int)); // Mengalokasikan memori untuk array 5 elemen
    ```
- **calloc (Contigouous Allocation)**: Mengalokasi blok memori dan menginisialisasi semuanya ke nol.
    ```c
    int *arr = (int*) calloc(5, sizeof(int)); // Array 5 elemen, semuanya diinisialisasi ke 0
    ```
- **realloc (Reallocation)**: Mengubah ukuran bok memori yang sudah dialokasikan.
    ```c
    arr = (int*) realloc(arr, 10 * sizeof(int)); // Ubah ukuran array jadi 10 elemen
    ```
- **free**: Melepaskan atua mengembalikan memori yang sudah tidak diperlukan lagi.
    ```c
    free(arr); // Melepaskan memori yang dialokasikan ke arr
    ```

## 4. Pentingnya Memory Management
- **Efisiensi Memori**: Menggunakan memori sesuai kebutuhan membantu program lebih efisien dan tidak boros.
- **Menghindari Memory Leak**: Jika memori dialokasikan tapi tidak dibebaskan, maka akan ada "kebocoran memori", dimana memori tidak bisa digunakan kembali, menyebabkan program lambat atau crash.
- **Optimasi Akses Memori** Membantu program mengakses data yang tersimpan di memori dengan lebih cepat.

## Pertanyaan
### Definisi Memory Allocation
1. Definisi Memory Allocation itu proses pengalokasian ruang di memori komputer untuk menyimpan data saat program berjalan, nah menyimpan data berupa apa aja?