#include <stdio.h>


int main() {
    int x = 10;         // variabel x menyimpan nilai 10 
    int *ptr = &x;      // pointer ptr menyimpan alamat memori x
    int **ptr2 = &ptr;  // pointer ptr2 menyimpan alamat memori ptr

    printf("Nilai x: %d\n", x);     // output: 10;
    printf("Alamat ptr: %p\n", (void*)ptr);     // output: alamat x
    printf("Alamat ptr2: %p\n", (void *)ptr2);
    printf("Nilai yang ditunjuk ptr2: %d\n", **ptr2); // Ouptut: 10
   return 0;
}