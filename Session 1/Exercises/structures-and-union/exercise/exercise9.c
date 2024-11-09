#include <stdio.h>
#include <string.h>

struct Order {
    int orderID;
    char menuItem[50];
    int quantity;
    int isComplete;
};

void inputOrders(struct Order *orders, int muchOrders) {
    for (int i = 0; i < muchOrders; i++) {
        printf("Pesanan ke-%d\n", i+1);
        printf("ID Pesanan: ");
        scanf("%d", &orders[i].orderID);
        getchar();
        printf("Menu Item: ");
        fgets(orders[i].menuItem, sizeof(orders[i].menuItem), stdin);
        orders[i].menuItem[strcspn(orders[i].menuItem, "\n")] = 0;
        printf("Jumlah: ");
        scanf("%d", &orders[i].quantity);
        getchar();
        orders[i].isComplete = 0;
        printf("\n");
    }
}

void displayOrders(struct Order *orders, int muchOrders) {
    printf("Semua Pesanan: \n");
    for(int i = 0; i < muchOrders; i++) {
        printf("ID: %d, Menu: %s, Jumlah: %d, Status: %s\n", orders[i].orderID, orders[i].menuItem, orders[i].quantity, orders[i].isComplete == 0 ? "Belum Selesai" : "Selesai");
    }
    printf("\n");
}

int markOrderCompleted(struct Order *orders, int muchOrders) {
    int menuId;
    printf("Masukkan ID Pesanan yang ingin ditandai selesai: ");
    scanf("%d", &menuId);
    for (int i = 0; i < muchOrders; i++) {
        if (menuId == orders[i].orderID) {
            orders[i].isComplete = 1;
            return 0;
        }
    }
    printf("\n");
    fprintf(stderr, "Order ID yang dimasukkan tidak tersedia.");
    return 1;
}

void displayPendingOrders(struct Order *orders, int muchOrders) {
    printf("\nPesanan yang belum selesai: \n");
    for (int i = 0; i < muchOrders; i++) {
        if(orders[i].isComplete == 0) {
            continue;
        }
        printf("ID: %d, Menu: %s, Jumlah: %d, Status: Belum Selesai\n", orders[i].orderID, orders[i].menuItem, orders[i].isComplete);
    }
    printf("\n");
}

int main() {
    int orderQty;
    printf("Masukkan jumlah pesanan: ");
    scanf("%d", &orderQty);
    getchar();
    struct Order order1[orderQty];
    int muchOrders = sizeof(order1) / sizeof(order1[0]);
    inputOrders(order1, muchOrders);
    displayOrders(order1, muchOrders);
    markOrderCompleted(order1, muchOrders);
    displayPendingOrders(order1, muchOrders);

    return 0;
}