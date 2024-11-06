#include <stdio.h>
#include <string.h>

struct Employee {
   int id;
   char name[50];
   float salary;
};

void updateSalary(struct Employee *emp, float newSalary, int index) {
   emp[index].salary = newSalary;
}

void displayEmployee(struct Employee *emp, int size) {
   int i = 0;
   while (i < size) {
      printf("ID: %d\n", emp[i].id);
      printf("Name: %s\n", emp[i].name);
      printf("Salary: %.2f\n", emp[i].salary);
      i++;
   }
}

int main() {
   int size = 3;
   struct Employee emp1[size];

   emp1[0].id = 1;
   strcpy(emp1[0].name, "Firman");
   emp1[0].salary = 4500.0;

   emp1[1].id = 2;
   strcpy(emp1[1].name, "Farhan");
   emp1[1].salary = 6000.0;

   emp1[2].id = 3;
   strcpy(emp1[2].name, "Dalfan");
   emp1[2].salary = 5500.0;

   printf("Data karyawan sebelum update:\n");
   displayEmployee(emp1, size);

   updateSalary(emp1, 7500.0, 0);
   updateSalary(emp1, 8500.0, 1);
   updateSalary(emp1, 9500.0, 2);

   printf("\nData karyawan sesudah update:\n");
   displayEmployee(emp1, size);
   
   return 0;
}