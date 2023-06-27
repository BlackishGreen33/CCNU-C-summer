#include <stdio.h>
#include <stdbool.h>
bool is_prime(int n){
    if(n <= 1) return false;
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0) return false;
    return true;
}
void fun(int m, int *k, int xx[]){
    *k = 0;
    for(int i = 2; i < m; i++)
        if(!is_prime(i)){
            xx[*k] = i;
            (*k)++;
        }
}
int main(){
    int m, k, xx[100];
    printf("Plz enter an integer m: ");
    scanf("%d", &m);
    fun(m, &k, xx);
    printf("There are %d non-prime numbers between 2 and %d, which are:\n", k, m);
    for(int i = 0; i < k; i++) printf("%d ", xx[i]);
    return 0;
}
