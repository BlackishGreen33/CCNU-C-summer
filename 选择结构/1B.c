#include<stdio.h>
int main(){
    int num;
    printf("Plz enter a positive integer with no more than 5 digits: ");
    scanf("%d", &num);
    if(num < 10)
        printf("%d is a 1-digit number.", num);
    else if(num < 100)
        printf("%d is a 2-digit number.", num);
    else if(num < 1000)
        printf("%d is a 3-digit number.", num);
    else if(num < 10000)
        printf("%d is a 4-digit number.", num);
    else
        printf("%d is a 5-digit number.", num);
    return 0;
}
