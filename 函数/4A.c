#include<stdio.h>
void fun(int a, int b, int *c){
    *c = a % 10 * 1000 + a / 10 + b % 10 * 10 + b / 10 * 100;
}
int main(){
    int a, b, c;
    scanf("%d %d", &a, &b);
    fun(a, b, &c);
    printf("The merged integer is: %d", c);
    return 0;
}
