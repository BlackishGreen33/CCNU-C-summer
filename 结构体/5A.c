#include<stdio.h>
enum score{
    FAIL,
    GENERAL,
    GOOD,
    EXCELLENT
};
int main(){
    int grade;
    printf("Plz enter the student's grade: ");
    scanf("%d", &grade);
    enum score s;
    if(grade < 60) s = FAIL;
    else if (grade < 80) s = GENERAL;
    else if (grade < 90) s = GOOD;
    else s = EXCELLENT;
    switch(s){
        case FAIL:
            printf("The student's grade is fail.");
            break;
        case GENERAL:
            printf("The student's grade is general.");
            break;
        case GOOD:
            printf("The student's grade is good.");
            break;
        case EXCELLENT:
            printf("The student's grade is excellent.");
            break;
        default:
            printf("Invalid grade.");
            break;
    }
    return 0;
}
