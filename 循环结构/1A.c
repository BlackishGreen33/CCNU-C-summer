#include<stdio.h>
int main(){
    int num[9], sum = 0, positive_sum = 0, negative_sum = 0;
    for(int i = 0; i < 9; i++) scanf("%d", &num[i]);
    for(int i = 0; i < 9; i++){
        sum += num[i];
        if(num[i] > 0) positive_sum += num[i];
        else negative_sum += num[i];
    }
    printf("The sum of all the numbers is: %d\n", sum);
    printf("The sum of all positive numbers is: %d\n", positive_sum);
    printf("The sum of all negative numbers is: %d", negative_sum);
    return 0;
}
