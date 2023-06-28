#include<stdio.h>
#include<string.h>
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
    for (int i = 0; i < n; i++){
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
struct stu Searchname(struct stu a[], int n, char name[]) {
    for(int i = 0; i < n; i++)
        if (strcmp(a[i].name, name) == 0) return a[i];
    struct stu noresult = {0, "", ' ', {0, 0, 0}, {0, 0, 0, 0}, 0};
    return noresult;
}
void Sortname(struct stu a[], int n){
    struct stu temp;
    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < n - i - 1; j++)
            if(strcmp(a[j].name, a[j + 1].name) > 0){
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
    printf("Sorted information by name:\n");
    Outputarray(a, n);
}
int main(){
    int n;
    struct stu class[50];
    printf("Plz enter the number of students in the class: ");
    scanf("%d", &n);
    Inputarray(class, n);
    char search_name[20];
    printf("Plz enter the name of the student to search: ");
    scanf("%s", search_name);
    struct stu result = Searchname(class, n, search_name);
    if(result.num == 0) printf("No result found.\n");
	else{
        printf("Information for student %s:\n", search_name);
        Output(result);
    }
    Sortname(class, n);
    return 0;
}
