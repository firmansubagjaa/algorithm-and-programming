#include <stdio.h>
#include <string.h>

struct Employee {
   int id;
   char name[50];
   float salary;
};

void updateSalary(struct Employee *emp, float newSalary) {
   emp->salary = newSalary;
}

void displayEmployee(struct Employee emp) {
   printf("ID: %d\n", emp.id);
   printf("Name: %s\n", emp.name);
   printf("Salary: %.2f\n", emp.salary);
}

int main() {
   struct Employee emp1;
   emp1.id = 101;
   strcpy(emp1.name, "Budi");
   emp1.salary = 5000.0;

   printf("Data karyawan sebelum update:\n");
   displayEmployee(emp1);

   updateSalary(&emp1, 7500.0);

   printf("Data karyawan sesudah update:\n");
   displayEmployee(emp1);
   
   return 0;
}