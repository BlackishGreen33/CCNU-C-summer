#include <stdio.h>
#define MAX_SIZE 100
int main(){
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];
    int m, n, i, j;
    printf("Plz input the number of rows and columns for matrices A and B:\n");
    scanf("%d %d", &m, &n);
    printf("Plz input all elements of matrix A:\n");
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++) scanf("%d", &A[i][j]);
    printf("Plz input all elements of matrix B:\n");
    for(i = 0; i < m; i++)
        for (j = 0; j < n; j++) scanf("%d", &B[i][j]);
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++) C[i][j] = A[i][j] + B[i][j];
    printf("The sum of matrices A and B is:\n");
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++) printf("%4d", C[i][j]);
        printf("\n");
    }
    return 0;
}
