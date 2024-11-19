#include <stdio.h>
#include <string.h>

struct Mahasiswa {
    char nama[50];
    int nim;
    float ipk;
};

void inputData(struct Mahasiswa *mhs) {
    printf("Masukkan nama: ");
    fgets(mhs->nama, sizeof(mhs->nama), stdin);
    mhs->nama[strcspn(mhs->nama, "\n")] = '\0';

    printf("Masukkan NIM: ");
    scanf("%d", &mhs->nim);

    printf("Masukkan IPK: ");
    scanf("%f", &mhs->ipk);
    getchar();
}

void showingData(struct Mahasiswa *mhs) {
    printf("\nData yang dimasukkan\n");
    printf("Nama: %s\n", mhs->nama);
    printf("NIM: %d\n", mhs->nim);
    printf("IPK: %.2f\n", mhs->ipk);
}

int main() {
    struct Mahasiswa mhs1;

    inputData(&mhs1);
    showingData(&mhs1);

    return 0;
}