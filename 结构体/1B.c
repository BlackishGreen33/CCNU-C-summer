#include<stdio.h>
#include<stdlib.h>
struct Date{
    int year;
    int month;
    int day;
};
int compareDate(const void* a, const void* b){
    struct Date d1 = *(struct Date*)a;
    struct Date d2 = *(struct Date*)b;
    if(d1.year != d2.year)
        return d2.year - d1.year;
    else if(d1.month != d2.month)
        return d2.month - d1.month;
    else
        return d2.day - d1.day;
}
int main(){
    const int count = 10;
    struct Date dates[count];
    for (int i = 0; i < count; i++){
        printf("Enter the date (in the format yyyy-mm-dd): ");
        scanf("%d-%d-%d", &dates[i].year, &dates[i].month, &dates[i].day);
    }
    qsort(dates, count, sizeof(struct Date), compareDate);
    printf("Sorted dates in descending order:\n");
    for(int i = 0; i < count; i++)
        printf("%d-%02d-%02d\n", dates[i].year, dates[i].month, dates[i].day);
    return 0;
}
