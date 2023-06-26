#include<stdio.h>
int main(){
    char c;
    printf("Plz enter a character: ");
    scanf("%c", &c);
    if(c >= 'A' && c <= 'Z'){
        char lower = c + ('a' - 'A');
        printf("%c corresponds to lowercase %c.", c, lower);
    } 
	else
        printf("%c is not an uppercase letter.", c);
    return 0;
}
