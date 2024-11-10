#include <stdio.h>
#include <stdlib.h>

int main() {
    int *numbers;
    int size = 2;
    int count = 0;
    int input;

    // Alokasi emmori awal untuk 2 elemen;
    numbers = (int *)malloc(size * sizeof(int));
    if (numbers == NULL) {
        fprintf(stderr, "Alokasi memori gagal!\n");
        return 1;
    }

    printf("Masukkan bilangan bulat (ketik -1 untuk berhenti):\n");

    while (1) {
        printf("Input: ");
        scanf("%d", &input);

        // Jika pengguna memasukkan -1, keluar dar loop
        if (input == -1) {
            break;
        }

        // Jika array penuh, alokasikan lebih banyak memori
        if (count == size) {
            size += 2;
            numbers = (int *)realloc(numbers, size * sizeof(int));
            if (numbers == NULL) {
                fprintf(stderr, "Realokasi memori gagal!\n");
                return 1;
            }
        }

        // Tambah input ke dalam array
        numbers[count] = input;
        count++;
    }

    // Cetak semua bilanga bulat yang dimasukkan
    printf("\nBilangan yang dimasukkan:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Bebaskan memori yang telah dialokasikan
    free(numbers);

    return 0;
}