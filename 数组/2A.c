#include<stdio.h>
int main(){
    int age[15] = {0};
    int i, student_age;
    for (i = 0; i < 5; i++) {
        printf("Plz enter the age of student %d: ", i+1);
        scanf("%d", &student_age);
        if(student_age >= 16 && student_age <= 30) age[student_age - 16]++;
    }
    for(i = 0; i < 15; i++)
        printf("Number of students at age %d: %d\n", i+16, age[i]);
    return 0;
}
