#include<stdio.h>
int main(){
    int n, i, j, num;
    printf("Plz enter the value of n: ");
    scanf("%d", &n);
    int magic[n][n];
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++) magic[i][j] = 0;
    i = 0;
    j = n / 2;
    for(num = 1; num <= n * n; num++){
        magic[i][j] = num;
        i--;
        j++;
        if((num % n) == 0){
            i += 2;
            j--;
        }
        else{
            if(j == n) j -= n;
            else if(i < 0) i += n;
        }
    }
    printf("The magic square is:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++) printf("%4d", magic[i][j]);
        printf("\n");
    }
    return 0;
}
