#include<stdio.h>
#include<string.h>
int main(){
    char *weekdays[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int day;
    printf("Plz enter the day of the week (1-7): ");
    scanf("%d", &day);
    if(day >= 1 && day <= 7)
        printf("The English name of the day is: %s", *(weekdays+day-1));
    else printf("Invalid input!");
    return 0;
}
