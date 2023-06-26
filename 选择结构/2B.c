#include<stdio.h>
int main(){
    char c;
    printf("Plz enter a lowercase English letter: ");
    scanf("%c", &c);
    if(c >= 'a' && c <= 'z'){
        char sixth = (c - 'a' + 6) % 26 + 'a';
        printf("The 6th letter in the circular order for %c is %c.", c, sixth);
    }
	else
        printf("%c is not a lowercase English letter.", c);
    return 0;
}
