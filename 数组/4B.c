#include<stdio.h>
#define ROWS 4
#define COLS 4
int main(){
    int matrix[ROWS][COLS];
    int i, j, min;
    printf("Plz enter %d elements of a %d x %d matrix:\n", ROWS * COLS, ROWS, COLS);
    for(i = 0; i < ROWS; i++)
        for(j = 0; j < COLS; j++) scanf("%d", &matrix[i][j]);
    min = matrix[0][0];
    for(i = 1; i < ROWS; i++)
        if(matrix[i][i] < min) min = matrix[i][i];
    printf("The minimum element on the diagonal is: %d", min);
    return 0;
}
