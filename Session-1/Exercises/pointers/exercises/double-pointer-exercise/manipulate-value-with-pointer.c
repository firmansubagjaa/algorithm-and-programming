#include <stdio.h>

void ubahNilai(int **ptr, int nilaiBaru) {
    **ptr = nilaiBaru;
}

int main() {
    int x = 10;
    int *ptr = &x;
    int **ptr2 = &ptr;

    printf("Nilai belum berubah: %d\n", **ptr2);

    ubahNilai(ptr2, 50);

    printf("Nilai sesudah berubah: %d\n", **ptr2);

    return 0;
}