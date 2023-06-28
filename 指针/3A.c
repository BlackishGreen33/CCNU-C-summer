#include<stdio.h>
void transpose(int (*matrix)[3]);
int main(){
    int matrix[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    printf("Original matrix:\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++) printf("%d ", matrix[i][j]);
        printf("\n");
    }
    transpose(matrix);
    printf("Transposed matrix:\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++) printf("%d ", matrix[i][j]);
        printf("\n");
    }
    return 0;
}
void transpose(int (*matrix)[3]) {
    int temp;
    for(int i = 0; i < 3; i++) {
        for(int j = i+1; j < 3; j++) {
            temp = *(*(matrix+i)+j);
            *(*(matrix+i)+j) = *(*(matrix+j)+i);
            *(*(matrix+j)+i) = temp;
        }
    }
}
