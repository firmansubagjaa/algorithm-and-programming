#include <stdio.h>
#include <stdlib.h>

void doubleValue(int **ptr) {
    int y = 2;
    **ptr *= y;
}

int main() {
    int x = 30;
    int *ptr = &x;

    printf("Sebelum: %d\n", *ptr);

    doubleValue(&ptr);

    printf("Sesudah: %d\n", *ptr);
    return 0;
}