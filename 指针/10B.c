#include<stdio.h>
#define M 3
#define N 4
void fun(int a[][N], int m, int n, int *p, int *n_count);
int main(){
    int a[M][N] = {{33, 33, 33, 33}, {44, 44, 44, 44}, {55, 55, 55, 55}};
    int arr[M * N];
    int n_count = 0;
    fun(a, M, N, arr, &n_count);
    printf("The one-dimensional array is: ");
    for(int i = 0; i < M * N; i++) printf("%d ", arr[i]);
    printf("\n");
    printf("The number of elements in the one-dimensional array is: %d", n_count);
    return 0;
}
void fun(int a[][N], int m, int n, int *p, int *n_count){
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++){
            *(p++) = a[i][j];
            (*n_count)++;
        }
}
