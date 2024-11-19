/*
    Soal 2: Mengakses Elemen array dengan Pointer

    Definisi masalah
    Membuat program untuk mengakses array dengan menggunakan pointer tanpa menggunakan indeks memori.

    Membuat model
    - array of number with length 5 index static
    - insert array elements = {10, 20, 30, 40, 50}

    Merancang algoritma
    START
        SET ARRAY AS INTEGER "NUMS" WITH ELEMENTS 10,20,30,40,50
        SET POINTER *ptr FROM VARIABLE NUMS

        SET FOR (i = 0; i < 5; i++)
            SHOWING "Element ke-[i + 1]: [ptr + i]"
        END FOR
    END

    MEMBUAT PROGRAM
*/
#include <stdio.h>

int main() {
    int nums[5] = {10, 20, 30, 40, 50};
    int *ptr = nums;

    for (int i = 0; i < 5; i++) {
        printf("Element ke-%d: %d\n", i + 1, *(ptr + i));
    }
    return 0;
}