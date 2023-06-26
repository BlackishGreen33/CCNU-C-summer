#include<stdio.h>
int main(){
    float x, y, pay;
    printf("Plz enter the customer's purchase amount: ");
    scanf("%f", &x);
    switch((int)x/800){
        case 0:
            y = 0;
            break;
        case 1:
            y = 0.05;
            break;
        case 2:
            y = 0.1;
            break;
        case 3:
            y = 0.15;
            break;
        default:
            y = 0.2;
            break;
    }
    pay = x * (1 - y);
    printf("The amount to be paid is %.2f.", pay);
    return 0;
}
