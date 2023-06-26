#include<stdio.h>
int main(){
    int n, fact = 1, sum = 0;
    printf("Please enter the value of N: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        fact *= i;
        sum += fact;
    }
    printf("The sum of 1!+2!+3!+...+%d! is: %d", n, sum);
    return 0;
}
