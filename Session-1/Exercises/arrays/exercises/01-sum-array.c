#include <stdio.h>

// Fungsi untuk menghitung jumlah elemen dalam array
int sumArrays(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(arr + i); // Menggunakan *(arr + i) untuk menjumlahkan elemen ke-i
    }
    return sum;
}

// Fungsi untuk menambah 1 pada setiap elemen array
void incrementArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        *(arr + i) += 1;
    }
}

int main() {
    int numbers[] = {2, 4, 6, 8, 10};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    // Memanggil fungsi untuk menambah 1 pada setiap elemen array
    incrementArray(numbers, size);

    // Memanggil fungsi untuk menghitung jumlah total elemen array
    int total = sumArrays(numbers, size);
    printf("Jumlah total array setelah perubahan: %d\n", total);

    // Mencetak nilai array setelah diubah
    printf("Nilai array sesudah berubah:\n");
    for (int i = 0; i < size; i++) {
        printf("Nilai ke-%d: %d\n", i + 1, numbers[i]);
    }

    return 0;
}