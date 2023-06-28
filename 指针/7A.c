#include<stdio.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int arr[100];
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int max_idx = 0;
    int min_idx = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] > arr[max_idx]) max_idx = i;
        if(arr[i] < arr[min_idx]) min_idx = i;
    }
    swap(&arr[0], &arr[max_idx]);
    swap(&arr[n - 1], &arr[min_idx]);
    printf("The modified array is: ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}
