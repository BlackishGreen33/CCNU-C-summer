#include<stdio.h>
#define MAX_SIZE 100
int main(){
    int nums[MAX_SIZE];
    int odds[MAX_SIZE];
    int i, n = 0, m = 0;
    printf("Plz input a set of integers (enter -l to finish):\n");
    while(1){
        scanf("%d", &nums[n]);
        if(nums[n] == -1) break;
        n++;
    }
    printf("The original integers are:\n");
    for(i = 0; i < n; i++){
        printf("%4d", nums[i]);
        if((i + 1) % 3 == 0) printf("\n");
    }
    if(i % 3 != 0) printf("\n");
    for(i = 0; i < n; i++){
        if(nums[i] % 2 != 0){
            odds[m] = nums[i];
            m++;
        }
    }
    printf("All odd numbers are:\n");
    for(i = 0; i < m; i++){
        printf("%4d", odds[i]);
        if((i + 1) % 3 == 0) printf("\n");
    }
    if(i % 3 != 0) printf("\n");
    return 0;
}
