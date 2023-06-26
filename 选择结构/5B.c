#include<stdio.h>
int main(){
    float t;
    printf("Plz enter the score: ");
    scanf("%f", &t);
    int grade = (int)t / 10;
    switch(grade){
        case 10:
        case 9:
            printf("Grade A.");
            break;
        case 8:
            printf("Grade B.");
            break;
        case 7:
            printf("Grade C.");
            break;
        case 6:
            printf("Grade D.");
            break;
        default:
            printf("Grade E.");
            break;
    }
    return 0;
}
