/*
    Soal 3: Menemukan Elemen Maksimum dalam Array

    Definisi masalah
    Membuat program untuk menemukan elemen maksimum dari sebuah array menggunakan pointer. Input array dapat diisi secara dinamis oeh pengguna

    Membuat model
    int *nums
    int size
    int max = 0;

    Merancang algoritma
    START
        set pointer nums, size, max = 0 as integer
        showing "Masukkan panjang array: "
        read size

        set nums = (int *)malloc(size * length of integer)
        set if nums equal to NULL
            showing error "Gagal untuk alokasi memori!"
            returning 1
        end if

        set for (integer  i = 0; i lower than size; sum i + 1) 
            showing "Masukkan elemen ke-[i+1]: "
            read nums by index
        end for

        set for(integer i = 0; i lower than size; sum i + 1)
            if (nums[i] < max)
                set max = nums[i]
            end if
        end for

        showing "Nilai terbesar dari nums yang sudah dinputkan: [max]"
    END

    Menulis program
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *nums, size, max;

    printf("Masukkan panjang array: ");
    scanf("%d", &size);

    nums = (int *)malloc(size * sizeof(int));
    if (nums == NULL) {
        fprintf(stderr, "Gagala untuk mengalokasikan memori!\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        printf("Masukkan elemen ke-%d: ", i + 1);
        scanf("%d", &nums[i]);
    }

    max = nums[0];

    for (int i = 1; i < size; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }

    printf("Nilai terbesar dari nums yang sudah diinputkan: %d", max);


    free(nums);
    return 0;
}