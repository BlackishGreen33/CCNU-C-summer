#include<stdio.h>
#define SIZE 10
int main(){
    int numbers[SIZE];
    int i, max, min, max_index, min_index;
    printf("Plz enter %d integers:\n", SIZE);
    for(i = 0; i < SIZE; i++) scanf("%d", &numbers[i]);
    max = min = numbers[0];
    max_index = min_index = 0;
    for(i = 1; i < SIZE; i++){
        if(numbers[i] > max){
            max = numbers[i];
            max_index = i;
        }
        if(numbers[i] < min){
            min = numbers[i];
            min_index = i;
        }
    }
    printf("The maximum value is %d, and it is located at index %d.\n", max, max_index);
    printf("The minimum value is %d, and it is located at index %d.", min, min_index);
    return 0;
}
