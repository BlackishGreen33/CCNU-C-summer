#include<stdio.h>
int main(){
    float t;
    printf("Plz enter the score: ");
    scanf("%f", &t);
    if(t >= 90) printf("Grade A.");
    else{
        if(t >= 80) printf("Grade B.");
        else{
            if(t >= 70) printf("Grade C.");
			else{
                if(t >= 60) printf("Grade D.");
				else printf("Grade E.");
            }
        }
    }
    return 0;
}
