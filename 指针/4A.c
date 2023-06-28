#include<stdio.h>
int main(){
    int numRows = 10;
    int triangle[numRows][numRows];
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i) triangle[i][j] = 1;
            else triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }
    return 0;
}
