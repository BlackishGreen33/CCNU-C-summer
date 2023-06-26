#include<stdio.h>
#include<math.h>
int main(){
    double rate, capital, deposit;
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the capital: ");
    scanf("%lf", &capital);
    printf("Enter the rate: ");
    scanf("%lf", &rate);
    rate /= 100;
    deposit = capital * pow(1 + rate, n);
    printf("The deposit is %.2lf", deposit);
    return 0;
}
