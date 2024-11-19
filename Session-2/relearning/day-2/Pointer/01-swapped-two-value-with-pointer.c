#include <stdio.h>
#include <stdlib.h>

void swapped(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    int num1 = 5;
    int num2 = 7;
    int *ptr1 = &num1;
    int *ptr2 = &num2;

    printf("Nilai sebelum di tukar:\n");
    printf("num1: %d\n", *ptr1);
    printf("num2: %d\n", *ptr2);

    swapped(ptr1, ptr2);
    printf("\nNilai sesudah di tukar:\n");

    printf("num1: %d\n", *ptr1);
    printf("num2: %d\n", *ptr2);
    return 0;
}