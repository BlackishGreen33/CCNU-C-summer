#include<stdio.h>
int main(){
    float x, y, pay;
    printf("Plz enter the customer's purchase amount: ");
    scanf("%f", &x);
    if (x < 1600) y = 0;
    else{
        if(x < 2400) y = 0.05;
		else{
            if(x < 3200) y = 0.1;
			else{
                if(x < 6400) y = 0.15;
				else y = 0.2;
            }
        }
    }
    pay = x * (1 - y);
    printf("The amount to be paid is %.2f.", pay);
    return 0;
}
