#include<stdio.h>
int main(){
    int month, i, current, previous, next;
    printf("Plz enter the number of months: ");
    scanf("%d", &month);
    previous = 1;
    current = 1;
    for(i = 3; i <= month; i++){
        next = current + previous;
        previous = current;
        current = next;
    }
    printf("The total number of rabbit pairs after %d months is: %d", month, current);
    return 0;
}
