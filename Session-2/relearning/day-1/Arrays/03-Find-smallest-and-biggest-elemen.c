#include <stdio.h>

int main() {
    int size;

    printf("Masukkan panjang array: ");
    scanf("%d", &size);

    int nums[size];
    
    for(int i = 0; i < size; i++) {
        printf("Masukkan element ke-%d: ", i + 1);
        scanf("%d", &nums[i]);
    }
    getchar();

    printf("\nNilai array yang sudah dimasukkan: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    int min = nums[0];
    int max = nums[0];
    for (int i = 1; i < size; i++) {
        if (nums[i] < min) {
            min = nums[i];
        }
        if (nums[i] > max) {
            max = nums[i];
        }
    }

    printf("\nElemen terkecil di array nums: %d\n", min);
    printf("\nElemen terbesar di array nums: %d\n", max);

    return 0;
}