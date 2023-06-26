#include<stdio.h>
int main(){
    int sum, i, j;
    for(i = 1; i <= 1000; i++){
        sum = 0;
        for(j = 1; j < i; j++)
            if(i % j == 0) sum += j;
        if(sum == i){
            printf("%d is a perfect number, factors are: ", i);
            for(j = 1; j < i; j++)
                if(i % j == 0) printf("%d ", j);
            printf("\n");
        }
    }
    return 0;
}
