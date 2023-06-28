#include<stdio.h>
void sort(int *arr, int size);
int main(){
    int arr[10];
    printf("Plz enter 10 integers:");
    for(int i = 0; i < 10; i++) scanf("%d", &arr[i]);
    sort(arr, 10);
    printf("The sorted array in ascending order is: ");
    for(int i = 0; i < 10; i++) printf("%d ", arr[i]);
    return 0;
}
void sort(int *arr, int size){
    int temp;
    for(int i = 0; i < size-1; i++)
        for(int j = i+1; j < size; j++)
            if(*(arr+i) > *(arr+j)){
                temp = *(arr+i);
                *(arr+i) = *(arr+j);
                *(arr+j) = temp;
            }
}
