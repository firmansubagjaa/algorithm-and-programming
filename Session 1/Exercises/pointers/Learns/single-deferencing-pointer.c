#include <stdio.h>

int main() {
    int x = 10;     // variabel x menyimpan nilai 10
    int *ptr = &x;  // pointer ptr menyimpan alamat memori x

    printf("Nilai x: %d\n", x); // output 10
    printf("Alamat yang disimpan di ptr: %p\n", (void *)ptr); // output : alamat x
    printf("Nilai yang ditunjuk ptr: %d\n", *ptr); //output: 10
    return 0;
}