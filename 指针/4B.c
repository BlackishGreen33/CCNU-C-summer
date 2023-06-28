#include<stdio.h>
int main(){
    int arr[3][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};
    int sum[3] = {0};
    printf("The original array is:\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++) printf("%d ", arr[i][j]);
        printf("\n");
    }
    printf("The sum of elements in each row is:\n");
    for(int i = 0; i < 3; i++){
        int *rowPtr = arr[i];
        for(int j = 0; j < 5; j++) sum[i] += *(rowPtr + j);
        printf("The sum of elements in row %d is %d\n", i+1, sum[i]);
    }
    return 0;
}
