#include <stdio.h>
#include <stdlib.h>

int main() {
    int *nums;
    int *reverseNums;
    int size;

    printf("Masukkan panjang array: ");
    scanf("%d", &size);
    printf("\n");


    nums = (int *)malloc(size * sizeof(int));
    if (nums == NULL) {
        fprintf(stderr, "Gagal mengalokasi memori!\n");
        return 1;
    }

    for(int i = 0; i < size; i++) {
        printf("Masukkan element ke-%d: ", i + 1);
        scanf("%d", &nums[i]);
    }
    getchar();

    printf("\nElement-element sebelum di-reverse: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", *(nums + i));
    }

    reverseNums = (int *)malloc(size * sizeof(int));
    if (reverseNums == NULL) {
        fprintf(stderr, "Gagal mengalokasi memori!\n");
        return 1;
    }
    printf("\n");

    for(int i = size - 1, j = 0; i >= 0; i--, j++) {
        reverseNums[j] = nums[i];
    }  

    printf("Element-element sesudah di-reverse: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", reverseNums[i]);
    }
    printf("\n\n");

    return 0;
}