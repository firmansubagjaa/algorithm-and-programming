#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 1;
    int *ptr = &x;

    printf("Alamat memori x: %p\n", (void*)&x);
    printf("Alamat memori ptr: %p\n", (void*)&ptr);

    return 0;
}