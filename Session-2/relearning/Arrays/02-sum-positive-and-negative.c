#include <stdio.h>


int main() {
    int nums[5] = {10, -5, -9, 9, 30};
    int totalPositive = 0, totalNegative = 0;
    int size = sizeof(nums)/ sizeof(nums[0]);


    for (int i = 0; i < size; i++) {
        if (nums[i] > 0) {
            totalPositive++;
        } else {
            totalNegative++;
        }
    }
    printf("Jumlah nilai positif di dalam array adalah: %d\n", totalPositive);
    printf("Jumlah nilai negatif di dalam array dalah: %d\n", totalNegative);

    return 0;
}