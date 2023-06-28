#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    char name[20];
    char unit[50];
    char address[100];
    char title[20];
}Teacher;
typedef struct{
    char name[20];
    char class[10];
    char address[100];
    double score;
}Student;
int compareTeacher(const void* a, const void* b){
    Teacher* t1 = (Teacher*)a;
    Teacher* t2 = (Teacher*)b;
    return strcmp(t1->name, t2->name);
}
int compareStudent(const void* a, const void* b){
    Student* s1 = (Student*)a;
    Student* s2 = (Student*)b;
    return strcmp(s1->name, s2->name);
}
int main(){
    const int count = 10;
    Teacher teachers[count];
    Student students[count];
    printf("Plz enter information for 10 teachers:\n");
    for(int i = 0; i < count; i++){
        printf("Enter the information for teacher %d:\n", i+1);
        printf("Name: ");
        scanf("%s", teachers[i].name);
        printf("Unit: ");
        scanf("%s", teachers[i].unit);
        printf("Address: ");
        scanf("%s", teachers[i].address);
        printf("Title: ");
        scanf("%s", teachers[i].title);
    }
    printf("Plz enter information for 10 students:\n");
    for(int i = 0; i < count; i++){
        printf("Enter the information for student %d:\n", i+1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Class: ");
        scanf("%s", students[i].class);
        printf("Address: ");
        scanf("%s", students[i].address);
        printf("Score: ");
        scanf("%lf", &students[i].score);
    }
    qsort(teachers, count, sizeof(Teacher), compareTeacher);
    qsort(students, count, sizeof(Student), compareStudent);
    printf("Sorted teacher information:\n");
    for(int i = 0; i < count; i++)
        printf("%s %s %s %s\n", teachers[i].name, teachers[i].unit, teachers[i].address, teachers[i].title);
    printf("Sorted student information:\n");
    for(int i = 0; i < count; i++)
        printf("%s %s %s %.2lf\n", students[i].name, students[i].class, students[i].address, students[i].score);
    return 0;
}
