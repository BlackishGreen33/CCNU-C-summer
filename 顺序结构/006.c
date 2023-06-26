#include<stdio.h>
int main(){
    char lower, upper;
    printf("Plz enter a lowercase letter: ");
    scanf("%c", &lower);
    upper = lower - 32;
    printf("The decimal ASCII code is: %d\n", upper);
    printf("The hexadecimal ASCII code is: %x", upper);
    return 0;
}
