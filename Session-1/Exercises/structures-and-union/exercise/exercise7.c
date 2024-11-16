#include <stdio.h>

struct Student {
    int id;
    char name[50];
    float gpa;
};

void inputData (struct Student *student, int people) {
    for(int i = 0; i < people; i++) {
        printf("Masukkan data mahasiswa ke-%d\n", i + 1);
        printf("ID: ");
        scanf("%d", &student[i].id); // Added & operator
        printf("Masukkan nama siswa: ");
        scanf("%s", student[i].name); // name is already an array so no & needed
        printf("Masukkan gpa: ");
        scanf("%f", &student[i].gpa); // Added & operator
        printf("\n");
    }
}

void displayData(struct Student *student, int people) {
    for (int i = 0; i < people; i++){
        printf("\nData mahasiswa sebelum update:\n");
        printf("ID: %d\nName: %s\nGPA: %.2f\n\n", student[i].id, student[i].name, student[i].gpa);
    }
}

int updateData(struct Student *student, int people) {
    int id;
    float newGPA;
    printf("Masukkan ID mahasiswa yang GPA-nya ingin diperbarui: ");
    scanf("%d", &id);
    
    for (int i = 0; i < people; i++) {
        if (id == student[i].id) {
            printf("Masukkan GPA baru: ");
            scanf("%f", &newGPA);
            student[i].gpa = newGPA;
            printf("GPA berhasil diperbarui!\n");
            return 0;
        }
    }
    
    fprintf(stderr, "ID mahasiswa tidak tersedia.\n");
    return 1;
}

int main() {
    int people;
    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &people);
    struct Student student1[people];
    inputData(&student1, people);
    displayData(&student1, people);
    updateData(&student1, people);
    return 0;
}