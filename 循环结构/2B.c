#include<stdio.h>
int main(){
    double e = 1, term = 1;
    int n = 1;
    while(term >= 1e-6){
        term /= n;
        e += term;
        n++;
    }
    printf("The value of e is: %lf", e);
    return 0;
}
