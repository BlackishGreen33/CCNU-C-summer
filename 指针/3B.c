#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a, int *b);
void sort(int *arr, int n);
int main(){
    int n;
    printf("Plz enter the length of the array n:\n");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    srand(time(NULL));
    printf("Randomly generated array elements:\n");
    for(int i = 0; i < n; i++){
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");
    sort(arr, n);
    printf("Sorted array:\n");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    free(arr);
    return 0;
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sort(int *arr, int n){
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            if(arr[i] > arr[j]) swap(&arr[i], &arr[j]);
}
