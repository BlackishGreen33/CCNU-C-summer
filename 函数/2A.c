#include<stdio.h>
int Fact(int n){
    int result = 1;
    for(int i = 1; i <= n; i++) result *= i;
    return result;
}
int main(){
    int n, sum = 0;
    printf("Plz enter a natural number n:");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) sum += Fact(i);
    printf("The sum of factorials from 1 to n is: %d", sum);
    return 0;
}
