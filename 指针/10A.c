#include<stdio.h>
void reverse(int *arr, int n, int start, int count);
int main(){
    int arr[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int start = 3, count = 5;
    printf("The original array is: ");
    for(int i = 0; i < 10; i++) printf("%d ", arr[i]);
    printf("\n");
    reverse(arr, 10, start, count);
    printf("The modified array is: ");
    for(int i = 0; i < 10; i++) printf("%d ", arr[i]);
    return 0;
}
void reverse(int *arr, int n, int start, int count){
    int *p_start = arr + start - 1;
    int *p_end = p_start + count - 1;
    while(p_start < p_end){
        int temp = *p_start;
        *p_start = *p_end;
        *p_end = temp;
        p_start++;
        p_end--;
    }
}
