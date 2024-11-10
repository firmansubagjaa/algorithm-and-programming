#include <stdio.h>

// Fungsi untuk menukar dua nilai
void tukar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x, y;
    printf("Masukkan nilai x: ");
    scanf("%d", &x);
    printf("Masukkan nilai y: ");
    scanf("%d", &y);

    printf("Sebelum ditukar: x = %d, y = %d\n", x, y);
    tukar(&x, &y);
    printf("Setelah ditukar: x = %d, y = %d\n", x, y);

    return 0;
}
