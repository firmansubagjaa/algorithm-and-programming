#include <stdio.h>

int main() {
    int size;

    printf("Masukkan ukuran panjang array: ");
    scanf("%d", &size);

    int nums[size];
    for (int i = 0; i < size; i++) {
        printf("Masukkan elemen ke-%d: ", i + 1);
        scanf("%d", &nums[i]);
    }
    getchar();

    printf("\nBentuk awal elemen array yang belum disisipkan: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n\n");

    int newElement;
    int position;
    printf("Nilai elemen yang akan disisipkan ke array nums: ");
    scanf("%d", &newElement);
    printf("Masukkan posisi indeks yang akan disisipkan: ");
    scanf("%d", &position);

    if (position < 1 || position > size + 1) {
        printf("Posisi tidak valid!\n");
        return 1;
    }

    for (int i = size; i >= position; i--) {
        nums[i] = nums[i - 1];
    }

    nums[position - 1] = newElement;
    size++;

    printf("\nArray setelah penyisipan: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n\n");
    
    return 0;
}