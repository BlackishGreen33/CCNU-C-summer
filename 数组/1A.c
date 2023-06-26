#include<stdio.h>
int main(){
    int nums[20], i, max, second_max;
    printf("Plz enter 20 integers: ");
    for(i = 0; i < 20; i++) scanf("%d", &nums[i]);
    if(nums[0] > nums[1]){
        max = nums[0];
        second_max = nums[1];
    } 
	else{
        max = nums[1];
        second_max = nums[0];
    }
    for(i = 2; i < 20; i++){
        if(nums[i] > max){
            second_max = max;
            max = nums[i];
        } 
		else if(nums[i] > second_max)
            second_max = nums[i];
    }
    printf("The maximum value is: %d\n", max);
    printf("The second maximum value is: %d", second_max);
    return 0;
}
