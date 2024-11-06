#include <stdio.h>

struct Person {
   char name[100];
   int age;
};

void setPersonData (struct Person *ps) {
   printf("Masukan nama anda: ");
   fgets(ps->name, sizeof(ps->name), stdin);
   printf("Masukkan umur anda: ");
   scanf("%d", &ps->age);
}

void showingPersonData(struct Person ps) {
   printf("Name: %sAge: %d", ps.name, ps.age);
}

int main() {
   struct Person ps1;
   setPersonData(&ps1);
   showingPersonData(ps1);

   return 0;
}