#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int length;
    int *nums;
    printf("Masukkan berapa banyak nilai yang akan dimasukkan: ");
    scanf("%d", &length);
    getchar();
    
    nums = (int*)malloc(length * sizeof(int));

    printf("\nMasukkan angka:\n");
    for (int i = 0 ; i < length; i++) {
        printf("Masukkan angka ke-%d: ", i+1);
        scanf("%d", &nums[i]);
        if (nums[i] < 0) {
            fprintf(stderr, "Bilangan tidak boleh kurang dari nol!");
            return 1;
        }
    }
    getchar();

    printf("\nMenampilkan angka yang telah dimasukkan:\n");
    for (int i = 0; i < length; i++) {
        printf("Angka ke-%d: %d\n", i+1, nums[i]);
    }

    return 0;
}