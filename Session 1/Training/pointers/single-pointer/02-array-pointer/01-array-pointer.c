#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr;
    int size = sizeof(arr) / sizeof(arr[0]);
    int i = 0;

    printf("Mencetak array dengan pointer: ");
    while(i < size) {
        printf("%d ", *(ptr + i));
        (ptr)++;
    }
    return 0;
}