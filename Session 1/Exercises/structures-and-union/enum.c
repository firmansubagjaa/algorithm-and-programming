#include <stdio.h>

enum Day {
   SUNDAY,
   MONDAY, 
   TUESDAY, 
   WEDNESDAY, 
   THURSDAY, 
   FRIDAY, 
   SATURDAY
};

int main() {
   enum Day today;
   today = TUESDAY;

   if (today != MONDAY) {
      fprintf(stderr, "Hari ini senin bukan yang lain.");
      return 1;
   }
      printf("Hari ini adalah Senin.\n");
   
   return 0;
}