#include<stdio.h>
void input(int *arr, int n);
void process(int *arr, int n);
void output(int *arr, int n);
int main(){
    int arr[10];
    input(arr, 10);
    process(arr, 10);
    output(arr, 10);
    return 0;
}
void input(int *arr, int n){
    printf("Enter %d integers:\n", n);
    for(int i = 0; i < n; i++) scanf("%d", arr + i);
}
void process(int *arr, int n){
    int min_index = 0, max_index = 0;
    for(int i = 1; i < n; i++){
        if(*(arr + i) < *(arr + min_index)) min_index = i;
        if(*(arr + i) > *(arr + max_index)) max_index = i;
    }
    int temp = *(arr + 0);
    *(arr + 0) = *(arr + min_index);
    *(arr + min_index) = temp;
    temp = *(arr + n - 1);
    *(arr + n - 1) = *(arr + max_index);
    *(arr + max_index) = temp;
}
void output(int *arr, int n){
    printf("The modified array is:\n");
    for(int i = 0; i < n; i++) printf("%d ", *(arr + i));
}
