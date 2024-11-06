#include <stdio.h>

struct Person
{
   char name[100];
   int age;
};

void inputPerson(struct Person *ps) {
   printf("Masukkan nama: ");
   fgets(ps->name, sizeof(ps->name), stdin);
   printf("Masukkan umur: ");
   scanf("%d", &ps->age);
}

void outputPerson(struct Person ps) {
   printf("Name: %sAge: %d", ps.name, ps.age);
}

int main() {
   struct Person ps1;
   inputPerson(&ps1);
   outputPerson(ps1);
   return 0;
}
