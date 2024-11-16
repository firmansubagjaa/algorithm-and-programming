#include <stdio.h>

int main() {
    int x = 25;
    int *ptr = &x;
    int **ptr2 = &ptr;

    // printf("Nilai yang ditunjuk ptr: %d\n", *ptr);

    printf("Nilai yang ditunjuk ptr2: %d\n", *ptr2);

    return 0;
}