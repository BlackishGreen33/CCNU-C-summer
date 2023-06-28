#include<stdio.h>
int main() {
    int num, reversed_num = 0;
    printf("Plz enter an integer: ");
    scanf("%d", &num);
    int *p = &num;
    while(*p != 0){
        reversed_num = reversed_num * 10 + (*p % 10);
        *p /= 10;
    }
    printf("The reversed number is: %d", reversed_num);
    return 0;
}
