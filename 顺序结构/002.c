#include<stdio.h>
int main(){
    double num1, num2, sum, difference, product;
    printf("Plz enter the first real number¡G");
    scanf("%lf", &num1);
    printf("Plz enter the second real number¡G");
    scanf("%lf", &num2);
    sum = num1 + num2;
    difference = num1 - num2;
    product = num1 * num2;
    printf("sum = %.2lf\n", sum);
    printf("difference = %.2lf\n", difference);
    printf("product = %.2lf", product);
    return 0;
}
