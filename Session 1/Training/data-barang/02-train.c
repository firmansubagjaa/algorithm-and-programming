#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Barang {
    char nama[50];
    unsigned int stok;
    float harga;
};

FILE *openFile(const char filename) {
    FILE *check = fopen(filename, "r");
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Terjadi kesalahan.");
        return NULL;
    }
    
}