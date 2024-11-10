#include <stdio.h>

int ubahNilai(int **ptr2) {
    **ptr2 = 50;
}

int main() {
    int x;

    printf("Masukkan angka: ");
    scanf("%d", &x);

    int *ptr = &x;
    int **ptr2 = &ptr;

    printf("\nSebelum diubah: %d\n", **ptr2);

    ubahNilai(ptr2);

    printf("Sesduah diubah: %d\n", **ptr2);

    return 0;
}