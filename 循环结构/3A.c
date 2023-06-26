#include<stdio.h>
#include<ctype.h>
int main(){
    char c;
    int letter = 0, space = 0, digit = 0, other = 0;
    printf("Plz enter a line of characters: ");
    while((c = getchar()) != '\n'){
        if(isalpha(c)) letter++;
        else if(isspace(c)) space++;
        else if(isdigit(c)) digit++;
        else other++;
    }
    printf("There are %d letters, %d spaces, %d digits, and %d other characters in the input.", letter, space, digit, other);
    return 0;
}
