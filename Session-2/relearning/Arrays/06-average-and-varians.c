#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int *nums;
    int size;

    printf("Masukkan jumlah elemen array: ");
    scanf("%d", &size);

    if (size <= 0) {
        fprintf(stderr, "Jumlah elemen harus lebih dari 0!\n");
        return 1;
    }

    nums = (int *)malloc(size * sizeof(int *));
    if (nums == NULL) {
        fprintf(stderr, "Gagal mengalokasi memori!\n");
        return 1;
    }

    double sum = 0.0, mean = 0.0, variance =0.0;

    printf("Masukkan elemen array:\n");
    for (int i = 0; i < size; i++) {
        printf("Elemen ke-%d: ", i + 1);
        scanf("%d", &nums[i]);
        sum += *(nums + i);
    }

    mean = sum / size;

    for (int i = 0; i < size; i++) {
        variance += pow(*(nums + i) - mean, 2);
    }
    variance /= size;

    printf("\nRata-rata: %.2lf\n", mean);
    printf("Varians: %.2lf\n", variance);

    return 0;
}