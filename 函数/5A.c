#include<stdio.h>
double fun(int m, int n){
    int diff = m - n;
    double p = 1.0;
    for(int i = m; i > diff; i--) p *= i;
    for(int j = n; j > 0; j--) p /= j;
    return p;
}
int main(){
    int m, n ;
    scanf("%d %d", &m, &n);
    double p = fun(m, n);
    printf("When m=%d and n=%d, the value of P is %.6lf", m, n, p);
    return 0;
}
