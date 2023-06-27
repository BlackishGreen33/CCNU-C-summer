#include<stdio.h>
void fun(){
    int matrix[3][3];
    int sum = 0;
    printf("Plz enter a 3x3 matrix:\n");
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++){
            scanf("%d", &matrix[i][j]);
            if (i == j) sum += matrix[i][j];
        }
    printf("The sum of the main diagonal elements of the matrix is: %d", sum);
}
int main(){
    fun();
    return 0;
}
