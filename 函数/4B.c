#include<stdio.h>
void fun(int *a, int *n){
    int count = 0;
    for(int i = 1; i <= 1000; i++)
        if((i % 7 == 0 || i % 11 == 0) && !(i % 7 == 0 && i % 11 == 0)) a[count++] = i;
    *n = count;
}
int main(){
    int a[1000], n;
    fun(a, &n);
    printf("There are %d integers between 1 and 1000 that are divisible by 7 or 11, but not both. They are:\n", n);
    for(int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}
