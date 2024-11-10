#include <stdio.h>

void ubahNilai(int **ptr2) {
    **ptr2 = 100;
}

int main() {
    int x = 5;
    int *ptr = &x;
    int **ptr2 = &ptr;

    printf("Sebelum diubah: x = %d\n", x);

    ubahNilai(ptr2);

    printf("Setelah diubah: x = %d\n",x);

    return 0;
}