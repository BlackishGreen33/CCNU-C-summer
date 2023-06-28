#include<stdio.h>
struct Date{
    int year;
    int month;
    int day;
};
int daysInMonth(int month, int year){
    switch(month){
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                return 29;
            else
                return 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}
int dayOfYear(struct Date date){
    int days = date.day;
    for (int i = 1; i < date.month; i++)
        days += daysInMonth(i, date.year);
    return days;
}
int main(){
    struct Date date;
    printf("Enter the date: ");
    scanf("%d-%d-%d", &date.year, &date.month, &date.day);
    int day = dayOfYear(date);
    printf("Day of the year in %d: %d", date.year, day);
    return 0;
}
