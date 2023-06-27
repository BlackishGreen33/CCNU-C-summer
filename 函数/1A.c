#include<stdio.h>
void fun(int n) {
    float sum = 0;
    for(int i = 1; i <= n; i++)
        if(i % 5 == 0 || i % 9 == 0) sum += 1.0 / i;
    printf("The sum of the reciprocals of natural numbers that can be divided by 5 or 9 within n is: %f", sum);
}
int main(){
    int n;
    printf("Plz enter a natural number n:");
    scanf("%d", &n);
    fun(n);
    return 0;
}
