#include <stdio.h>
#include <string.h>

typedef struct {
   char name[50];
   int age;
} Person;

int main() {
   Person p1;
   strcpy(p1.name, "Budi");
   p1.age = 21;

   printf("Nama: %s, Usia: %d\n", p1.name, p1.age);
   return 0;  
}