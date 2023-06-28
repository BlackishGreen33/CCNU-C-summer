#include<stdio.h>
struct date{
    int month;
    int day;
    int year;
};
struct stu{
    int num;
    char name[20];
    char sex;
    struct date birthday;
    float score[4];
    float ave;
};
void Input(struct stu *a){
    printf("Plz enter student ID: ");
    scanf("%d", &a->num);
    printf("Plz enter student name: ");
    scanf("%s", a->name);
    printf("Plz enter student gender (M/F): ");
    scanf(" %c", &a->sex);
    printf("Plz enter student date of birth (month day year): ");
    scanf("%d %d %d", &a->birthday.month, &a->birthday.day, &a->birthday.year);
    printf("Plz enter scores for four courses: ");
    scanf("%f %f %f %f", &a->score[0], &a->score[1], &a->score[2], &a->score[3]);
    a->ave = (a->score[0] + a->score[1] + a->score[2] + a->score[3]) / 4;
}
void Output(struct stu a){
    printf("Student ID: %d\n", a.num);
    printf("Student name: %s\n", a.name);
    printf("Student gender: %c\n", a.sex);
    printf("Student date of birth: %d/%d/%d\n", a.birthday.month, a.birthday.day, a.birthday.year);
    printf("Scores for four courses: %.1f %.1f %.1f %.1f\n", a.score[0], a.score[1], a.score[2], a.score[3]);
    printf("Average score: %.1f\n", a.ave);
}
void Inputarray(struct stu a[], int n){
    for(int i = 0; i < n; i++){
        printf("Plz enter information for student %d:\n", i + 1);
        Input(&a[i]);
    }
}
void Outputarray(struct stu a[], int n){
    for(int i = 0; i < n; i++){
        printf("Information for student %d:\n", i + 1);
        Output(a[i]);
    }
}
int main(){
    int n;
    struct stu class[50];
    printf("Plz enter the number of students in the class: ");
    scanf("%d", &n);
    Inputarray(class, n);
    int max_index = 0;
    float max_ave = class[0].ave;
    for (int i = 1; i < n; i++)
        if (class[i].ave > max_ave) {
            max_index = i;
            max_ave = class[i].ave;
        }
    printf("\nInformation of the student with the highest average score:\n");
    Output(class[max_index]);
    return 0;
}
