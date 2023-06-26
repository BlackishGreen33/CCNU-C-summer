#include<stdio.h>
int main(){
    float x, y;
    printf("Plz enter the value of x: ");
    scanf("%f", &x);
    if(x >= 0 && x <= 8)
        y = x + 2 * x * x + 10;
	else if(x < 0 || x > 8)
        y = x - 3 * x * x * x - 9;
    printf("The value of y is %f.", y);
    return 0;
}
