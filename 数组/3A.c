#include<stdio.h>
int main(){
    int arr[5];
    for(int i = 0; i < 5; i++) scanf("%d", &arr[i]);
    int len = sizeof(arr) / sizeof(arr[0]);
    int temp, i;
    for(i = 0; i < len / 2; i++){
        temp = arr[i];
        arr[i] = arr[len - i - 1];
        arr[len - i - 1] = temp;
    }
    printf("The reversed array is: ");
    for(i = 0; i < len; i++) printf("%d ", arr[i]);
    return 0;
}
