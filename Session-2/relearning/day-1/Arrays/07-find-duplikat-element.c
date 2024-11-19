#include <stdio.h>
#include <stdlib.h>

void sortArray(int *arr, int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int main() {
    int size;
    int *nums;

    // Menentukan panjang element
    printf("Section to input length of array\n");
    printf("Masukkan panjang array: ");
    scanf("%d", &size);

    // Error handling jika size kurang dari 0
    if (size < 0) {
        fprintf(stderr, "Nilai tidak boleh kurang dari 0!\n");
        return 1;
    }

    // Membuat dan menentukan panjang array nums
    nums = (int *)malloc(size * sizeof(int));
    if (nums == NULL) {
        fprintf(stderr, "Gagal mengalokasi memori!\n");
        return 1;
    }

    // Memasukkan beberapa elemen ke array
    printf("\nSection input elements to array\n");
    for(int i = 0; i < size; i++) {
        printf("Masukkan elemen ke-%d: ", i + 1);
        scanf("%d", &nums[i]);
    }

    // Menampilkan array sesudah dimasukkan
    printf("\nSection showing array\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(nums + i));
    }
    printf("\n");

    // Mengurutkan elemen dari nilai terkecil ke terbesar
    sortArray(nums, size);

    // Menampilkan elemen sesudah mengurutkan
    printf("\nAfter Sorting an array\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(nums + i));
    }
    printf("\n");


    
    printf("\nSection for duplicate element\n");
    int hasDuplicate = 0;
    for (int i = 0; i < size - 1; i++) {
        if (*(nums + i) == *(nums + i + 1)) {
            printf("Ditemukan duplikat: %d\n", *(nums + i));
            hasDuplicate = 1;
        }
    }
    
    if (!hasDuplicate) {
        printf("Tidak ditemukan elemen duplikat\n");
    }

    free(nums);
    return 0;
}