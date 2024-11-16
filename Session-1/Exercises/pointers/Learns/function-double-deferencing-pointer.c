#include <stdio.h>

void ubahPointer(int **ptr2, int *nilaiBaru) {
    *ptr2 = nilaiBaru;
}

int main() {
    int a = 10, b = 20;
    int *ptr = &a;

    printf("Nilai yang ditunjuk ptr sebelum perubahan: %d\n", *ptr);

    ubahPointer(&ptr, &b);
    printf("Nilai yang ditunjuk ptr setelah perubahan: %d\n", *ptr);
    return 0;
}