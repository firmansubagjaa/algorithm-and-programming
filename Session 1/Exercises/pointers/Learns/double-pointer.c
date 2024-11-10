#include <stdio.h>


int main() {
    int x = 10;
    int *ptr = &x;

    // Cek alamat
    printf("Alamat x: %p\n", (void *)&x);
    printf("Alamay yang disimpan di ptr: %p\n", (void *)ptr);

    // Cek nilai dengan dereferencing
    printf("Nilai x: %d\n", x);
    printf("Nilai yang ditunjuk ptr: %d\n", *ptr);

    return 0;
}