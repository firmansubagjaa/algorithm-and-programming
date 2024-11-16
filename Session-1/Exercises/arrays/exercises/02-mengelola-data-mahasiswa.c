#include <stdio.h>
#include <string.h>

#define MAX 3

struct Mahasiswa {
    char nama[50];
    int nim;
    float nilai;
};

void printfMahasiswa(struct Mahasiswa *mhs, int size) {
    for (int i = 0; i < size; i++) {
        printf("Mahasiswa %d:\n", i+1);
        printf("Nama: %s\n", (mhs + i)->nama);
        printf("NIM : %d\n", (mhs + i)-> nim);
        printf("Nilai: %.2f\n", (mhs + i)->nilai);
    }
}

float hitungRataNilai(struct Mahasiswa *mhs, int size) {
    float totalNilai = 0.0;
    for (int i = 0; i < size; i++) {
        totalNilai += (mhs + i)->nilai;
    }
    return totalNilai / size;
}

int main() {
    struct Mahasiswa data[MAX];

    for (int i = 0; i < MAX; i++) {
        printf("Masukkan data mahasiswa %d\n", i+1);
        printf("Nama : ");
        fgets(data[i].nama, sizeof(data[i].nama), stdin);
        data[i].nama[strcspn(data[i].nama, "\n")] = '\0';

        printf("NIM : ");
        scanf("%d", &data[i].nim);

        printf("Nilai : ");
        scanf("%f", &data[i].nilai);
        
        getchar();
    }

    printf("Data Mahasiswa:\n");
    printfMahasiswa(data, MAX);

    float rataNilai = hitungRataNilai(data, MAX);
    printf("Rata-rata nilai: %.2f\n", rataNilai);

    return 0;
}