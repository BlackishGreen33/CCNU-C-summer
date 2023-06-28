#include<stdio.h>
void swap_arrays(int *a, int *b, int n){
    for(int i = 0; i < n; i++){
        int temp = *(a + i);
        *(a + i) = *(b + i);
        *(b + i) = temp;
    }
}
int main(){
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {6, 7, 8, 9, 10};
    int n = sizeof(a) / sizeof(int);
    printf("Before swapping:\n");
    printf("a: ");
    for(int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    printf("b: ");
    for(int i = 0; i < n; i++) printf("%d ", b[i]);
    printf("\n");
    swap_arrays(a, b, n);
    printf("After swapping:\n");
    printf("a: ");
    for(int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    printf("b: ");
    for(int i = 0; i < n; i++) printf("%d ", b[i]);
    return 0;
}
