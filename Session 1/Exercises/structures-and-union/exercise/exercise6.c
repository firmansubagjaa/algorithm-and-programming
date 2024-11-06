#include <stdio.h>

struct Person{
    char name[50];
    int age;
};

void inputPerson(struct Person *person) {
    printf("Nama kamu siapa?");
    fgets(person->name, sizeof(person->name), stdin);
    printf("Umur kamu sekarang?");
    scanf("%d", person->age);
}

void showingDataPerson(struct Person person) {
    printf("Nama: %s\nUmur: %d", person.name, person.age);
}

int main() {
    struct Person person1;
    inputPerson(&person1);
    showingDataPerson(person1);
    return 0;
}