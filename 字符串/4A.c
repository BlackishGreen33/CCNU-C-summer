#include<stdio.h>
#include<ctype.h>
void remove_digits(char* str){
    int i, j;
    for(i = 0, j = 0; str[i] != '\0'; i++)
        if(!isdigit(str[i])) str[j++] = str[i];
    str[j] = '\0';
}
int main(){
    char str[] = "hello123, world456!";
    printf("%s\n", str);
    remove_digits(str);
    printf("%s", str);
    return 0;
}
