#include <stdio.h>
#include <string.h>

struct Product {
    int code;
    char name[50];
    float price;
    int stock;
};

void inputProducts(struct Product *product, int qty) {
   for(int i = 0; i < qty; i++) {
    printf("\nData Produk ke-%d\n", i+1);
    printf("Kode produk: ");
    scanf("%d", &product[i].code);
    getchar(); // Clear input buffer
    printf("Nama produk: ");
    fgets(product[i].name, sizeof(product[i].name), stdin);
    product[i].name[strcspn(product[i].name, "\n")] = 0;
    printf("Harga: ");
    scanf("%f", &product[i].price);
    printf("Stok: ");
    scanf("%d", &product[i].stock);
    getchar(); // Clear input buffer
   } 
}

void displayProducts(struct Product *product, int qty) {
    printf("\nDaftar Produk:\n");
    for(int i = 0; i < qty; i++) {
        printf("Kode: %d, Nama: %s, Harga: %.2f, Stok: %d\n", product[i].code, product[i].name, product[i].price, product[i].stock);
    }
}

int sellProduct(struct Product *product, int qty){
    int code;
    int buyerQty;
    printf("\nMasukkan kode produk yang ingin dibeli: ");
    scanf("%d", &code);
    printf("Jumlah yang ingin dibeli: ");
    scanf("%d", &buyerQty);
    for (int i = 0; i < qty; i++) {
        if (code == product[i].code) {
            product[i].stock -= buyerQty;
            return 0;
        }
    }
    fprintf(stderr, "Produk tidak tersedia");
    return 1;
}

int updateStock(struct Product *product, int qty){
    int code;
    int addStock;
    printf("\nMasukkan kode produk yang ingin dibeli: ");
    scanf("%d", &code);
    printf("Jumlah yang ingin dibeli: ");
    scanf("%d", &addStock);
    for (int i = 0; i < qty; i++) {
        if (code == product[i].code) {
            product[i].stock += addStock;
            return 0;
        }
    }
    fprintf(stderr, "Produk tidak tersedia");
    return 1;
}

void displayRestockProduct(struct Product *product, int qty) {
    printf("\nDaftar produk setelah update:\n");
    for(int i = 0; i < qty; i++) {
        printf("Kode: %d, Nama: %s, Harga: %.2f, Stok: %d\n", product[i].code, product[i].name, product[i].price, product[i].stock);
    }
}

int main() {
    int qty;
    printf("Masukkan jumlah produk: ");
    scanf("%d", &qty);
    struct Product products[qty];
    inputProducts(products, qty);
    displayProducts(products, qty);
    sellProduct(products, qty);
    updateStock(products, qty);
    displayRestockProduct(products, qty);
    return 0;
}