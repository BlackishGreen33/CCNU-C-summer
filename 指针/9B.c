#include<stdio.h>
void find_max(int *arr, int n, int *max, int *index);
int main() {
    int arr[10] = {3, 5, 1, 9, 8, 4, 7, 2, 6, 0};
    printf("The original array is: ");
    for(int i = 0; i < 10; i++) printf("%d ", arr[i]);
    printf("\n");
    int max, index;
    find_max(arr, 10, &max, &index);
    printf("The maximum value is %d, and its index is %d.", max, index);
    return 0;
}
void find_max(int *arr, int n, int *max, int *index){
    *max = *(arr + 0);
    *index = 0;
    for(int i = 1; i < n; i++)
        if(*(arr + i) > *max) {
            *max = *(arr + i);
            *index = i;
        }
}
