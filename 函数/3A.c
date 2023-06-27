#include<stdio.h>
double fun(int n){
    double s = 0.0;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += i;
        s += 1.0 / sum;
    }
    return s;
}
int main(){
    int n;
    double s;
    printf("Plz enter an integer n: ");
    scanf("%d", &n);
    s = fun(n);
    printf("The value of the polynomial is: %.6f", s);
    return 0;
}
