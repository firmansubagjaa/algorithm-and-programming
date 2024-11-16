#include <stdio.h>
#include <stdlib.h>

void increment(int *ptr) {
    printf("Angka sebelum melakukan aritmatika: %d\n", *ptr);
    *ptr += 1;
    printf("Angka sesudah melakukan aritmatika: %d\n", *ptr);
}

int main() {
    int x = 8;
    int *ptr = &x;
    increment(ptr);
    return 0;
}