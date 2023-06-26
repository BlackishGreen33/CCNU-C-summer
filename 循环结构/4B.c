#include<stdio.h>
int main(){
	int i, j, n = 7;
	printf("              *\n");
    for(i = 3; i <= n; i += 2){
        for(j = 0; j < i; j++) printf("* ");
        printf("\n");
    }
    for(i = n - 2; i >= 2; i -= 2){
    	for(j = 0; j < i; j++) printf("* ");
        printf("\n");
    }
    printf("              *");
    return 0;
}
