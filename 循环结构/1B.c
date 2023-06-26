#include<stdio.h>
int main(){
    int n = 20;
    double pre = 2, cur = 1, sum = 2;
    for(int i = 2; i <= n; i++){
        double temp = cur;
        cur = pre + cur;
        pre = temp;
        sum += cur / pre;
    }
    printf("Sum¡G%lf", sum);
    return 0;
}
