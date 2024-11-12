#include <stdio.h>

int main() {
  int arr[] = {5, 10, 15, 20};
int *ptr = arr;
*ptr += 5;
*(ptr + 2) *= 2;
printf("%d %d", arr[0], arr[2]);

    return 0;
}