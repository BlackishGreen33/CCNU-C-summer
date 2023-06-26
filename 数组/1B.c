#include<stdio.h>
int main(){
    int arr[100], n, i, j, num;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter elements of array in ascending order: ");
    for(i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter number to be inserted: ");
    scanf("%d", &num);
    for(i = 0; i < n; i++){
        if(num < arr[i]){
            for(j = n; j > i; j--) arr[j] = arr[j - 1];
            arr[i] = num;
            break;
        }
    }
    printf("New array: ");
    for(i = 0; i < n + 1; i++) printf("%d ", arr[i]);
    return 0;
}
