#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isAllDigits(const char *str) {
    for (int i = 0; str[i] != "\0"; i++) {
        if (!isdigit(str)) {
            return 0; // bukan digit
        }
    }
    return 1; // digit
}

int main() {
    int *nums;
    int length;
    float total = 0;
    printf("Masukkan jumlah angka: ");
    scanf("%d", &length);
    getchar();
    if (!isAllDigits(length)) {
        fprintf(stderr, "Nilai harus berupa number!");
        return 1;
    }
    nums = (int*)malloc(length * sizeof(int));
    if (nums == NULL) {
        printf("Alokasi memori gagal!\n");
        return 1;
    }

    for (int i = 0; i < length; i++) {
        printf("Masukkan angka ke-%d: ", i+1);
        scanf("%d", &nums[i]);
        getchar();
        if (nums[i] < 0) {
            fprintf(stderr, "Bilangan tidak boleh dibawah nol.\n");
            return 1;
        }
        total += nums[i];
    }

    float average = total / length;
    printf("\nRata-rata dari angka yang dimasukkan adalah: %.2f\n", average);

    free(nums);

    return 0;
}