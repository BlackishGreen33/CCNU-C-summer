#include<stdio.h>
int main() {
    float x, y;
    printf("Plz enter the value of x: ");
    scanf("%f", &x);
    switch((int)x){
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            y = x + 2 * x * x + 10;
            break;
        default:
            y = x - 3 * x * x * x - 9;
            break;
    }
    printf("The value of y is %f.", y);
    return 0;
}
