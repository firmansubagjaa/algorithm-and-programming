#include <stdio.h>

int main() {
    int x = 5;
    int *ptr = &x;

    printf("Nilai tunggal pointer: %d\n", *ptr);
    return 0;
}