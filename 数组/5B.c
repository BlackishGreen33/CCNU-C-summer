#include<stdio.h>
#define SIZE 20
int main(){
    int a[SIZE], b[SIZE / 3];
    int i, j, sum;
    printf("Plz enter %d integers:\n", SIZE);
    for(i = 0; i < SIZE; i++) scanf("%d", &a[i]);
    j = 0;
    for(i = 0; i < SIZE; i += 3){
        sum = a[i] + a[i + 1] + a[i + 2];
        b[j] = sum;
        j++;
    }
    printf("The sums of every three elements in array a are:\n");
    for(i = 0; i < j; i++){
        printf("%d ", b[i]);
        if((i + 1) % 5 == 0) printf("\n");
    }
    if(i % 5 != 0) printf("\n");
    return 0;
}
